#include "glade.h"
int main(int argc, char *argv[])
{
	
    gtk_init(&argc, &argv);

    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "form1.glade", NULL);

    window = GTK_WIDGET(gtk_builder_get_object(builder, "form1"));
  
	g_signal_connect_swapped (window , "destroy",
			      G_CALLBACK (on_destroy),
			    window );
			     
	g_signal_connect_swapped (window , "selection-changed",
			      G_CALLBACK (on_select),
			    window ); 
	
   
    g_object_unref(builder);
    gtk_widget_show(window);                
    gtk_main();
    return 0;
}
