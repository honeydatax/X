#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

GtkWidget       *button1;
GtkBuilder      *builder; 
GtkWidget       *window;
GtkFileChooser *file1;
void on_destroy();
void on_select();

void on_select(){
	char *cc;
	char c[600];
	file1=GTK_FILE_CHOOSER(window);
	cc=gtk_file_chooser_get_filename(file1);
	if (cc!=NULL){
		strcpy(c,"/usr/bin/mousepad ");
		strcat(c,cc);
		strcat(c,"");
		gtk_main_quit();
		system(c);
	}
}




void on_destroy(){
	gtk_main_quit();
}











