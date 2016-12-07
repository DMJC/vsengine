Nome: vegastrike-data
Contenuto: Vegastrike - un simulatore spaziale 3d opensource(data files)
Versione: 0.4.1D
Release: 1
Copyright: GPL
Categoria: Amusements/Games
Sorgenti: vegastrike-data.tar.gz
URL: http://vegastrike.sourceforge.net
Creatore pacchetto: Krister Kjelltr√∂m aka Starchild <k00_kjr@k.kth.se>
Cartella di compilazione: %{_tmppath}/data
Prefisso: /usr/local
Provides: vegastrike-data
Necessita di: vegastrike >= 0.4.1




%description
Vega Strike Celeste - Commercia, combatti ed esplora l'universo.

Vega Strike Ë un RPG di simulazione 3d accelerato OpenGL/GPL per Windows/Linux/MacOSX che permette ad un giocatore di commerciare e assaltare vascelli di altri commercianti, nello stile di Elite. Cominci con una nave da carico Llama, con infinite possibilt‡ di fronte a te e giusto i soldi per costruirti una vita. Il pericolo ti aspetta nello spazio di fronte a te..

Questo archivio contiene i file essenziali per giocare.
Contiene anche la versione aggiornata al 25 settembre 2003 del file factions.xml.
 
%prep
rm -rf $RPM_BUILD_ROOT

%setup -n data

%build
echo "Non Ë stato individuato nulla da compilare"

%install
echo "Installazione..."
mkdir -p $RPM_BUILD_ROOT/usr/local/games/vegastrike/data
mkdir -p $RPM_BUILD_ROOT/usr/local/bin/
mkdir -p $RPM_BUILD_ROOT/usr/local/man/man1/
cp vslauncher $RPM_BUILD_ROOT/usr/local/bin/
cp vsinstall $RPM_BUILD_ROOT/usr/local/bin/
cp documentation/vsinstall.1 $RPM_BUILD_ROOT/usr/local/man/man1/
cp documentation/vslauncher.1 $RPM_BUILD_ROOT/usr/local/man/man1/
cp -R . $RPM_BUILD_ROOT/usr/local/games/vegastrike/data
echo "questo pacchetto contiene la versione aggiornata al 25 settembre 2003 del file factions.xml"

%clean
rm -rf $RPM_BUILD_ROOT

%files
%doc /usr/local/man/man1/vslauncher.1
%doc /usr/local/man/man1/vsinstall.1
# Normal files
/usr/local/games/vegastrike/data
%attr(755, root, root) /usr/local/bin/vslauncher
%attr(755, root, root) /usr/local/bin/vsinstall

%changelog

* Sat Jan 03 2004 Daniel Aleksandrow <dandandaman@users.sourceforge.net>
- changed data dir to /usr/local/games/vegastrike/data

* Tue Sep 30 2003 Krister Kjellstr√∂m <k00_kjr@k.kth.se>
- Updated the description and paths, etc for 0.4.1
- Replaced /tmp with {_tmppath}
- Added attr() in front of the binaries in files section,
- don't know if they do any good:)
- Added comments below
- Added echo message after install phase: 'This pakage...
 
################################################################
#
#            Note:
#
# Before building, make sure vsinstall and vslauncher
# is in the appropriet place.
# Also make sure there is no music subdirectory present, unless,
# of course, you intend to include it:)
#
# Should be made with -bb and --target noarch, ie:
# rpmbuild -bb vegastrike-data.spec --target noarch
#
################################################################
