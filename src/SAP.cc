
#include "../include/SAP.hh"
#include <cstdio>

int main(int argc, const char *argv[]) {

    DspConf DConf;
    WinConf WConf;
    Window  Win1;

    Display *Dsp1  = XOpenDisplay(NULL);
    int	     Scr1  = DConf.Scr;
    int	     Root1 = RootWindow(Dsp1, Scr1);

    Check(Dsp1, Scr1);

    OWindow(Dsp1, Scr1, Root1, 0, 0, 500, 800, "white");

    Loop(Dsp1, DConf.Xe);
    Close(Dsp1);

    return 0;
}