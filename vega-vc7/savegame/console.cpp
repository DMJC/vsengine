#ifdef _WIN32

#include <windows.h>
#include <wincon.h>


void GetRidOfConsole() {
	FreeConsole ();
}
void my_sleep(int i) {
	Sleep (i);
}
#endif