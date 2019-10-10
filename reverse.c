#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char var0[1024];
char var1[]="hello planet there hi planet.";
char var2[]="planet";
void reverse(char *destiny,char *src);

int main(int argc, char *argv[])
{
	char *c0=var0;
	char *c1=var1;
	char *c2=var2;
	printf("\e[0;47;34m\n");
	printf("%s\n",c1);
	reverse(c0,c1);
	printf("=%s\n",c0);
}

void reverse(char *destiny,char *src){
	int size=strlen(src);
	int n;
	for (n=0;n<size;n++){
		destiny[n]=src[size-n-1];
	}	
	destiny[size]=0;

}













