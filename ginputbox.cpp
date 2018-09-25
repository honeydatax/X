#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

static void enter_callback( GtkWidget *widget,
                            GtkWidget *entry )
{
}




int main( int   argc,
          char *argv[] )
{

    GtkWidget *window;
    gint tmp_pos;
    GtkWidget *entry;
    GdkColor color;

    gdk_color_parse ("#FF1000", &color);


    gtk_init (&argc, &argv);

    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_widget_set_size_request (GTK_WIDGET (window), 320, 80);
    gtk_window_set_title (GTK_WINDOW (window), "LINUX");
    g_signal_connect (window, "destroy",
		    G_CALLBACK (gtk_main_quit),
		    NULL);

    entry = gtk_entry_new ();
    gtk_entry_set_max_length (GTK_ENTRY (entry), 50);
    g_signal_connect (entry, "activate",G_CALLBACK (enter_callback),entry);
    gtk_entry_set_text (GTK_ENTRY (entry), "LINUX Text sample");
    gtk_widget_show (entry);
    gtk_container_add (GTK_CONTAINER (window), entry);
                  



    
    gtk_widget_show (window);
    gtk_widget_modify_bg ( GTK_WIDGET(window), GTK_STATE_NORMAL, &color);
    gtk_widget_modify_bg ( GTK_WIDGET(entry), GTK_STATE_NORMAL, &color);
    gtk_main();

    return 0;
}





















