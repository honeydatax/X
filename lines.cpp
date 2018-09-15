#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main(void) {
   Display *d;
   Window w;
   
   XEvent e;
   GC gc;
   
   int s;
 
   d = XOpenDisplay(NULL);
   if (d == NULL) {
      fprintf(stderr, "x fail\n");
      exit(1);
   }
 
   s = DefaultScreen(d);
   w = XCreateSimpleWindow(d, RootWindow(d, s), 10, 10, 320, 240, 1,
                           0x0000F0, 0xFF8E00);
   XSelectInput(d, w, ExposureMask | KeyPressMask);
   XMapWindow(d, w);
    gc=XCreateGC(d,w,0x0,0);
 
   while (1) {
      XNextEvent(d, &e);
      if (e.type == Expose) {
			XDrawLine(d,w,gc,0,0,320,240);
			XDrawLine(d,w,gc,0,240,320,0);
      }
      if (e.type == KeyPress)
         break;
   }
 
   XCloseDisplay(d);
   return 0;
}
