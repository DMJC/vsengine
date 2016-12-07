#ifndef __UNIT_CSV_H__
#define __UNIT_CSV_H__

CSVRow LookupUnitRow( const std::string &name, const std::string &faction );

extern void AddMeshes( std::vector< Mesh* > &xmeshes,
                       float &randomstartframe,
                       float &randomstartseconds,
                       float unitscale,
                       const std::string &meshes,
                       int faction,
                       Flightgroup *fg,
                       vector< unsigned int > *counts = NULL );

#endif

