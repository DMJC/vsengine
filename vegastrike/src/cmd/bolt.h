#ifndef _CMD_BOLT_H_
#define _CMD_BOLT_H_
#include "gfxlib.h"
#include "gfxlib_struct.h"
#include "weapon_xml.h"
#include "gfx/matrix.h"
#include "gfx/quaternion.h"
#include "collide_map.h"
class Animation;
class Unit;
class StarSystem;
class bolt_draw ;
class Bolt {
private:
  const weapon_info* type;//beam or bolt;
  Matrix drawmat;
  QVector cur_position;
  Vector ShipSpeed;
  QVector prev_position;//beams don't change heading.
  void *owner;
  float curdist;
  int decal;//which image it uses
 public:
  CollideMap::iterator location;
  static int AddTexture(bolt_draw *q, std::string filename);
  static int AddAnimation(bolt_draw *q, std::string filename, QVector cur_position);
  bool Collide (Unit * target);
  static bool CollideAnon (Collidable::CollideRef bolt_name, Unit* target);
  static Bolt * BoltFromIndex(StarSystem* ss,Collidable::CollideRef bolt_name);
  static Collidable::CollideRef BoltIndex(int index, int decal, bool isBall);
  bool operator == (const Bolt & b) const{
    
    return owner==b.owner
      &&curdist==b.curdist
      &&cur_position==b.cur_position
      &&prev_position==b.prev_position;
  }
  Bolt(const weapon_info *type, const Matrix &orientationpos, const Vector & ShipSpeed, void *owner, CollideMap::iterator hint);//makes a bolt
  void Destroy(unsigned int index);
  static void Draw();
  bool Update(Collidable::CollideRef index);
  bool Collide(Collidable::CollideRef index);
  static void UpdatePhysics(StarSystem *ss);//updates all physics in the starsystem
  void noop()const{}
};
class bolt_draw {
public:
  class DecalQueue *boltdecals;
  static GFXVertexList * boltmesh;
  vector <std::string> animationname;
  vector <Animation *> animations;
  vector <vector <Bolt> > bolts;
  vector <vector <Bolt> > balls;
  vector <int> cachedecals;
  bolt_draw();
  ~bolt_draw();
};

#endif
