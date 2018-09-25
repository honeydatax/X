#include <gtk/gtk.h>

int main( int   argc,
          char *argv[] )
{
  static GtkWidget *window = NULL;
  GtkWidget *label;
  GdkColor color;

  gdk_color_parse ("#FF0000", &color);


 
  gtk_init (&argc, &argv);

  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  g_signal_connect (window, "destroy",
		    G_CALLBACK (gtk_main_quit),
		    NULL);

  gtk_window_set_title (GTK_WINDOW (window), "linux");
  label = gtk_label_new ("Linux sample gnome gtk LINUX SAMPLE");
  gtk_container_add (GTK_CONTAINER (window), label);
  
  
  gtk_widget_show_all (window);
  gtk_widget_modify_bg ( GTK_WIDGET(window), GTK_STATE_NORMAL, &color);
  gtk_widget_modify_bg ( GTK_WIDGET(label), GTK_STATE_NORMAL, &color);
  gtk_main ();
  
  return 0;
}













