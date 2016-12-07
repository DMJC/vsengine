December 15th 2010
VC7 (VC 2003) Is not longer supported. The current solution will NOT compile a working binary. Please update your copy of VC++ to 2008 or 2010.

22-May-03

This README is for the vega-vc7 module.  It is here to support Microsoft VC++ .NET 2003 builds (MSVC 7.1).

As of this writing, only the vegastrike module can be built.  The other modules have very old workspace descriptions in them.  They are there as placeholders -- hopefully someday we'll support them, too.

When you want to checkout Vega Strike, make a Vegastrike directory and from there, checkout the "vega-vc7", "vegastrike" and "data" modules ALL from the vegastrike directory.

vegastrike/ - base directory.
vegastrike/vegastrike/ - The stuff from the vegastrike module (the actual code)
vegastrike/vega-proj/ - The project files.
vegastrike/data/ - The project execution directory.  DLL's, runtime data, etc.

NOTE: DATA *MUST* BE CHECKED OUT WITH -kb (BINARY MODE)
Technically you can put the data directory anywhere you want, but you'll need to change the vegastrike workspace path setting a bit if you do.

Also, the data project doesn't contain the music, because the music is so big.  You can either copy the music from the VegaStrike release (if you have one), or get the "music" module.  VegaStrike will work fine without the music files, you just don't have quite the "ambience" ;-) when you test.

-- Mike Byron

March 18, 2010

File vegastrike.cbp added to this folder. It is a Code::Blocks Project file, contributed by shenle.
http://vegastrike.sourceforge.net/forums/viewtopic.php?p=116520#p116520
 r12737

-- chuck_starchaser

March 20, 2010

File mesher.cbp added to this folder. It is a Code::Blocks Project file, also contributed by shenle.
 r12746

-- chuck_starchaser


