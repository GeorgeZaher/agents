#include <time.h>
#include <stdio.h>
#include <assert.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

int main(int argc, char** argv)
{
    time_t current_time;
    XImage* image;
    Display* display;
    Window window;

    display = XOpenDisplay(NULL);
    assert(display);

    window = XRootWindow(display, DefaultScreen(display));
    image = XGetImage(display, window, 10, 10, 201, 201, AllPlanes , ZPixmap);

    time(&current_time);
    char filename[80] = "screenshot";
    (void) sprintf(filename, current_time);
    FILE* imagefile = fopen(filename, "wb");

    XDestroyImage(image);
    XDestroyWindow(display, root);
    XCloseDisplay(display);
    return 0;
}
