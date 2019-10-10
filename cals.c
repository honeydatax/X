#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void printt();
int getdays();
int getmont();
int getmontd();
int getyear();
void printday(int d);
time_t d;
struct tm dd;



int main(int argc, char *argv[])
{	
	printf("\e[0;47;34m\n");
	printt();
}

void printt(){
	d=time(NULL);
	dd =*localtime(&d);
	int r=getdays();
	int m=getmontd();
	int leep=r;
	int n=1;
	
	printf("Su Mo Tu We Th Fr Sa\n");
	printday(r*3);
	for(n=1;n<m+1;n++){
		if (n<10)printf(" ");
		printf("%d",n);
		leep++;
		if (leep>6){
			leep=0;
			printf("\n");
		}else{
			printf(" ");
		}
		
		
	}
	printf("\n");
}

int getdays(){
	int r=0;
	dd.tm_mday=1;
	mktime(&dd);
	r=dd.tm_wday;
	return r;
}

int getmont(){
	int r=0;
	r=dd.tm_mon+1;
	printf("month=%d\n",r);
	return r;
}

int getmontd(){
	int y=getyear();
	int m=getmont();
	int mm[]={31,28,31,30,31,30,31,31,30,31,30,31};
	int t=mm[m-1];
	int leap=0;
	if (m=2){
		leap=y/4;
		if (leap*4==y){
			t++;
		}
	}
	return t;
}



int getyear(){
	int r=0;
	r=dd.tm_year+1900;
	printf("%d\n",r);
	return r;
}

void printday(int d){
	int n=0;
	for (n=0;n<d;n++){
		printf(" ");
	}
}

