When another module (e.g. vegastrike, texturizer), they should be placed above vega-proj.

For example, when you want to checkout Vega Strike, you may make a Vegastrike directory and from there, checkout vega-prog, vegastrike, data and then maybe texturizer or vssetup ALL from this directory.

Here is a list of every project included for CVS compilation:

*AsterGet (AsterGen.exe)
*mission (Mission Launcher.exe)
*savegame (Launcher.exe)
*texturizer (Texturizer.exe)
**REQUIRES texturizer module
*TriSort (TriSort.exe)
*vsacctserver (accountserver.exe)
*vegastrike (Vegastrike.exe)
*vsserver (vegaserver.exe)
*vssetup (Setup.exe)
**REQUIRES vssetup module

NOTE: Every project requires vegastrike, vega-proj and data (or minimalist) CVS modules.

vegastrike/ - base directory.
vegastrike/vegastrike/ - The stuff from the vegastrike module (the actual code)
vegastrike/vega-proj/ - The project files.
vegastrike/vssetup/ - the vssetup module directory.
vegastrike/texturizer/ - If you want to compile the texturizer.
vegastrike/data/ - The data directory that vega strike needs to run.  You may also use minimalist data instead (see the forums for more information)
NOTE: DATA *MUST* BE CHECKED OUT WITH -kb (BINARY MODE)

mkdir vegastrike
cd vegastrike
cvs -d:pserver:anonymous@cvs.vegastrike.sourceforge.net:/cvsroot/vegastrike login
((type in <enter> for password))
cvs -z3 -d:pserver:anonymous@cvs.vegastrike.sourceforge.net:/cvsroot/vegastrike co vega-proj
cvs -z3 -d:pserver:anonymous@cvs.vegastrike.sourceforge.net:/cvsroot/vegastrike co vegastrike
cvs -z3 -d:pserver:anonymous@cvs.vegastrike.sourceforge.net:/cvsroot/vegastrike co vssetup
cvs -z3 -d:pserver:anonymous@cvs.vegastrike.sourceforge.net:/cvsroot/vegastrike co texturizer
cvs -z3 -d:pserver:anonymous@cvs.vegastrike.sourceforge.net:/cvsroot/vegastrike co data -kb
cvs -d:pserver:anonymous@cvs.vegastrike.sourceforge.net:/cvsroot/vegastrike logout