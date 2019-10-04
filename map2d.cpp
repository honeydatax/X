//g++ -o out map2d.cpp  $(pkg-config --cflags --libs cairo x11 pango)
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include <cairo-xlib.h>
#include <cairo.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


const char maps[]={
	"oooooooooooooooo"
	"ol             o"
	"oooooooooooooo o"
	"o            o o"
	"o oooooooooo o o"
	"o o        o o o"
	"o o oooooo o o o"
	"o o o    o o o o"
	"o o o o. o o o o"
	"o o o oooo o o o"
	"o o o      o o o"
	"o o oooooooo o o"
	"o o          o o"
	"o oooooooooooo o"
	"o              o"
	"oooooooooooooooo"
	};

void drawMap(cairo_t *cr,float x,float y,float red,float green, float blue);
void drawbits(cairo_surface_t *crfrom,cairo_t *crinto);
void drawback(cairo_t *cr);
void on_paint(cairo_t *cr);
char getcor(const char *c,float x,float y);
void formap();
cairo_surface_t *surface;
cairo_t *cr1;
cairo_surface_t *ccr;
cairo_t *ccr1;
float x=320.0f;
float xx=20.0f;
 
int main(void) {
   Display *d;
   Window w;
   XEvent e;
   int ww=640;
   int hh=320;
   char text[512]="hello world.!";
   int c=0;
   
   int s;
 
   d = XOpenDisplay(NULL);
   if (d == NULL) {
      fprintf(stderr, "x fail\n");
      exit(1);
   }
 
   s = DefaultScreen(d);
   w = XCreateSimpleWindow(d, RootWindow(d, s), 10, 10, ww, hh, 1,
                           0x0000F0, 0x4040FF);
   XSelectInput(d, w, ExposureMask | KeyPressMask | ButtonPressMask);
   XMapWindow(d, w);
   
   
    Atom WM_DELETE_WINDOW = XInternAtom(d, "WM_DELETE_WINDOW", False); 
	XSetWMProtocols(d, w, &WM_DELETE_WINDOW, 1);  
	surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32,ww, hh );
    cr1 = cairo_create (surface);
    ccr=cairo_xlib_surface_create(d,w,DefaultVisual(d,s),ww,hh);
	cairo_xlib_surface_set_size(ccr,ww,hh);
	ccr1 = cairo_create (ccr);
	on_paint(ccr1);
	
   while (1) {
      XNextEvent(d, &e);
      if (e.type == Expose) {
			
      }
          if (e.type == KeyPress)
    {
      char buf[128] = {0};
      KeySym keysym;
      int len = XLookupString(&e.xkey, buf, sizeof buf, &keysym, NULL);
	  if (keysym == XK_Left) x=x-xx;
 	  if (keysym == XK_Right) x=x+xx;
 	  if (x>640) x=640;
 	  if (x<0) x=0;

	printf("%f\n",x);
		on_paint(ccr1);
	
      if (keysym == XK_Escape)
        break;
    }
 
 
    if ((e.type == ClientMessage) && 
        (static_cast<unsigned int>(e.xclient.data.l[0]) == WM_DELETE_WINDOW))
    {
      break;
    }

      
   }
	cairo_surface_destroy (surface);
	cairo_destroy (cr1);	
	cairo_surface_destroy (ccr);
	cairo_destroy (ccr1);	

	XDestroyWindow(d, w); 
	
   XCloseDisplay(d);
   return 0;
}



void on_paint(cairo_t *cr){
	cairo_push_group(cr);
	drawback(cr1);
	formap();
	drawbits(surface,cr);
	cairo_pop_group_to_source(cr);
    cairo_paint(cr);
	cairo_surface_flush(ccr);	
}

void drawback(cairo_t *cr){
	cairo_set_source_rgb(cr,0.8,0.8,0.8);
	cairo_set_line_width(cr,1);
    cairo_rectangle(cr,0.0,0.0,640.0,350.0);
    cairo_stroke_preserve(cr);
    cairo_fill(cr);
		
}
void drawMap(cairo_t *cr,float x,float y,float red,float green, float blue){
   	cairo_set_source_rgb(cr1,red,green,blue);
	cairo_set_line_width(cr1,1);
    cairo_rectangle(cr1,x*20,y*20,20.0,20.0);
    cairo_stroke_preserve(cr1);
    cairo_fill(cr1);
	
}

void drawbits(cairo_surface_t *crfrom,cairo_t *crinto){
	cairo_set_source_rgb(crinto,1.0,1.0,1.0);
	cairo_set_source_surface(crinto,crfrom,1,1);
	cairo_rectangle(crinto,0.0,0.0,640.0,350.0);
    cairo_stroke_preserve(crinto);
	cairo_fill(crinto);
    cairo_clip(crinto);
}

void formap(){
float x;
float y;
char c;
const char *cc;
		cc=&maps[0];

	for(y=0;y<16.0;y=y+1.0){
		for(x=0;x<16.0;x=x+1.0){
			c=getcor(cc,x,y);
			if(c==' ')drawMap(cr1,x,y,0.0,0.0,1.0);
			if(c=='o')drawMap(cr1,x,y,0.5,0.5,0.5);
			if(c=='.')drawMap(cr1,x,y,0.5,0.5,1.0);
			if(c=='l')drawMap(cr1,x,y,0.5,0.5,1.0);
		}			
	}
}
char getcor(const char *c,float x,float y){
int xx=(int) x;
int yy=(int) y;
yy=yy*16;
xx=xx+yy;
return c[xx];
}
