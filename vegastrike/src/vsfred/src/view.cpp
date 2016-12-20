#include "../include/view.h"
#include "../include/gui.h"
#include <iostream>
using namespace std;

void view::create_view(int perspective/*, *camera*/)
{
	cout << "creating initial view" << endl;
	switch (perspective){
	case PERSPECTIVE:
		cout << "creating perspective view" << endl;
/*		object->origin[Z] = 20;
		IdentityMatrix(frame->rotate);
		RotateMatrix( -20.0, 20.0, 0.0, frame->rotate);
		InvertMatrix( frame->rotate, view->rotate);*/
	break;
	case TOP:
		cout << "creating top view" << endl;
/*		IdentityMatrix(frame->rotate);
		RotateMatrix( -90, 0, 0, frame->rotate);
		InvertMatrix( frame->rotate, view->rotate);*/
	break;
	case BOTTOM:
		cout << "creating bottom view" << endl;
/*		IdentityMatrix(frame->rotate);
		RotateMatrix( 90, 0, 0, frame->rotate);
		InvertMatrix( frame->rotate, view->rotate);*/
	break;
	case LEFT:
		cout << "creating left view" << endl;
/*		frame->translate[Y] = 2.0;
		IdentityMatrix(frame->rotate);
		RotateMatrix( 0, -90, 0, frame->rotate);
		InvertMatrix( frame->rotate, view->rotate);*/
	break;
	case RIGHT:
		cout << "creating right view" << endl;
/*		frame->translate[Y] = 2.0;
		IdentityMatrix(frame->rotate);
		RotateMatrix( 0, 90, 0, frame->rotate);
		InvertMatrix( frame->rotate, view->rotate);*/
	break;
	case FRONT:
		cout << "creating forward view" << endl;
/*		frame->translate[Y] = 2.0;
		IdentityMatrix(frame->rotate);
		IdentityMatrix(view->rotate);*/
	break;
	case BACK:
		cout << "creating back view" << endl;
/*		frame->translate[Y] = -2.0;
		IdentityMatrix(frame->rotate);
		RotateMatrix( 180, 0, 0, frame->rotate);
		IdentityMatrix(view->rotate);*/
	break;
	case CAMERA:
		cout << "creating camera view" << endl;
	break;
	default:
		cout << "creating perspective view as default option" << endl;
	break;
	}
}

/*view::view()
{
    //ctor
}*/

view::~view()
{
    //dtor
}
