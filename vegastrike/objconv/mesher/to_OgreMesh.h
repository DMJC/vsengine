#ifndef _TO_OGREMESH_H_
#define _TO_OGREMESH_H_

#include "to_BFXM.h"

namespace OgreMeshConverter
{
void ConverterInit();      //Initializes the OgreMesh converter
void ConverterClose();      //Deinitializes the OgreMesh converter
void SetTemplatePath( string path );     //Necessary, most of the time - set the path to template material scripts

void * Init();     //creates an output context, and returns it
void * Init( const char *inputfile, const char *matfile );     //creates an output context, and returns it - preloaded with the contents of inputfile, which must be an OgreMesh
void Add( void *outputcontext, const XML &memfile );     //adds input to the output context
void Dump( void *outputcontext, const char *outputfile, const char *materialfile );     //de-initializes the output context, and dumps its contents into outputfile (if it's not null)
void SetName( void *outputcontext, const char *name );     //sets the name of the mesh - actually, only used to create unique material names
void SetBasePath( void *outputcontext, const char *name );     //sets the name of the mesh - actually, only used to create unique material names
void DoneMeshes( void *outputcontext );     //must call right after Optimize, dumping and stuff, and after adding all meshes.

float RadialSize( void *outputcontext );     //returns the size of the resulting mesh (it's maximum distance from 0,0,0). Useful for LODding.

void Optimize( void *outputcontext );     //a good idea - reorganizes internal buffers so that the output mesh is more efficient
void AutoLOD( void *outputcontext, bool force, int numLod, float reductionFactor, float refDistance );     //autogenerates LOD levels - if force==true, will discard current LOD data
void AutoEdgeList( void *outputcontext );     //a good idea - prepares the mesh for stencil shadows
void AutoTangents( void *outputcontext );     //prepares the mesh for normal mapping (only needed if the material uses normal mapping)
}

#endif

