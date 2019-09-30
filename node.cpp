#include "node.h"
int main(int argc, char *argv[])
{
	
    gtk_init(&argc, &argv);
	textss=&texts[0];
    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "node.glade", NULL);

    window = GTK_WIDGET(gtk_builder_get_object(builder, "form1"));
	tree1 = GTK_WIDGET(gtk_builder_get_object(builder, "tree1"));
	text2 = GTK_WIDGET(gtk_builder_get_object(builder, "text2"));
	store=gtk_tree_store_new(1,G_TYPE_STRING);

	gtk_tree_store_append(store,&iter0,NULL);
	gtk_tree_store_set(store,&iter0,0,"x86",-1);
	gtk_tree_store_append(store,&iter1,NULL);
	gtk_tree_store_set(store,&iter1,0,"ARM",-1);

	gtk_tree_store_append(store,&iter2,&iter0);
	gtk_tree_store_set(store,&iter2,0,"8086",-1);
	gtk_tree_store_append(store,&iter3,&iter0);
	gtk_tree_store_set(store,&iter3,0,"80186",-1);
	gtk_tree_store_append(store,&iter4,&iter0);
	gtk_tree_store_set(store,&iter4,0,"80286",-1);
	gtk_tree_store_append(store,&iter5,&iter0);
	gtk_tree_store_set(store,&iter5,0,"80386",-1);
	gtk_tree_store_append(store,&iter6,&iter0);
	gtk_tree_store_set(store,&iter6,0,"80486",-1);
	gtk_tree_store_append(store,&iter7,&iter0);
	gtk_tree_store_set(store,&iter7,0,"above",-1);
	gtk_tree_store_append(store,&iter8,&iter1);
	gtk_tree_store_set(store,&iter8,0,"none",-1);
		
	
	render=gtk_cell_renderer_text_new();
	gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(tree1),-1,"processors",render,"text",0,NULL);
	model=GTK_TREE_MODEL(store);
	gtk_tree_view_set_model(GTK_TREE_VIEW(tree1),model);
  
	g_signal_connect_swapped (window , "destroy",
			      G_CALLBACK (on_destroy),
			    window );

	g_signal_connect_swapped (tree1, "row-activated",
			      G_CALLBACK (on_delete1),
			    NULL );


    g_object_unref(builder);
    gtk_widget_show(window);                
    gtk_main();
    return 0;
}
