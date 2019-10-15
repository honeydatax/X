#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char *file="labelhtml.dat";
char varname[864000]; 
char varname2[864000]; 
char var1[512];
void on_select();
char *body_start(char *c);
char *body_end(char *c);
void remove_tags(char *c, char *cc);

int main(int argc, char *argv[])
{
	char *c=varname;
	char *cc=varname2;
	printf("\e[0;47;34m\n");
	strcpy(var1,"curl -s ");
	strcat(var1,argv[1]);
	strcat(var1," > ");
	strcat(var1,file);
	system(var1);
	on_select();
	c=body_start(c);
	body_end(c);
	remove_tags(cc,c);
	printf("%s\n",cc);

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







