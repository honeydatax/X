#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main(void) {
   Display *d;
   Window w;
   Window w2;
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
   
   w2 = XCreateSimpleWindow(d, RootWindow(d, s), 10, 10, 320, 240, 1,
                           0xFF8E00 ,0x0000F0 );
   XSelectInput(d, w2, ExposureMask | KeyPressMask);
   XMapWindow(d, w2);
   
    
 
   while (1) {
      XNextEvent(d, &e);
      if (e.type == Expose) {
			
      }
      if (e.type == KeyPress)
         break;
   }
 
   XCloseDisplay(d);
   return 0;
}
