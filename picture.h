#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int firsttime=0;
GtkWidget       *button1;
GtkBuilder      *builder; 
GtkWidget       *window2;
GtkWidget       *window;
GtkWidget       *image1000;
GtkWidget       *box1;
GtkFileChooser *file1;
GError			*errors=NULL;
gchar filename[100];
const gchar *filenames;

gchar *cc;
char c[600];
char c1[600];
char cf1[600];
void on_destroy();
void on_select();
void on_click();
void on_acivate();
void on_load();

void on_click(){
		gtk_widget_show (window);
}


void on_acivate(){
}


void on_select(){
	filenames=filename;
	if (firsttime!=0){ 
		gtk_widget_show(window2);
	}
	file1=GTK_FILE_CHOOSER(window);
	cc=gtk_file_chooser_get_filename(file1);
	if (cc!=NULL){
		printf("%s\n",cc);
		on_load();
	}
	firsttime=1;

}




void on_destroy(){
	gtk_main_quit();
}


void on_load(){
		window2 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
		gtk_widget_set_size_request (GTK_WIDGET (window2), 620, 340);
		
		gtk_window_set_title (GTK_WINDOW (window2), cc);
			g_signal_connect (window2, "destroy",
                      G_CALLBACK (on_click), NULL);
		box1 = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 2);
		gtk_container_add (GTK_CONTAINER (window2), box1);
		image1000=gtk_image_new_from_file(cc);
		gtk_container_add (GTK_CONTAINER(box1),image1000);
		gtk_widget_show (box1);
		gtk_widget_show (image1000);
		gtk_widget_show (window2);
		gtk_widget_hide (window);

}








