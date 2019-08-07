#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>


static void
activate (GtkApplication *app,
          gpointer        user_data)
{
  GtkWidget *window1;
  GtkWidget *window2;
  GtkWidget *window3;



  window1 = gtk_application_window_new (app);
  window2 = gtk_application_window_new (app);
  window3 = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window1), "-windows 1");
  gtk_window_set_title (GTK_WINDOW (window2), "-windows 2");
  gtk_window_set_title (GTK_WINDOW (window3), "-windows 3");
   gtk_window_move (GTK_WINDOW (window1),10,10);
   gtk_window_move (GTK_WINDOW (window2),50,50);
   gtk_window_move (GTK_WINDOW (window3),100,100);
gtk_widget_set_size_request(GTK_WIDGET(window1),100,100);
gtk_widget_set_size_request(GTK_WIDGET(window2),150,150);
gtk_widget_set_size_request(GTK_WIDGET(window3),200,200);
gtk_widget_show_all (window1);
  gtk_widget_show_all (window2);
  gtk_widget_show_all (window3);




}

int
main (int argc, char **argv)
{
  GtkApplication *app;
  int status;
//g++ windows.c `pkg-config --cflags --libs gtk+-3.0` -o window.o
  app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);
    printf("exiting application\n");
  return status;
}
