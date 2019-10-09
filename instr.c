#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char var1[]="hello planet there hi planet.";
char var2[]="planet";
int instr(char *c,char *cc);

int main(int argc, char *argv[])
{
	char *c1=var1;
	char *c2=var2;
	printf("%s\n",c1);
	printf("find %s=%d\n",c2,instr(c1,c2));
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













