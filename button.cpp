#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main(void) {
   Display *d;
   Window w;
   XEvent e;
   char text[512];
   int c=0;
   
   int s;
 
   d = XOpenDisplay(NULL);
   if (d == NULL) {
      fprintf(stderr, "x fail\n");
      exit(1);
   }
 
   s = DefaultScreen(d);
   w = XCreateSimpleWindow(d, RootWindow(d, s), 10, 10, 640, 240, 1,
                           0x1010FF, 0xFF8E00);
   XSelectInput(d, w, ExposureMask | KeyPressMask);
   XMapWindow(d, w);
   
     Atom WM_DELETE_WINDOW = XInternAtom(d, "WM_DELETE_WINDOW", False); 
  XSetWMProtocols(d, w, &WM_DELETE_WINDOW, 1);  

    
 
   while (1) {
      XNextEvent(d, &e);
      if (e.type == Expose) {
				XDrawRectangle(d, w, DefaultGC(d, s),15,30,100,32);
      }
          if (e.type == KeyPress)
    {
	  }
      
	if (e.type == ButtonPress) {
                   XButtonEvent* button_event=&e.xbutton;
		   		if (button_event->x >=5 && button_event->y>=30 && button_event->x<=105 && button_event->y<=62){
					break;                 
		} }
    if ((e.type == ClientMessage) && 
        (static_cast<unsigned int>(e.xclient.data.l[0]) == WM_DELETE_WINDOW))
    {
      break;
    }

      
   }
	XDestroyWindow(d, w); 
   XCloseDisplay(d);
   return 0;
}

