#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char var0[1024];
char *i[1024];

char var1[]="a=10;b=3;a+b";
char var2[]=";";
int strsplint(char *destiny,char *list[],char *src,char separete);

int main(int argc, char *argv[])
{
	int n=0;
	int count=0;
	char *c0=var0;
	char *c1=var1;
	char *c2=var2;
	printf("\e[0;47;34m\n");
	printf("%s\n",c1);
	count=strsplint(c0,i,c1,';');
	printf("vars count=%d\n",count);
	for(n=0;n<count;n++){
		printf("%d	%s\n",n,i[n]);
	}
}

int strsplint(char *destiny,char *list[],char *src,char separete){
	char *v1;
	char *v2;
	char *v3;
	int count=1;
	v1=destiny;
	v2=src;
	strcpy(v1,v2);
	list[0]=v1;
	do{
		v2=v1;
		v1=strchr(v2,separete);
		v3=NULL;
		if (v1!=NULL) v3=v1+1;
		if (v1!=NULL) list[count]=v3;
		if (v1!=NULL) count++;
		if (v1!=NULL) v1[0]=0;
		v1=v3;
	}while(v1!=NULL);
	return count;
}













