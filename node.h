#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

gpointer p;
int firsttime=0;
guint gu1=3000;
GtkTreeSelection  *selected;
GtkWidget       *tree1;
GtkWidget       *text2;
GtkBuilder      *builder; 
GtkWidget       *window;
GtkCellRenderer *render;
GtkTreeModel *model;
GtkTreeStore *store;
GtkTreeIter iter;
GtkTreeIter iter0;
GtkTreeIter iter1;
GtkTreeIter iter2;
GtkTreeIter iter3;
GtkTreeIter iter4;
GtkTreeIter iter5;
GtkTreeIter iter6;
GtkTreeIter iter7;
GtkTreeIter iter8;
GtkTreeIter iter9;
char *cc;
char *dd;
char c[600];
char d[600];
FILE *f1;
gint exitcode=0;
GtkFileChooser *file1;
char texts[68000];
char *textss;
void on_destroy();
void on_select();
void on_acivate();
void on_delete1(GtkTreeView *view,GtkTreePath *paths,GtkTreeViewColumn *Column,gpointer userdatas);
void on_delete2(GtkTreeView *view,GtkTreePath *paths,GtkTreeViewColumn *Column,gpointer userdatas);

void on_delete1(GtkTreeView *view,GtkTreePath *paths,GtkTreeViewColumn *Column,gpointer userdatas){
	gchar *name;
	gchar entry_texts[500];
    gchar *entry_text;
    entry_text=&entry_texts[0];
	GtkTreeModel *mmodel;
	GtkTreeIter iters1;
	mmodel=gtk_tree_view_get_model(GTK_TREE_VIEW(tree1));
			if(!gtk_tree_model_get_iter(mmodel,&iters1,paths)) return;
				if(gtk_tree_model_get_iter(mmodel,&iters1,paths)){
					gtk_tree_model_get(mmodel,&iters1,0,&name,-1);
					strcpy(entry_text,name);
					gtk_entry_set_text (GTK_ENTRY (text2),entry_text);
					
				}



}


void on_destroy(){
	gtk_main_quit();
}











