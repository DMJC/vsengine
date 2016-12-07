December 15th 2010
VC8 (VC 2005) Is not longer supported. The current solution will NOT compile a working binary. Please update your copy of VC++ to 2008 or 2010.

22-May-03

This README is for the vega-vc8 module.

This is an initial workspace setting, designed to work with Microsoft Visual Studio 2005 Express. Since MSVC 2005 Express comes without any SDK, it may not be a trivial thing to set it up to build this workspace - it won't work out-of-the-box.

To-Do: add instructions or links to the setup procedure.

- Download & Install Microsoft's DirectX SDK
- Assuming the DXSDK is installed in C:\DXSDK, do the following:
	(note - you don't need this if the DXSDK is already properly installed)
	- Add the environment variable DXSDK_ROOT with value C:\DXSDK:
		(In Win2K)
		- Open the control panel
		- Go to "advanced" tab in the "System" applet
		- Select "Environment Variables"
		- Select "New" in "User variables for <username>"
		- Write "DXSDK_ROOT" in "Variable Name"
		- Write "C:\DXSDK" in "Variable Value"
		- OK to all
	- Add the $(DXSDK_ROOT)\Include to global include directories:
		- Go to Tools/Options (in MSVC Express menues)
		- Open "Projects and Solutions"/"VC++ Directories"
		- Select "Include Files" under "Show directories for"
		- Select the last line (an empty line), and press Ctrl+Insert
		- Type "$(DXSDK_ROOT)\Include"
		- Ok to all
	- Add the $(DXSDK_ROOT)\Lib to global include directories:
		- Go to Tools/Options (in MSVC Express menues)
		- Open "Projects and Solutions"/"VC++ Directories"
		- Select "Library Files" under "Show directories for"
		- Select the last line (an empty line), and press Ctrl+Insert
		- Type "$(DXSDK_ROOT)\Lib"
		- Ok to all
	Note: You need to restart MSVC to get it to recognize the new environment variable	

NOTE: Python2.4 requires a patch to work on VC8. Python SVN has that patch
	applied already (a similar one, at least), so posterior versions
	of Python will probably not require such a patch (even... bugfix
	releases of python2.4 could also fix the issue).
	But... if you get an assertion failure talking about signals,
	then you need the patch:

--------------- PYTHON 2.4 PATCH BEGIN -------------

diff -wur old/Python/pythonrun.c new/Python/pythonrun.c
--- old/Python/pythonrun.c	2005-08-24 05:39:46.000000000 -0300
+++ new/Python/pythonrun.c	2006-03-19 02:51:19.000000000 -0300
@@ -1654,7 +1654,20 @@
 	return context.sa_handler;
 #else
 	PyOS_sighandler_t handler;
+
+
+#if ( defined(_MSC_VER) && (_MSC_VER >= 1400) )
+	//Avoid calling signal() with unknown signals - MSVC8 asserts on those.
+	static unsigned long sig_avail = 
+		  (1<<SIGINT) | (1<<SIGILL) | (1<<SIGFPE) | (1<<SIGSEGV) | (1<<SIGTERM)
+		| (1<<SIGBREAK) | (1<<SIGABRT) | (1<<SIGABRT_COMPAT);
+	if ((sig_avail&(1<<sig)) != 0)
+		handler = signal(sig, SIG_IGN); else
+		handler = SIG_ERR;
+#else
 	handler = signal(sig, SIG_IGN);
+#endif
+
 	if (handler != SIG_ERR)
 		signal(sig, handler);
 	return handler;

--------------- PYTHON 2.4 PATCH END -------------

-- Claudio Freire (Klauss)
