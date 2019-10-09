#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char var0[512];
char var1[]="hello 1 there hi 1.";
char var2[]="1";
char var3[]="planet";
void strReplace(char *cccc,char *c,char *cc,char *ccc);

int main(int argc, char *argv[])
{
	char *c0=var0;
	char *c1=var1;
	char *c2=var2;
	char *c3=var3;
	printf("%s\n",c1);
	strReplace(c0,c1,c2,c3);
	printf("%s\n",c0);
}

void strReplace(char *cccc,char *c,char *cc,char *ccc){
	long i1=0;
	long i2=0;
	long i3=0;
	char *v1=NULL;
	char *v2=NULL;
	v2=c;
	strcpy(cccc,"");
	do{
		i1=(long)(void*)v2;
		i3=strlen(v2);
		v1=strstr(v2,cc);
		if (v1!=NULL) i2=(long)(void*)v1;
		if (v1!=NULL) i3=i2-i1;
		strncat(cccc,v2,i3);
		if (v1!=NULL) strcat(cccc,ccc);
		if (v1!=NULL) v2=v1+strlen(cc);
	}while(v1!=NULL);
	

}













