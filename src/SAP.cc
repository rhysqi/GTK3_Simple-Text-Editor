
#include "../include/SAP.hh"
#include "X11/Xlib.h"

int main(int argc, const char *argv[]) {

    Display *Dsp1;
    int Scr1 = DefaultRootWindow(Dsp1);
    XEvent Xe;

    Check(Dsp1, Scr1);

    Loop(Dsp1, Xe);

    return 0;
}