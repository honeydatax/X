#include <cairo.h>
#include <cairo-pdf.h>
#include <cairo-svg.h>
#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int w=640;
int h=1000;
cairo_t *cr ;

void on_select();

int main(int argc, char *argv[])
{
	
		cairo_surface_t *surface = cairo_svg_surface_create("2020.svg",w, h );
		system("cal 2020 > calc.txt");
		cr = cairo_create (surface);
		cairo_set_source_rgb(cr,1.0,1.0,1.0);
		cairo_set_line_width(cr,1);
        cairo_rectangle(cr,0.0,0.0,640.0,350.0);
        cairo_stroke_preserve(cr);
        cairo_fill(cr);
        cairo_select_font_face(cr,"mono",CAIRO_FONT_SLANT_NORMAL,CAIRO_FONT_WEIGHT_BOLD);
        cairo_set_font_size(cr,12.0);
        cairo_set_source_rgb(cr,0.0,0.0,0.0);
        on_select();
        cairo_surface_destroy (surface);
        cairo_destroy (cr);
        return 0;
}

void on_select(){
	char *dd;
	char cc[]="calc.txt";
	char *file1=&cc[0];
	char d[6800];
	float n=20.0f;
	FILE *f1;
	

	
		f1=fopen(file1,"r");
		dd=&d[0];
		do{
			fgets(dd,599,f1);
			cairo_move_to(cr,20.00,n);
			cairo_show_text(cr,d);
			n=n+14.0;
		}while(!feof(f1));

		fclose(f1);
		
		

	}





