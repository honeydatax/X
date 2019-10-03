#include <cairo.h>
#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int w=640;
int h=320;

int main(int argc, char *argv[])
{
		cairo_surface_t *surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32,w, h );
        cairo_t *cr = cairo_create (surface);
		cairo_set_source_rgb(cr,1.0,0.8,0.0);
		cairo_set_line_width(cr,1);
        cairo_rectangle(cr,0.0,0.0,640.0,350.0);
        cairo_stroke_preserve(cr);
        cairo_fill(cr);
        cairo_select_font_face(cr,"mono",CAIRO_FONT_SLANT_NORMAL,CAIRO_FONT_WEIGHT_BOLD);
        cairo_set_font_size(cr,24.0);
        cairo_set_source_rgb(cr,1.0,1.0,0.0);
        cairo_move_to(cr,20.00,100.00);
        cairo_show_text(cr,"surface font");
		cairo_destroy (cr);
        cairo_surface_write_to_png (surface, "draw.png");
                
        cairo_surface_destroy (surface);
        return 0;
}
