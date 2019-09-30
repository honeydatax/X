#include <cairo.h>
#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define circle_width 16
#define circle_height 16
static unsigned char circle_bits[] = {
   0xc0, 0x01, 0xf0, 0x07, 0xfc, 0x1f, 0xfc, 0x1f, 0xfe, 0x3f, 0xfe, 0x3f,
   0xff, 0x7f, 0xff, 0x7f, 0xff, 0x7f, 0xfe, 0x3f, 0xfe, 0x3f, 0xfc, 0x1f,
   0xfc, 0x1f, 0xf0, 0x07, 0xc0, 0x01, 0x00, 0x00};



int main(int argc, char *argv[])
{
unsigned char *circle_b=&circle_bits[0];
int i=cairo_format_stride_for_width(CAIRO_FORMAT_A1,circle_width);   
printf("%d\n",i);
cairo_surface_t *surface = cairo_image_surface_create_for_data (circle_b,CAIRO_FORMAT_A1, circle_width, circle_height,i );
        cairo_t *cr = cairo_create (surface);
        cairo_destroy (cr);

        
        cairo_surface_write_to_png (surface, "circle.png");
        
        cairo_surface_destroy (surface);
        return 0;
}
