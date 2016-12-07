#include <string>
#include <vector>
#include <sstream>

class RText
{
private:
//text rendering
    struct cline
    {
        cline()
        {
            outtime = 0;
        }
        cline( const cline &in )
        {
            if (in.cref.size() > 0)
                cref.append( in.cref );
            outtime = in.outtime;
        }
        std::string cref;
        int outtime;
    };
    std::vector< cline >conlines;
    std::vector< std::string >vhistory;
    int ndraw;
    int WORDWRAP;
    int conskip;
    int histpos;
    std::string commandbuf;
public: RText();
    virtual ~RText();
    std::string getcurcommand();
    int text_width( char *str );           //set the text width?
    void draw_text( std::string &str, float left, float top, int gl_num );           //creates textplane object
    void renderconsole();             //renders the text in the console
    void conline( std::string &sf, bool highlight );           //add a line to
//the console
    void conoutf( char* );
    virtual void conoutf( std::string &s, int a = 0, int b = 0, int c = 0 );
//add a line to the console(Use this one.)
    void saycommand( const char *init );           //actually does the appending of
//the string to the commandbuf, and seperates entries
    void ConsoleKeyboardI( int code, bool isdown );
//interpret keyboard input to the console
    void conoutn( std::string &in, int a, int b, int c );
};

