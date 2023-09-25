
#include <X11/Xlib.h>

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

// XCreate Window (Advanced)
inline void RH_Window() {}

// XCreate Window (Simple)
inline void RH_Simp_Window(Display *Dsp, int Scr, int Root, int x, int y,
			   int height, int width, const char *BG) {
    int Black = BlackPixel(Dsp, Scr);
    int White = WhitePixel(Dsp, Scr);
    if (strcmp(BG, "black"))
	{
	    Window Win = XCreateSimpleWindow(Dsp, Root, x, y, width, height, 1,
					     Black, White);
	    XMapWindow(Dsp, Win);
    } else
	{
	    Window Win = XCreateSimpleWindow(Dsp, Root, x, y, width, height, 1,
					     White, Black);
	    XMapWindow(Dsp, Win);
	}
}