#include <cairo.h>
#include <cairo-pdf.h>
#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>



//g++ -o out browser.c  `pkg-config gtk+-2.0 --cflags --libs`
int w=640;
int h=1000;
char files[]="labelhtml.dat";
char *file=files;
char varname[864000]; 
char varname2[864000]; 
char var1[512];
char var2[98];
cairo_t *cr ;
char *body_start(char *c);
char *body_end(char *c);
void remove_tags(char *c, char *cc);
void on_selection();
void on_select();
char *aargv;
int instr(char *c,char *cc);

int main(int argc, char *argv[])
{
		aargv=argv[1];
		cairo_surface_t *surface = cairo_pdf_surface_create("labelhtml.pdf",w, h );
		cr = cairo_create (surface);
		cairo_set_source_rgb(cr,1.0,1.0,1.0);
		cairo_set_line_width(cr,1);
        cairo_rectangle(cr,0.0,0.0,640.0,350.0);
        cairo_stroke_preserve(cr);
        cairo_fill(cr);
        cairo_select_font_face(cr,"mono",CAIRO_FONT_SLANT_NORMAL,CAIRO_FONT_WEIGHT_BOLD);
        cairo_set_font_size(cr,12.0);
        cairo_set_source_rgb(cr,0.0,0.0,0.0);
        on_selection();
        cairo_surface_destroy (surface);
        cairo_destroy (cr);
        //system("exo-open labelhtml.pdf");
        return 0;
}

void on_selection(){
	int n=0;
	int nnn=0;
	int in=0;
	char *dd;
	char *ee;
	float nn=20.0f;
	char *c=varname;
	char *cc=varname2;
	char enterss[]="\r";
	char *entersss=enterss;
	char enter[]="\n";
	char *enters=enter;
	printf("\e[0;47;34m\n");
	strcpy(var1,"curl -s ");
	strcat(var1,aargv);
	strcat(var1," > ");
	strcat(var1,file);
	system(var1);
	on_select();
	c=body_start(c);
	body_end(c);
	remove_tags(cc,c);
	dd=cc;
	
	do{
		n=instr(dd,enters);
		in=instr(dd,entersss);
		if (n==-1)n=1000;
		if (in==-1)in=1000;
		if (in<n)n=in;
		printf("%d\n",n);
		if(n<90){
			cc=dd+n;
			ee=cc+n+1;
			cc[0]=0;
			cairo_move_to(cr,20.00,nn);
			cairo_show_text(cr,dd);
			nn=nn+14.0;
			dd=ee;
		}else{
			n=strlen(dd);
			if(n<90){
			cairo_move_to(cr,20.00,nn);
			cairo_show_text(cr,dd);
			nn=nn+14.0;
			ee=dd+n;
			dd=ee;
			}else{
				strncpy(var2,dd,90);
				cairo_move_to(cr,20.00,nn);
				cairo_show_text(cr,var2);
				nn=nn+14.0;
				ee=dd+91;
				dd=ee;
			}
		}
		if (dd[0]==0 || nn > 986)nnn=1;
	}while(nnn!=1);

		
	}





void on_select(){
	char *cc;
	char *ccc;
	char d[600];
	char *dd=d;

	FILE *f1;
	
	cc=file;
	if (cc!=NULL){
		ccc=varname;
		strcpy(ccc,"");
		f1=fopen(cc,"r");
		do{
			fgets(dd,599,f1);
			strcat(ccc,dd);
			
			
		}while(!feof(f1));

		fclose(f1);
		
		
		

	}
}

char *body_start(char *c){
	char *cc=NULL;
	cc=strstr(c,"<body>");
	if (cc==NULL) cc=strstr(c,"<BODY>");
	if (cc!=NULL) cc=cc+6; 
	return cc;
}

char *body_end(char *c){
	char *cc=NULL;
	cc=strstr(c,"</body>");
	if (cc==NULL) cc=strstr(c,"</BODY>");
	if (cc!=NULL) cc[0]=0; 
	return cc;
}

void remove_tags(char *c, char *cc){
	char *ccc=c;
	char *cccc=cc;
	char *ccc1=cc;
	char *cccc1=cc;
	int tim=0;
	strcpy(c,"");
	do{
		cccc1=strstr(cccc,"<");
		if (cccc1!=NULL){
			ccc1=cccc1+1;
			cccc1[0]=0;
			strcat(c,cccc);
			cccc=strstr(ccc1,">");
			cccc=cccc+1;
			if (cccc[0]=='\0') tim=1;
		}else{
			strcat(c,cccc);
			tim=1;
		}
		
	}while(tim!=1);
}


int instr(char *c,char *cc){
	long i1=0;
	long i2=0;
	long i3=0;
	char *v1=NULL;
	i1=(long)(void*)c;
	i3=-1;
	v1=strstr(c,cc);
	if (v1!=NULL) i2=(long)(void*)v1;
	if (v1!=NULL) i3=i2-i1;
	return (int) i3;
}







