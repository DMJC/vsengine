#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

string FileToString( const char *argv )
{
    FILE *fp = fopen( argv, "rb" );
    if (fp) {
        fseek( fp, 0, SEEK_END );
        long   len    = ftell( fp );
        fseek( fp, 0, SEEK_SET );
        char  *finder = new char[len+1];
        finder[len] = 0;
        if(fread( finder, len, 1, fp ) != 1) exit(-1);
        string ret( finder, len );
        fclose( fp );
        //printf ("%s",ret.c_str());
        return ret;
    } else {
        return "";
    }
}
bool findit( const char *argv, string replace )
{
    return FileToString( argv ).find( replace ) != string::npos;
}
void replaceit( const char *argv, string fin, string rep )
{
    string file = FileToString( argv );
    unsigned int curpos = 0;
    FILE  *fp   = fopen( argv, "wb" );
    if (fp) {
        while ( curpos < file.length() ) {
            size_t where = file.find( fin, curpos );
            if (where == string::npos) {
                fwrite( file.data()+curpos, file.length()-curpos, 1, fp );
                break;
            } else {
                where  -= curpos;
                if (where > 0)
                    fwrite( file.data()+curpos, where, 1, fp );
                curpos += where+fin.length();
                fwrite( rep.data(), rep.length(), 1, fp );
            }
        }
        fclose( fp );
    }
}
int main( int argc, char **argv )
{
    if (argc < 3)
        return -1;
    string replace1( argv[1] );
    string replace2( argv[2] );
    for (int i = 3; i < argc; i++)
        if ( findit( argv[i], replace1 ) )
            replaceit( argv[i], replace1, replace2 );
    return 0;
}

