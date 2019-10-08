#include <string.h>
#include <stdlib.h>
#include <stdio.h>

const char file[]="input.txt";
char varname[64000]; 
char varvalue[64000];
int on_select();

int main(int argc, char *argv[])
{
	int counter=on_select();
	int n=0;
	char *c;
	char *cc;
	printf("%d vars load\n",counter);
	for (n=0;n<counter;n++){
		printf("%d\n",n);
		c=&varname[n*80];
		cc=&varvalue[n*255];
		printf("%d = %s\n",n,c);
		printf("= %s\n",cc);
	}
}

int on_select(){
	int counter=0;
	const char *cc;
	char *ee;
	char *ff;
	char *dd;
	char *gg;
	char *hh;
	//char c[600];
	char d[600];
	FILE *f1;
	
	cc=&file[0];
	if (cc!=NULL){
		f1=fopen(cc,"r");
		dd=&d[0];
		do{
			fgets(dd,599,f1);
			ee=strstr(dd,"=");
			if (ee!=NULL){
				gg=&varname[counter*80];
				hh=&varvalue[counter*255];
				ff=&ee[1];
				ee[0]='\0';
				strcpy(gg,dd);
				strcpy(hh,ff);
				counter++;
				
			}
		}while(!feof(f1));

		fclose(f1);
		
		
		

	}
	return counter;

}













