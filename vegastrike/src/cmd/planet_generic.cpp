#include "planet_generic.h"
#include "unit_factory.h"
#include "gfx/mesh.h"
#include "galaxy_xml.h"
#include <sys/types.h>
#include <sys/stat.h>
#include "universe_util.h"
#include "lin_time.h"

char * getnoslash( char *inp )
{
    char *tmp = inp;
    for (unsigned int i = 0; inp[i] != '\0'; i++)
        if (inp[i] == '/' || inp[i] == '\\')
            tmp = inp+i+1;
    return tmp;
}

string getCargoUnitName( const char *textname )
{
    char *tmp2 = strdup( textname );
    char *tmp  = getnoslash( tmp2 );
    unsigned int i;
    for (i = 0; tmp[i] != '\0' && (isalpha( tmp[i] ) || tmp[i] == '_'); i++) {}
    if (tmp[i] != '\0')
        tmp[i] = '\0';
    string retval( tmp );
    free( tmp2 );
    return retval;
}

PlanetaryOrbit::PlanetaryOrbit( Unit *p,
                                double velocity,
                                double initpos,
                                const QVector &x_axis,
                                const QVector &y_axis,
                                const QVector &centre,
                                Unit *targetunit ) : Order( MOVEMENT, 0 )
    , velocity( velocity )
    , theta( initpos )
    , inittheta( initpos )
    , x_size( x_axis )
    , y_size( y_axis )
    , current_orbit_frame( 0 )
{
    for (unsigned int t = 0; t < NUM_ORBIT_AVERAGE; ++t)
        orbiting_average[t] = QVector( 0, 0, 0 );
    orbiting_last_simatom = SIMULATION_ATOM;
    orbit_list_filled     = false;
    p->SetResolveForces( false );
    double delta = x_size.Magnitude()-y_size.Magnitude();
    if (delta == 0)
        focus = QVector( 0, 0, 0 );
    else if (delta > 0)
        focus = x_size*( delta/x_size.Magnitude() );
    else
        focus = y_size*( -delta/y_size.Magnitude() );
    if (targetunit) {
        type    = (MOVEMENT);
        subtype = (SSELF);
        AttachSelfOrder( targetunit );
    } else {
        type    = (MOVEMENT);
        subtype = (SLOCATION);
        AttachOrder( centre );
    }
    const double div2pi = ( 1.0/(2.0*PI) );
    if (Network != NULL || SERVER)
        theta = inittheta+velocity * getNewTime()*div2pi;
    this->SetParent( p );
}

PlanetaryOrbit::~PlanetaryOrbit()
{
    parent->SetResolveForces( true );
}

void PlanetaryOrbit::Execute()
{
    bool mining = parent->rSize() > 1444 && parent->rSize() < 1445;
    bool done   = this->done;
    this->Order::Execute();
    this->done = done;     //we ain't done till the cows come home
    if (done)
        return;
    QVector origin( targetlocation );
    static float orbit_centroid_averaging = XMLSupport::parse_float( vs_config->getVariable( "physics", "orbit_averaging", "16" ) );
    float   averaging = (float) orbit_centroid_averaging/(float) (parent->predicted_priority+1.0f);
    if (averaging < 1.0f) averaging = 1.0f;
    if (subtype&SSELF) {
        Unit *unit = group.GetUnit();
        if (unit) {
            unsigned int o = current_orbit_frame++;
            current_orbit_frame %= NUM_ORBIT_AVERAGE;
            if (current_orbit_frame == 0)
                orbit_list_filled = true;
            QVector desired = unit->prev_physical_state.position;
            if (orbiting_average[o].i == 0 && orbiting_average[o].j == 0 && orbiting_average[o].k == 0) {
                //clear all of them.
                for (o = 0; o < NUM_ORBIT_AVERAGE; o++)
                    orbiting_average[o] = desired;
                orbiting_last_simatom = SIMULATION_ATOM;
                current_orbit_frame   = 2;
                orbit_list_filled     = false;
            } else {
                if (SIMULATION_ATOM != orbiting_last_simatom) {
                    QVector sum_diff( 0, 0, 0 );
                    QVector sum_position;
                    int     limit;
                    if (orbit_list_filled) {
                        sum_position = orbiting_average[o];
                        limit = NUM_ORBIT_AVERAGE-1;
                        o = (o+1)%NUM_ORBIT_AVERAGE;
                    } else {
                        sum_position = orbiting_average[0];
                        limit = o;
                        o = 1;
                    }
                    for (int i = 0; i < limit; i++) {
                        sum_diff     += (orbiting_average[o]-orbiting_average[(o+NUM_ORBIT_AVERAGE-1)%NUM_ORBIT_AVERAGE]);
                        sum_position += orbiting_average[o];
                        o = (o+1)%NUM_ORBIT_AVERAGE;
                    }
                    if (limit != 0)
                        sum_diff *= ( 1./(limit) );
                    sum_position  *= ( 1./(limit+1) );

                    float ratio_simatom = (SIMULATION_ATOM/orbiting_last_simatom);
                    sum_diff      *= ratio_simatom;
                    unsigned int number_to_fill;
                    number_to_fill = (int) ( (NUM_ORBIT_AVERAGE/ratio_simatom)+.99 );
                    if (number_to_fill > NUM_ORBIT_AVERAGE) number_to_fill = NUM_ORBIT_AVERAGE;
                    if (ratio_simatom <= 1)
                        number_to_fill = NUM_ORBIT_AVERAGE;
                    //subtract it so the average remains the same.
                    sum_position += ( sum_diff*(number_to_fill/ -2.) );
                    for (o = 0; o < number_to_fill; o++) {
                        orbiting_average[o] = sum_position;
                        sum_position += sum_diff;
                    }
                    orbit_list_filled     = (o >= NUM_ORBIT_AVERAGE-1);
                    o %= NUM_ORBIT_AVERAGE;
                    current_orbit_frame   = (o+1)%NUM_ORBIT_AVERAGE;
                    orbiting_last_simatom = SIMULATION_ATOM;
                }
                orbiting_average[o] = desired;
            }
        } else {
            done = true;
            parent->SetResolveForces( true );
            return;             //flung off into space.
        }
    }
    QVector sum_orbiting_average( 0, 0, 0 );
    {
        int limit;
        if (orbit_list_filled)
            limit = NUM_ORBIT_AVERAGE;
        else
            limit = current_orbit_frame;
        for (int o = 0; o < limit; o++)
            sum_orbiting_average += orbiting_average[o];
        sum_orbiting_average *= 1./(limit == 0 ? 1 : limit);
    }
    const double div2pi = ( 1.0/(2.0*PI) );
    theta += velocity*SIMULATION_ATOM*div2pi;
    if (Network != NULL || SERVER) {
        float truetheta = inittheta+velocity * getNewTime()*div2pi;
        theta = theta*( (averaging-1.0f)/averaging )+truetheta*(1.0f/averaging);
    }
    QVector x_offset    = cos( theta )*x_size;
    QVector y_offset    = sin( theta )*y_size;

    QVector destination = origin-focus+sum_orbiting_average+x_offset+y_offset;
    double  mag = ( destination-parent->LocalPosition() ).Magnitude();
    if (mining && 0) {
        printf( "(%.2f %.2f %.2f)\n(%.2f %.2f %.2f) del %.2f spd %.2f\n",
                parent->LocalPosition().i,
                parent->LocalPosition().j,
                parent->LocalPosition().k,
                destination.i,
                destination.j,
                destination.k,
                mag,
                mag*(1./SIMULATION_ATOM)
              );
    }
    parent->Velocity = parent->cumulative_velocity = ( ( ( destination-parent->LocalPosition() )*(1./SIMULATION_ATOM) ).Cast() );
    static float Unreasonable_value =
        XMLSupport::parse_float( vs_config->getVariable( "physics", "planet_ejection_stophack", "2000" ) );
    float v2 = parent->Velocity.Dot( parent->Velocity );
    if (v2 > Unreasonable_value*Unreasonable_value ) {
        parent->Velocity.Set( 0, 0, 0 );
        parent->cumulative_velocity.Set( 0, 0, 0 );
        parent->SetCurPosition( origin-focus+sum_orbiting_average+x_offset+y_offset );
    }
}

string GetElMeshName( string name, string faction, char direction )
{
    using namespace VSFileSystem;
    char    strdir[2]     = {direction, 0};
    string  elxmesh       = string( strdir )+"_elevator.bfxm";
    string  elevator_mesh = name+"_"+faction+elxmesh;
    VSFile  f;
    VSError err = f.OpenReadOnly( elevator_mesh, MeshFile );
    if (err > Ok)
        f.Close();
    else elevator_mesh = name+elxmesh;
    return elevator_mesh;
}

Vector Planet::AddSpaceElevator( const std::string &name, const std::string &faction, char direction )
{
    Vector dir, scale;
    switch (direction)
    {
    case 'u':
        dir.Set( 0, 1, 0 );
        break;
    case 'd':
        dir.Set( 0, -1, 0 );
        break;
    case 'l':
        dir.Set( -1, 0, 0 );
        break;
    case 'r':
        dir.Set( 1, 0, 0 );
        break;
    case 'b':
        dir.Set( 0, 0, -1 );
        break;
    default:
        dir.Set( 0, 0, 1 );
        break;
    }
    Matrix ElevatorLoc( Vector( dir.j, dir.k, dir.i ), dir, Vector( dir.k, dir.i, dir.j ) );
    scale = dir*radius+Vector( 1, 1, 1 )-dir;
    Mesh  *shield = meshdata.back();
    string elevator_mesh = GetElMeshName( name, faction, direction );     //filename
    Mesh  *tmp    = meshdata.back() = Mesh::LoadMesh( elevator_mesh.c_str(),
                                                      scale,
                                                      FactionUtil::
                                                      GetFactionIndex( faction ),
                                                      NULL );

    meshdata.push_back( shield );
    {
        //subunit computations
        Vector mn( tmp->corner_min() );
        Vector mx( tmp->corner_max() );
        if (dir.Dot( Vector( 1, 1, 1 ) ) > 0)
            ElevatorLoc.p.Set( dir.i*mx.i, dir.j*mx.j, dir.k*mx.k );
        else
            ElevatorLoc.p.Set( -dir.i*mn.i, -dir.j*mn.j, -dir.k*mn.k );
        Unit *un = UnitFactory::createUnit( name.c_str(), true, FactionUtil::GetFactionIndex( faction ), "", NULL );
        if (pImage->dockingports.back().GetPosition().MagnitudeSquared() < 10)
            pImage->dockingports.clear();
        pImage->dockingports.push_back( DockingPorts( ElevatorLoc.p, un->rSize()*1.5, 0, DockingPorts::Type::INSIDE ) );
        un->SetRecursiveOwner( this );
        un->SetOrientation( ElevatorLoc.getQ(), ElevatorLoc.getR() );
        un->SetPosition( ElevatorLoc.p );
        SubUnits.prepend( un );
    }
    return dir;
}

void Planet::endElement() {}

Planet* Planet::GetTopPlanet( int level )
{
    if (level > 2) {
        un_iter satiterator = satellites.createIterator();
        assert( *satiterator );
        if ( (*satiterator)->isUnit() == PLANETPTR ) {
            return ( (Planet*) (*satiterator) )->GetTopPlanet( level-1 );
        } else {
            VSFileSystem::vs_fprintf( stderr, "Planets are unable to orbit around units" );
            return NULL;
        }
    } else {
        return this;
    }
}

void Planet::AddSatellite( Unit *orbiter )
{
    satellites.prepend( orbiter );
    orbiter->SetOwner( this );
}

extern float ScaleJumpRadius( float );
extern Flightgroup * getStaticBaseFlightgroup( int faction );

Unit* Planet::beginElement( QVector x,
                            QVector y,
                            float vely,
                            const Vector &rotvel,
                            float pos,
                            float gravity,
                            float radius,
                            const string &filename,
                            const string &technique,
                            const string &unitname,
                            BLENDFUNC blendSrc,
                            BLENDFUNC blendDst,
                            const vector< string > &dest,
                            int level,
                            const GFXMaterial &ourmat,
                            const vector< GFXLightLocal > &ligh,
                            bool isunit,
                            int faction,
                            string fullname,
                            bool inside_out )
{
    //this function is OBSOLETE
    Unit *un = NULL;
    if (level > 2) {
        un_iter satiterator = satellites.createIterator();
        assert( *satiterator );
        if ( (*satiterator)->isUnit() == PLANETPTR ) {
            un = ( (Planet*) (*satiterator) )->beginElement( x, y, vely, rotvel, pos,
                                                             gravity, radius,
                                                             filename, technique, unitname,
                                                             blendSrc, blendDst,
                                                             dest,
                                                             level-1,
                                                             ourmat, ligh,
                                                             isunit,
                                                             faction, fullname,
                                                             inside_out );
        } else {
            VSFileSystem::vs_fprintf( stderr, "Planets are unable to orbit around units" );
        }
    } else {
        if (isunit == true) {
            Unit *sat_unit  = NULL;
            Flightgroup *fg = getStaticBaseFlightgroup( faction );
            satellites.prepend( sat_unit = UnitFactory::createUnit( filename.c_str(), false, faction, "", fg, fg->nr_ships-1 ) );
            sat_unit->setFullname( fullname );
            un = sat_unit;
            un_iter satiterator( satellites.createIterator() );
            (*satiterator)->SetAI( new PlanetaryOrbit( *satiterator, vely, pos, x, y, QVector( 0, 0, 0 ), this ) );
            (*satiterator)->SetOwner( this );
        } else {
            Planet *p;
            if (dest.size() != 0)
                radius = ScaleJumpRadius( radius );
            satellites.prepend( p = UnitFactory::createPlanet( x, y, vely, rotvel, pos, gravity, radius, 
                                                               filename, technique, unitname, 
                                                               blendSrc, blendDst, dest,
                                                               QVector( 0, 0, 0 ), this, ourmat, ligh, faction, fullname, inside_out ) );
            un = p;
            p->SetOwner( this );
        }
    }
    return un;
}

Planet::Planet() :
    Unit( 0 )
    , radius( 0.0f )
    , satellites()
{
    inside = false;
    //Not needed as Unit default constructor is called and already does Init
    //Init();
    terraintrans = NULL;
    atmospheric  = false;
    //Force shields to 0
    memset( &(this->shield), 0, sizeof (Unit::shield) );
    this->shield.number = 2;
}

void Planet::InitPlanet( QVector x,
                         QVector y,
                         float vely,
                         const Vector &rotvel,
                         float pos,
                         float gravity,
                         float radius,
                         const string &filename,
                         const string &technique,
                         const string &unitname,
                         const vector< string > &dest,
                         const QVector &orbitcent,
                         Unit *parent,
                         int faction,
                         string fullname,
                         bool inside_out,
                         unsigned int lights_num )
{
    atmosphere = NULL;
    terrain    = NULL;
    static float bodyradius = XMLSupport::parse_float( vs_config->getVariable( "graphics", "star_body_radius", ".33" ) );
    if (lights_num)
        radius *= bodyradius;
    inside = false;
    curr_physical_state.position = prev_physical_state.position = cumulative_transformation.position = orbitcent+x;
    Init();
    //static int neutralfaction=FactionUtil::GetFaction("neutral");
    //this->faction = neutralfaction;
    killed = false;
    bool notJumppoint = dest.empty();
    for (unsigned int i = 0; i < dest.size(); ++i)
        AddDestination( dest[i] );
    //name = "Planet - ";
    //name += textname;
    name = fullname;
    this->fullname = name;
    this->radius   = radius;
    this->gravity  = gravity;
    static float densityOfRock = XMLSupport::parse_float( vs_config->getVariable( "physics", "density_of_rock", "3" ) );
    static float densityOfJumpPoint =
        XMLSupport::parse_float( vs_config->getVariable( "physics", "density_of_jump_point", "100000" ) );
    //static  float massofplanet = XMLSupport::parse_float(vs_config->getVariable("physics","mass_of_planet","10000000"));
    hull = (4./3)*M_PI*radius*radius*radius*(notJumppoint ? densityOfRock : densityOfJumpPoint);
    this->Mass   = (4./3)*M_PI*radius*radius*radius*( notJumppoint ? densityOfRock : (densityOfJumpPoint/100000) );
    SetAI( new PlanetaryOrbit( this, vely, pos, x, y, orbitcent, parent ) );     //behavior
    terraintrans = NULL;

    colTrees     = NULL;
    SetAngularVelocity( rotvel );
    // The docking port is 20% bigger than the planet
    static float planetdockportsize    = XMLSupport::parse_float( vs_config->getVariable( "physics", "planet_port_size", "1.2" ) );
    static float planetdockportminsize =
        XMLSupport::parse_float( vs_config->getVariable( "physics", "planet_port_min_size", "300" ) );
    if ( (!atmospheric) && notJumppoint ) {
        float dock = radius*planetdockportsize;
        if (dock-radius < planetdockportminsize)
            dock = radius+planetdockportminsize;
        pImage->dockingports.push_back( DockingPorts( Vector( 0, 0, 0 ), dock, 0, DockingPorts::Type::CONNECTED_OUTSIDE ) );
    }
    string tempname = unitname.empty() ? ::getCargoUnitName( filename.c_str() ) : unitname;
    setFullname( tempname );

    int    tmpfac   = faction;
    if (UniverseUtil::LookupUnitStat( tempname, FactionUtil::GetFactionName( faction ), "Cargo_Import" ).length() == 0)
        tmpfac = FactionUtil::GetPlanetFaction();
    Unit  *un = UnitFactory::createUnit( tempname.c_str(), true, tmpfac );

    static bool smartplanets = XMLSupport::parse_bool( vs_config->getVariable( "physics", "planets_can_have_subunits", "false" ) );
    if ( un->name != string( "LOAD_FAILED" ) ) {
        pImage->cargo = un->GetImageInformation().cargo;
        pImage->CargoVolume   = un->GetImageInformation().CargoVolume;
        pImage->UpgradeVolume = un->GetImageInformation().UpgradeVolume;
        VSSprite *tmp = pImage->pHudImage;
        pImage->pHudImage     = un->GetImageInformation().pHudImage;
        un->GetImageInformation().pHudImage = tmp;
        maxwarpenergy = un->WarpCapData();
        if (smartplanets) {
            SubUnits.prepend( un );
            un->SetRecursiveOwner( this );
            this->SetTurretAI();
            un->SetTurretAI();              //allows adding planetary defenses, also allows launching fighters from planets, interestingly
            un->name = "Defense_grid";
        }
        static bool neutralplanets =
            XMLSupport::parse_bool( vs_config->getVariable( "physics", "planets_always_neutral", "true" ) );
        if (neutralplanets) {
            static int neutralfaction = FactionUtil::GetNeutralFaction();
            this->faction = neutralfaction;
        } else {
            this->faction = faction;
        }
    }
    if ( un->name == string( "LOAD_FAILED" ) || (!smartplanets) )
        un->Kill();
}

Planet::Planet( QVector x,
                QVector y,
                float vely,
                const Vector &rotvel,
                float pos,
                float gravity,
                float radius,
                const string &filename,
                const string &technique,
                const string &unitname,
                const vector< string > &dest,
                const QVector &orbitcent,
                Unit *parent,
                int faction,
                string fullname,
                bool inside_out,
                unsigned int lights_num )
{
    inside = false;
    terraintrans = NULL;
    atmospheric  = false;
    this->InitPlanet( x, y, vely, rotvel,
                      pos,
                      gravity, radius,
                      filename, technique, unitname,
                      dest,
                      orbitcent, parent,
                      faction, fullname,
                      inside_out,
                      lights_num );
    corner_min.i = corner_min.j = corner_min.k = -this->radius;
    corner_max.i = corner_max.j = corner_max.k = this->radius;
    this->radial_size = this->radius;
    for (unsigned int i = 0; i < lights_num; i++) {
        int l = -1;
        lights.push_back( l );
    }
    //Force shields to 0
    /*
     *  this->shield.number=2;
     *  this->shield.recharge=0;
     *  this->shield.shield2fb.frontmax=0;
     *  this->shield.shield2fb.backmax=0;
     *  this->shield.shield2fb.front=0;
     *  this->shield.shield2fb.back=0;
     */
    memset( &(this->shield), 0, sizeof (Unit::shield) );
    this->shield.number = 2;
    if ( meshdata.empty() ) meshdata.push_back( NULL );
}

string Planet::getHumanReadablePlanetType() const
{
    //static std::map<std::string, std::string> planetTypes (readPlanetTypes("planet_types.xml"));
    //return planetTypes[getCargoUnitName()];
    return _Universe->getGalaxy()->getPlanetNameFromTexture( getCargoUnitName() );
}

Planet::~Planet()
{
    if (terraintrans) {
        Matrix *tmp = new Matrix();
        *tmp = cumulative_transformation_matrix;
        //terraintrans->SetTransformation (tmp);
    }
}

void Planet::Kill( bool erasefromsave )
{
    un_iter iter;
    Unit   *tmp;
    for (iter = satellites.createIterator();
         (tmp = *iter);
         ++iter)
        tmp->SetAI( new Order );
    /* probably not FIXME...right now doesn't work on paged out systems... not a big deal */
    satellites.clear();
    insiders.clear();
    Unit::Kill( erasefromsave );
}

