#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

const char *printers="/dev/stdout";
const char *files="cal.txt";
const char *charsto="__";
void replaceChar(char *c,const char *replaces);
void filereplace(const char *c,const char *printer,const char *replaces );
int main(int argc, char *argv[])
{

	system("cal > cal.txt");
	filereplace(files,printers,charsto);
	return 0;
}

void filereplace(const char *c,const char *printer,const char *replaces ){
	FILE *f1;
	FILE *f2;
	char d[600];
	char *dd;
	if (c!=NULL){
		f1=fopen(c,"r");
		dd=&d[0];
		f2=fopen(printer,"w");
		do{
			fgets(dd,599,f1);
			replaceChar(dd,replaces);
			fprintf(f2,"%s",dd);
		}while(!feof(f1));
		fclose(f2);
		fclose(f1);
	}
		
	
}


void replaceChar(char *c,const char *replaces){
	int sizess1=strlen(c);
	int sizess2=strlen(replaces);
	int counts1=0;
	int counts2=0;
	int counts3=0;
	int counts4=0;
	char cha;
	
	for (counts1=0;counts1<sizess1+1;counts1++){
		counts4=1;
		for (counts2=0;counts2<sizess2;counts2++){
			if (c[counts1]==replaces[counts2]) counts4=0;
		}
		cha=c[counts1];
		if (counts4!=0) c[counts3]=cha;
		counts3=counts3+counts4;
		
	}

}







