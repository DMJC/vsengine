#ifndef VIEW_H
#define VIEW_H
enum perspective {PERSPECTIVE, TOP, BOTTOM, LEFT, RIGHT, FRONT, BACK, CAMERA};

class view
{
    public:
        void create_view(int perspective);
        virtual ~view();
    protected:
    private:
};
void create_view(int perspective);

#endif // VIEW_H
