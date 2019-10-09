#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char var0[1024];
char var1[]="hello planet there hi planet.";
char var2[]="planet";
void mid(char *destiny,char *src,int start,int count);

int main(int argc, char *argv[])
{
	char *c0=var0;
	char *c1=var1;
	char *c2=var2;
	printf("\e[0;47;34m\n");
	printf("%s\n",c1);
	mid(c0,c1,6,12);
	printf("=%s\n",c0);
}

void mid(char *destiny,char *src,int start,int count){
	char *v1;
	char *v2;
	v1=destiny;
	v2=src+start;
	strcpy(v1,"");
	v1=strncat(v1,v2,count);
	
}













