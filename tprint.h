#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


const char *printer="lp";
//const char *printer="/dev/lp";
int firsttime=0;
GtkWidget       *button1;
GtkBuilder      *builder; 
GtkWidget       *window2;
GtkWidget       *window;
GtkWidget       *print1;
GtkFileChooser *file1;
void on_destroy();
void on_select();
void on_click();
void on_acivate();

void on_click(){
	gtk_widget_hide(window2);                
}


void on_acivate(){
	//gtk_widget_hide(button1);                
}


void on_select(){
	char *cc;
	char c[600];
	
	if (firsttime!=0){ 
		gtk_widget_show(window2);
	}
	file1=GTK_FILE_CHOOSER(window);
	cc=gtk_file_chooser_get_filename(file1);
	if (cc!=NULL){
		strcpy(c,cc);
		strcat(c,"");
	gtk_widget_show(print1);

	}
	if (firsttime!=0) gtk_widget_show(button1);                
	firsttime=1;

}




void on_destroy(){
	gtk_main_quit();
}











