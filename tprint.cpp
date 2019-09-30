#include "tprint.h"
int main(int argc, char *argv[])
{
	
    gtk_init(&argc, &argv);

    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "tprint.glade", NULL);

    window = GTK_WIDGET(gtk_builder_get_object(builder, "form1"));
    window2 = GTK_WIDGET(gtk_builder_get_object(builder, "form2"));
    button1 = GTK_WIDGET(gtk_builder_get_object(builder, "button3"));
    print1 = GTK_WIDGET(gtk_builder_get_object(builder, "print1"));
  
	g_signal_connect_swapped (window , "destroy",
			      G_CALLBACK (on_destroy),
			    window );
			     
	g_signal_connect_swapped (window , "selection-changed",
			      G_CALLBACK (on_select),
			    window ); 

	g_signal_connect_swapped (button1 , "pressed",
			      G_CALLBACK (on_click),
			    window ); 

	g_signal_connect_swapped (window2 , "response",
			      G_CALLBACK (on_acivate),
			    window );
	
   
    g_object_unref(builder);
	gtk_widget_show(window);                
    gtk_main();
    return 0;
}
