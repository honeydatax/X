#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

 //g++ -o out view.cpp  `pkg-config gtk+-2.0 --cflags --libs`

void tvprintf(char *s,int b,int tab);
int strchr1(char *argv);
void params(char *argv);
int lists(char *argv);
double PrintList(int sizes);
void priorityList(int sizes);
void priorityString(int sizes);
void clears(int p1,int size);
double solver(char *argv);
double subs(double d1,double d2);
double sums(double d1,double d2);
double muls(double d1,double d2);
double divs(double d1,double d2);
void smain();

int errorss;
char labels[50*50];
GtkWidget *entry2;
GtkWidget *entry;
char printft[68000];
char argsvv[1000];
char *argsvvv;
static void enter_callback() 
                            
{
  const gchar *entry_text;
  
  entry_text = gtk_entry_get_text (GTK_ENTRY (entry));
  sprintf(argsvvv,"(%s)",entry_text);
  strcpy(printft,"\n");
  errorss=-1;
  smain();
  if (errorss!=-1) gtk_text_buffer_set_text(gtk_text_view_get_buffer(GTK_TEXT_VIEW(entry2)),"error!!!!",-1);
}

int main( int   argc,
          char *argv[] )
{
    GdkColor color1;
    GtkWidget *window;
    GtkWidget *vbox, *hbox;
    GtkWidget *layout1;
    GtkWidget *button;
    GtkWidget *check;
    gint tmp_pos;
	argsvvv=&argsvv[0];
    gtk_init (&argc, &argv);
    
    color1.red=56000;
    color1.green=56000;
    color1.blue=56000;
	sprintf(argsvvv,"%d",0);
    /* create a new window */
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_widget_set_size_request (GTK_WIDGET (window), 620, 340);
    gtk_window_set_title (GTK_WINDOW (window), "calc");
    g_signal_connect (window, "destroy",
                      G_CALLBACK (gtk_main_quit), NULL);
    g_signal_connect_swapped (window, "delete-event",
                              G_CALLBACK (gtk_widget_destroy), 
                              window);
	layout1=gtk_layout_new(FALSE, 0);
    vbox = gtk_vbox_new (FALSE, 0);
    gtk_container_add (GTK_CONTAINER (window), vbox);
    gtk_container_add (GTK_CONTAINER (vbox), layout1);
    gtk_widget_show (vbox);
    gtk_widget_show (layout1);
    
    entry = gtk_entry_new ();
    entry2 = gtk_text_view_new ();
	gtk_text_buffer_set_text(gtk_text_view_get_buffer(GTK_TEXT_VIEW(entry2)),argsvvv,-1);
	
    gtk_entry_set_max_length (GTK_ENTRY (entry), 550);
    
    g_signal_connect (entry, "activate",
		      G_CALLBACK (enter_callback),
		      entry);
    gtk_entry_set_text (GTK_ENTRY (entry), "(12+12)*(12+12)/(12-3)");
    tmp_pos = GTK_ENTRY (entry)->text_length;
    gtk_editable_insert_text (GTK_EDITABLE (entry), "", -1, &tmp_pos);
    
    gtk_editable_select_region (GTK_EDITABLE (entry),
			        0, GTK_ENTRY (entry)->text_length);
    
    gtk_box_pack_start (GTK_BOX (vbox), entry, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX (vbox), entry2, TRUE, TRUE, 0);
	
	gtk_widget_modify_text(window,GTK_STATE_NORMAL,&color1);
	gtk_widget_modify_bg(window,GTK_STATE_NORMAL,&color1);
	gtk_widget_modify_fg(window,GTK_STATE_NORMAL,&color1);
	gtk_widget_modify_base(window,GTK_STATE_NORMAL,&color1);
	gtk_widget_modify_bg(entry,GTK_STATE_NORMAL,&color1);
	gtk_widget_modify_bg(entry2,GTK_STATE_NORMAL,&color1);
	gtk_widget_modify_fg(entry,GTK_STATE_NORMAL,&color1);
	gtk_widget_modify_fg(entry2,GTK_STATE_NORMAL,&color1);
	gtk_widget_modify_base(entry,GTK_STATE_NORMAL,&color1);
	gtk_widget_modify_base(entry2,GTK_STATE_NORMAL,&color1);
    gtk_widget_show (entry);
    gtk_widget_show (entry2);

    hbox = gtk_hbox_new (FALSE, 0);
    gtk_container_add (GTK_CONTAINER (vbox), hbox);
    gtk_widget_show (hbox);
   
     
     
    button = gtk_button_new_with_label ("calc");
    g_signal_connect_swapped (button, "clicked",
			      G_CALLBACK (enter_callback),
			     entry);
    gtk_box_pack_start (GTK_BOX (vbox), button, TRUE, TRUE, 0);
    gtk_widget_set_can_default (button, TRUE);
    gtk_widget_grab_default (button);
    gtk_widget_modify_base(button,GTK_STATE_NORMAL,&color1);
    gtk_widget_modify_fg(button,GTK_STATE_NORMAL,&color1);
    gtk_widget_modify_bg(button,GTK_STATE_NORMAL,&color1);
   
    gtk_widget_show (button);
    gtk_widget_set_size_request (GTK_WIDGET (entry2), 620, 200);
    gtk_widget_show (window);

    gtk_main();

    return 0;
}

void params(char *argv){
	char c[1024*8];
	char cc[128];
	int i;
	int pos=0;
	int ti;
	int size=0;
	int n=1024*4;
	int counter=0;
	int cond=0;
	double d=0.0;
	char *p1;
	char *p2;
	char *p3;
	char *p4;
	char *p5;
	char *p6;
	char *p7;
	GtkClipboard *clip=gtk_clipboard_get(GDK_SELECTION_CLIPBOARD);
	p1=&c[0];
	p2=&c[n];
	memset(c,0,1024*8);
	strcpy(p1,argv);
	p4=&p1[0];


	for(ti=0;ti<16000;ti++){
		tvprintf(p4,0,0);
		size=strlen(p4);
		for (i=0;i<size;i++){
			if(p4[i]=='(') p3=&p4[i];
			if(p4[i]==')') {
				p7=&p3[1];
				p3[0]=0;
				p5=&p4[i+1];
				p4[i]=0;
				i=size+1;				
			}
		}
		

		d=solver(p7);
		memset(cc,0,127);

		if(counter==0){
			memset(p2,0,n);
			strcpy(p2,p4);
			sprintf(cc,"%f",d);
			strcat(p2,cc);
			strcat(p2,p5);
			p4=&p2[0];
			pos=strchr1(p4);
			if (pos==-1)ti=16001;
			tvprintf(p2,0,10);
		}else{
			memset(p1,0,n);
			strcpy(p1,p4);
			sprintf(cc,"%f",d);
			strcat(p1,cc);
			strcat(p1,p5);
			p4=&p1[0];
			pos=strchr1(p4);
			if (pos==-1)ti=16001;
			tvprintf(p1,0,10);
			
		}
		counter++;
		if(counter>1) counter=0;
	}
	tvprintf(p4,0,15);
	d=solver(p4);
	sprintf(argsvvv,"%f",d);
	tvprintf(argsvvv,0,0);
	
	gtk_text_buffer_set_text(gtk_text_view_get_buffer(GTK_TEXT_VIEW(entry2)),printft,-1);
	gtk_clipboard_set_text(clip,printft,-1);
	
}


double solver(char *argv){
	int ii=0;
	double r=0.0;
	memset(labels,0,50*50-1);
	tvprintf(argv,0,12);
	ii=lists(argv);
	priorityList(ii);
	priorityString(ii);
	r=PrintList(ii);
	return r;
}





int lists(char *argv){
    int i;
    int ii=0;
    int iii=0;
    int iiii=0;
    int ti=0;
    int t2=0;
    int t3=0;
    int t5=0;
    
    for (i = 0;i<strlen(argv); i++) {
		t2=0;

		if (i==0 && argv[i]=='-') t2=-1;
		if (argv[i]==' ') t5=-1;
		if (t3==-1 && argv[i]=='-') t2=-1;
		if ((argv[i]=='+' || argv[i]=='-' || argv[i]=='*' || argv[i]=='/' || argv[i]=='\\' || argv[i]=='(' || argv[i]==')') && t2!=-1 ){
			if (i!=0 && iiii!=1) {
				labels[ii*50+iii]=0;
				ii++;
				iii=0;
				ti++;
				t3=-1;
			}
			labels[ii*50+iii]=(char) argv[i];
			labels[ii*50+iii+1]=0;
			ii++;
			iii=0;
			iiii=1;
			ti++;
			t3=-1;
		}else{
			if(t2==-1 && t5!=-1){
				labels[ii*50+iii]='-';
				iii++;
				iiii=0;
				i++;
			}
			if (t5!=-1){
				labels[ii*50+iii]=(char) argv[i];
				iii++;
				iiii=0;
				t2=0;
				t3=0;
			}
		}
		t5=0;
    }
	labels[ii*50+iii+1]=0;
	return ti+1;

	}


double PrintList(int sizes)

{
    int i=0;
    int ppi=0;
	char x[400];
    double d1=0.00;
    double d=0.00;
    double dd=0.00;
    char *p;
    char *p1;
    for (i = 0;i<sizes; i++) {
		p=&labels[i*50];
		if (labels[i*50]!=0){
			if((labels[i*50]>'0'-1 && labels[i*50]<'9'+1)||(labels[i*50]=='-' && labels[i*50+1]!=0)){
				if (i==0) {
					d=atof(p);
				
				
			}}else{
				if (labels[i*50]=='+'){
					p1=&labels[(i+1)*50];
					dd=d;
					d1=atof(p1);
					d=sums(d,d1);	
					if(d1!=0.00) {
						sprintf(x,"%f + %s=%f",dd,p1,d);
						tvprintf(x,0,20);
					}
					ppi=1;
				}else{
					if (labels[i*50]=='-'){
					p1=&labels[(i+1)*50];
					dd=d;
					d=subs(d,atof(p1));	
					sprintf(x,"%f - %s=%f",dd,p1,d);
					tvprintf(x,0,20);
					ppi=1;
					}else{
						if (labels[i*50]=='/'){
						}else{
							if (labels[i*50]=='\\'){
								;
							}else{
							if (labels[i*50]=='*'){
								;
							}else{						
								//printf("\n error !!!!!!!!!\n");
								errorss=0;	
							}
						}
					}
				}
		}
		
		}
    }

i=i+ppi;
ppi=0;
}	
	sprintf(x," = %f",d);
	tvprintf(x,0,0);
	return d;
}

void priorityList(int sizes)
{
    int i=0;
    char x[400];
    int ppi=0;
    double d=0.00;
    double dd=0.00;
    char *p;
    char *p1;
    for (i = 0;i<sizes; i++) {
		p=&labels[i*50];
		if (labels[i*50]!=0){
			if((labels[i*50]>'0'-1 && labels[i*50]<'9'+1)||(labels[i*50]=='-' && labels[i*50+1]!=0)){
				
					d=atof(p);
				
				
			}else{
				if (labels[i*50]=='+'){
					d=0.00;
				}else{
					if (labels[i*50]=='-'){
						d=0.00;
					}else{
						if (labels[i*50]=='/'){
							p1=&labels[(i+1)*50];
							dd=d;
							sprintf(x,"%f / %f ",d,atof(p1));
							tvprintf(x,1,20);
							d=divs(d,atof(p1));	
							sprintf(x," = %f ",d);	
							tvprintf(x,0,0);
							clears(i-1,50*3);
							labels[i*50]='+';
							labels[(i-1)*50]='0';
							p1=&labels[(i+1)*50];
							sprintf(p1,"%f",d);
							
						}else{
							if (labels[i*50]=='\\'){
							p1=&labels[(i+1)*50];
							dd=d;
							sprintf(x,"%f / %f ",d,atof(p1));
							tvprintf(x,1,20);
							d=divs(d,atof(p1));
							sprintf(x," = %f ",d);	
							tvprintf(x,0,0);
							clears(i-1,50*3);
							labels[i*50]='+';
							labels[(i-1)*50]='0';
							p1=&labels[(i+1)*50];
							sprintf(p1,"%f",d);
							}else{
							if (labels[i*50]=='*'){
							p1=&labels[(i+1)*50];
							dd=d;
							sprintf(x,"%f * %f ",d,atof(p1));
							tvprintf(x,1,20);
							d=muls(d,atof(p1));	
							sprintf(x," = %f ",d);	
							tvprintf(x,0,0);
							clears(i-1,50*3);
							labels[i*50]='+';
							labels[(i-1)*50]='0';
							p1=&labels[(i+1)*50];
							sprintf(p1,"%f",d);
							}else{						
								//printf("\n error !!!!!!!!!\n");
								errorss=0;	
							}
						}
					}
				}
		}
		
		}
    }

i=i+ppi;
ppi=0;
}	
}

int strchr1(char *argv){
		int i=-1;
		int pos=-1;
		int size=strlen(argv);
		for (i=0;i<size;i++){
			if(argv[i]==')') {
				pos=i;
				i=size+1;				
			}
		}
		return pos;
}


void priorityString(int sizes)
{
    int i=0;
    int ppi=0;
    double d=0.00;
    double dd=0.00;
    char *p;
    char *p1;
    for (i = 0;i<sizes; i++) {
		p=&labels[i*50];
		//tvprintf(p,0,20);
	}
	
}

void tvprintf(char *s,int b,int tab){
	char xxx[]="____________________________________________________________________________________________________";
	char *ccc;
	ccc=&xxx[0];
	int i;
	if (tab>0){
		
		strncat(printft,ccc,tab);
	}
	strcat(printft,s);
	if (b==0) strcat(printft,"\n");
}


void clears(int p1,int size){
		int i;
		char* c=&labels[p1*50];
		memset(c,0,size);
}

double sums(double d1,double d2){
	return d1+d2;
}

double subs(double d1,double d2){
	return d1-d2;
}

double muls(double d1,double d2){
	return d1*d2;
}

double divs(double d1,double d2){
	return d1/d2;
}

void smain(){
	int ii;
	char *argvs;
	argvs=&argsvv[0];
	params(argvs);
}


