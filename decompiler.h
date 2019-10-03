#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>



int firsttime=0;
GtkWidget       *button1;
GtkBuilder      *builder; 
GtkWidget       *window2;
GtkWidget       *window;
GtkWidget       *text3;
GtkFileChooser *file1;
gchar entry_texts[100];
const gchar *entry_text;

char *cc;
char c[600];
char c1[600];
char cf1[600];
void on_destroy();
void on_select();
void on_click();
void on_acivate();


void on_click(){
	gtk_widget_hide(window2);                
}


void on_acivate(){
}


void on_select(){
	if (firsttime!=0){ 
		gtk_widget_show(window2);
	}
	file1=GTK_FILE_CHOOSER(window);
	cc=gtk_file_chooser_get_filename(file1);
	if (cc!=NULL){
		strcpy(cf1,cc);
		strcpy(c,"ready to convert c file:");
		strcat(c,cc);
		strcat(c,"");

		strcpy(entry_texts,c);
		
		gtk_label_set_text (GTK_LABEL(text3),entry_texts);
		strcpy(c1,"bash -c \"/usr/bin/objdump -d ");
		strcat(c1,cf1); 
		strcat(c1," \" > ");
		strcat(c1,cf1);
		strcat(c1,".asm ");
		strcat(c1," 2> error.txt ");
		printf("%s\n",c1);
		system(c1);
		strcpy(c1,"mousepad ");
		strcat(c1,cf1);
		strcat(c1,".asm");
		system(c1);
		system("mousepad error.txt");

	}
	firsttime=1;

}




void on_destroy(){
	gtk_main_quit();
}











