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
   XSelectInput(d, w, ExposureMask | KeyPressMask | ButtonPressMask);
   XMapWindow(d, w);
   
     Atom WM_DELETE_WINDOW = XInternAtom(d, "WM_DELETE_WINDOW", False); 
  XSetWMProtocols(d, w, &WM_DELETE_WINDOW, 1);  

    
 
   while (1) {
      XNextEvent(d, &e);
      if (e.type == Expose) {
		XColor xcolour;
Colormap cmap=XDefaultColormap(d,s);
 char fontname[100];
 XFontStruct *font ;
for (int x=0;x<8;x++){
xcolour.red = 32000+(x*2048); xcolour.green = 16000+(x*2048); xcolour.blue = (0);
xcolour.flags = DoRed | DoGreen | DoBlue;


XAllocColor(d, cmap, &xcolour);

XSetForeground(d, DefaultGC(d,s), xcolour.pixel);
    if (x==0)strcpy(fontname,"-*-helvetica-*-r-*-*-04-*-*-*-*-*-*-*");
    if (x==1)strcpy(fontname,"-*-helvetica-*-r-*-*-05-*-*-*-*-*-*-*");
    if (x==2)strcpy(fontname,"-*-helvetica-*-r-*-*-08-*-*-*-*-*-*-*");
    if (x==3)strcpy(fontname,"-*-helvetica-*-r-*-*-10-*-*-*-*-*-*-*");
    if (x==4)strcpy(fontname,"-*-helvetica-*-r-*-*-12-*-*-*-*-*-*-*");
    if (x==5)strcpy(fontname,"-*-helvetica-*-r-*-*-14-*-*-*-*-*-*-*");
    if (x==6)strcpy(fontname,"-*-helvetica-*-r-*-*-15-*-*-*-*-*-*-*");
    if (x==7)strcpy(fontname,"-*-helvetica-*-r-*-*-24-*-*-*-*-*-*-*");
    font = XLoadQueryFont (d, fontname);
    XSetFont (d,DefaultGC(d,s), font->fid);
    XDrawString (d, w, DefaultGC(d,s),20, 10+(x*x*3), "im love marina", strlen("im love marina"));
XFlush(d);
      }}
          if (e.type == KeyPress)
    {
	  }
      
	
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

