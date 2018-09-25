#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>




static void
button_clicked (GtkButton *button,
                gpointer   user_data)
{
exit(0);


}



static void
activate (GtkApplication *app,
          gpointer        user_data)
{
  GtkWidget *window;
  GtkWidget *button;
  GdkColor color;

  gdk_color_parse ("#FF1000", &color);




  window = gtk_application_window_new (app);
  gtk_widget_modify_bg ( GTK_WIDGET(window), GTK_STATE_NORMAL, &color);
  gtk_window_set_title (GTK_WINDOW (window), "X");
  gtk_window_set_default_size (GTK_WINDOW (window), 320, 240);


  button = gtk_button_new_with_label ("X");
  gtk_widget_modify_size (GTK_WIDGET(button), 20, 40);
  gtk_widget_modify_bg ( GTK_WIDGET(button), GTK_STATE_NORMAL, &color);
  gtk_container_add (GTK_CONTAINER (window), button);


  g_signal_connect (GTK_BUTTON (button),
                    "clicked", 
                    G_CALLBACK (button_clicked), 
                    G_OBJECT (window));

  gtk_widget_show_all (window);

}



int
main (int argc, char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new (NULL, G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}