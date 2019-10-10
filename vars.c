#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char var0[1024];
char var3[160];
char varvar[64000];
char *i[1024];
char *ii[50];
char *iii[1024];


char var1[]="a=10;b=3;c=8;d=4;e=2";
char var2[]=";";
int ssplint(char *destiny,char *list[],char separete);
int main(int argc, char *argv[])
{
	int n=0;
	int count=0;
	int count2=0;
	char *c0=var0;
	char *c1=var1;
	char *c2=var2;
	char *c3=varvar;
	char *c4=var3;
	char **c5;
	printf("\e[0;47;34m\n");
	printf("%s\n",c1);
	count=ssplint(c1,i,';');
	printf("vars count=%d\n",count);
	for(n=0;n<count;n++){
			
			if ((ssplint(i[n],ii,'=')<3)){
				iii[n]=ii[1];
			}
	}


	for(n=0;n<count;n++){
			printf("var = %s\nvalue =%s\n",i[n],iii[n]);
	}

}


int ssplint(char *destiny,char *list[],char separete){
	char *v1;
	char *v2;
	char *v3;
	int count=1;
	v1=destiny;
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












