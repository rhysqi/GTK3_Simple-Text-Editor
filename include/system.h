
#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>

inline void Loop(Display *Dsp, int Scr) {
    Dsp = XOpenDisplay(NULL);
    Scr = DefaultScreen(Dsp);

    if (Dsp == NULL)
	{
	    printf("No display detected !\n");
	    exit(1);
    }
}

inline void EndLoop(Display *Dsp) { XCloseDisplay(Dsp); }

inline void WMapping(Display *Dsp, Window Win) { XMapWindow(Dsp, Win); }

inline void UnMapping(Display *Dsp, Window Win) { XUnmapWindow(Dsp, Win); }

inline void DestroyWin(Display *Dsp, Window Win) { XDestroyWindow(Dsp, Win); }