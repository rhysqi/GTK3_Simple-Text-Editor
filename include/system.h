
#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>

inline void Check(Display *Dsp, int Scr) {
    Dsp = XOpenDisplay(NULL);
    Scr = DefaultScreen(Dsp);

	if (Dsp == NULL) {
	    printf("No display detected !\n");
	    exit(1);
    }
}

inline void Loop(Display *Dsp, XEvent Xe) {
	while (true) {
	    XNextEvent(Dsp, &Xe);
        if (Xe.type == ButtonPress) {
            printf("Tombol diklik!\n");
            break;
        }
    }
}