#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <cairo.h>
#include <x11/xlib.h>


gboolean on_clock(gpointer data);
void on_exits1();
void on_paint(cairo_t *cr);
gboolean on_draws1(GtkWidget *widget,cairo_t *cr,gpointer user_data);
cairo_surface_t *surface;
cairo_t *cr1;
int errorss;
int first_time=0;
Drawable window;
GtkWidget *draws;
Display *widgets;
GtkStyleContext *context;
int w=640;
int h=320;
gint exitcode=0;
guint gu1=100;
float x=30.0f;
float y=30.0f;
float addx=5.0f;
float addy=5.0f;



gboolean on_clock(gpointer data){
	
	if(first_time==1) {
		x=(rand()&32767)/53;
		y=(rand()&32767)/103;
		cairo_set_source_rgb(cr1,1.0,1.0,0.0);
		cairo_set_line_width(cr1,1);
		cairo_rectangle(cr1,x,y,10.0f,10.0f);
		cairo_stroke_preserve(cr1);
		cairo_fill(cr1);

		gtk_widget_queue_draw_area(draws,0,0,620,320);
	}
 return TRUE;
}

gboolean on_draws1(GtkWidget *widget,cairo_t *cr,gpointer user_data){
	on_paint(cr);
	first_time=1;
	return FALSE;
}

int main( int   argc,char *argv[] )
{
    gtk_init (&argc, &argv);
        
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_widget_set_size_request (GTK_WIDGET (window), 620, 320);
    gtk_window_set_title (GTK_WINDOW (window), "rectangle");
    g_signal_connect (window, "destroy",
                      G_CALLBACK (on_exits1), NULL);
    
    
   
    
    draws = gtk_drawing_area_new ();
	gtk_container_add (GTK_CONTAINER(window), draws);
    gtk_widget_show (draws);
    gtk_widget_set_size_request (GTK_WIDGET (window), 620, 320);
    gtk_widget_show_all(window);

    g_signal_connect (G_OBJECT(draws), "draw",
                     G_CALLBACK (on_draws1), NULL);
                      
	
    exitcode=g_timeout_add(gu1,on_clock,NULL);
	surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32,w, h );
    cr1 = cairo_create (surface);
	cairo_set_source_rgb(cr1,1.0,0.8,0.0);
	cairo_set_line_width(cr1,1);
    cairo_rectangle(cr1,0.0,0.0,640.0,350.0);
    cairo_stroke_preserve(cr1);
    cairo_fill(cr1);
	
	gtk_main();

    g_source_remove(exitcode);

    return 0;
}

void on_exits1(){
	cairo_surface_destroy (surface);
	cairo_destroy (cr1);	
	gtk_main_quit();
}

void on_paint(cairo_t *cr){
	cairo_set_source_rgb(cr,1.0,0.8,1.0);
	cairo_set_source_surface(cr,surface,1,1);
    cairo_rectangle(cr,0.0,0.0,640.0,350.0);
    cairo_stroke_preserve(cr);
	cairo_fill(cr);
    cairo_clip(cr);
    cairo_paint(cr);
    
    
}


