
#include <X11/Xlib.h>

#include <string.h>

inline void createButton(Display *display, Window parent, int x, int y, int width, int height, const char *label) {
    Window button = XCreateSimpleWindow(display, parent, x, y, width, height, 1, BlackPixel(display, 0), WhitePixel(display, 0));

    XSelectInput(display, button, ButtonPressMask | ExposureMask);
    XMapWindow(display, button);

    XFontStruct *font = XLoadQueryFont(display, "fixed");
    XGCValues values;
    values.font = font->fid;
    GC gc = XCreateGC(display, button, GCFont, &values);

    XDrawString(display, button, gc, 10, 20, label, strlen(label));
}