#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int strchr1(char *argv);
void params(char *argv);
int lists(char *argv);
double PrintList(int sizes);
void priorityList(int sizes);
void priorityString(int sizes);
void clears(int p1,int size);
double solver(char *argv);
double subs(double d1,double d2);
double sums(double d1,double d2);
double muls(double d1,double d2);
double divs(double d1,double d2);

char labels[50*50];

void main(int argc, char *argv[]){
	int ii;
	char argvs[1000];
	char *argvss;
	argvs[0]=0;
	argvss=&argvs[0];
	printf("\e[0;43;30m\n");
	strcpy(argvss,argv[1]);
	params(argvs);
	}


void params(char *argv){
	char c[1024*8];
	char cc[128];
	int i;
	int pos=0;
	int ti;
	int size=0;
	int n=1024*4;
	int counter=0;
	int cond=0;
	double d=0.0;
	char *p1;
	char *p2;
	char *p3;
	char *p4;
	char *p5;
	char *p6;
	char *p7;
	p1=&c[0];
	p2=&c[n];
	memset(c,0,1024*8);
	strcpy(p1,argv);
	p4=&p1[0];


	for(ti=0;ti<16000;ti++){
		printf("?%s\n",p4);
		size=strlen(p4);
		for (i=0;i<size;i++){
			if(p4[i]=='(') p3=&p4[i];
			if(p4[i]==')') {
				p7=&p3[1];
				p3[0]=0;
				p5=&p4[i+1];
				p4[i]=0;
				i=size+1;				
			}
		}
		

		d=solver(p7);
		memset(cc,0,127);

		if(counter==0){
			memset(p2,0,n);
			strcpy(p2,p4);
			sprintf(cc,"%f",d);
			strcat(p2,cc);
			strcat(p2,p5);
			p4=&p2[0];
			pos=strchr1(p4);
			if (pos==-1)ti=16001;
			printf("|%s\n",p2);
		}else{
			memset(p1,0,n);
			strcpy(p1,p4);
			sprintf(cc,"%f",d);
			strcat(p1,cc);
			strcat(p1,p5);
			p4=&p1[0];
			pos=strchr1(p4);
			if (pos==-1)ti=16001;
			printf("|%s\n",p1);
			
		}
		counter++;
		if(counter>1) counter=0;
	}
	printf("====%s\n",p4);
	d=solver(p4);
}


double solver(char *argv){
	int ii=0;
	double r=0.0;
	memset(labels,0,50*50-1);
	//printf("%s\n",argv);
	ii=lists(argv);
	priorityList(ii);
	priorityString(ii);
	r=PrintList(ii);
	return r;
}





int lists(char *argv){
    int i;
    int ii=0;
    int iii=0;
    int iiii=0;
    int ti=0;
    int t2=0;
    int t3=0;
    
    for (i = 0;i<strlen(argv); i++) {
		t2=0;
		if (i==0 && argv[i]=='-') t2=-1;
		if (t3==-1 && argv[i]=='-') t2=-1;
		if ((argv[i]=='+' || argv[i]=='-' || argv[i]=='*' || argv[i]=='/' || argv[i]=='\\' || argv[i]=='(' || argv[i]==')') && t2!=-1 ){
			if (i!=0 && iiii!=1) {
				labels[ii*50+iii]=0;
				ii++;
				iii=0;
				ti++;
				t3=-1;
			}
			labels[ii*50+iii]=(char) argv[i];
			labels[ii*50+iii+1]=0;
			ii++;
			iii=0;
			iiii=1;
			ti++;
			t3=-1;
		}else{
			if(t2==-1){
				labels[ii*50+iii]='-';
				iii++;
				iiii=0;
				i++;
			}
			labels[ii*50+iii]=(char) argv[i];
			iii++;
			iiii=0;
			t2=0;
			t3=0;
		}
		
    }
	labels[ii*50+iii+1]=0;
	return ti+1;

	}


double PrintList(int sizes)

{
    int i=0;
    int ppi=0;
    double d1=0.00;
    double d=0.00;
    double dd=0.00;
    char *p;
    char *p1;
    for (i = 0;i<sizes; i++) {
		p=&labels[i*50];
		if (labels[i*50]!=0){
			if((labels[i*50]>'0'-1 && labels[i*50]<'9'+1)||(labels[i*50]=='-' && labels[i*50+1]!=0)){
				if (i==0) {
					d=atof(p);
				
				
			}}else{
				if (labels[i*50]=='+'){
					p1=&labels[(i+1)*50];
					dd=d;
					d1=atof(p1);
					d=sums(d,d1);	
					if(d1!=0.00) printf("%f + %s=%f\n",dd,p1,d);
					ppi=1;
				}else{
					if (labels[i*50]=='-'){
					p1=&labels[(i+1)*50];
					dd=d;
					d=subs(d,atof(p1));	
					printf("%f - %s=%f\n",dd,p1,d);
					ppi=1;
					}else{
						if (labels[i*50]=='/'){
						}else{
							if (labels[i*50]=='\\'){
								;
							}else{
							if (labels[i*50]=='*'){
								;
							}else{						
								printf("\n error !!!!!!!!!\n");
									
							}
						}
					}
				}
		}
		
		}
    }

i=i+ppi;
ppi=0;
}	
	printf("\n = %f \n",d);
	return d;
}

void priorityList(int sizes)
{
    int i=0;
    int ppi=0;
    double d=0.00;
    double dd=0.00;
    char *p;
    char *p1;
    for (i = 0;i<sizes; i++) {
		p=&labels[i*50];
		if (labels[i*50]!=0){
			if((labels[i*50]>'0'-1 && labels[i*50]<'9'+1)||(labels[i*50]=='-' && labels[i*50+1]!=0)){
				
					d=atof(p);
				
				
			}else{
				if (labels[i*50]=='+'){
					d=0.00;
				}else{
					if (labels[i*50]=='-'){
						d=0.00;
					}else{
						if (labels[i*50]=='/'){
							p1=&labels[(i+1)*50];
							dd=d;
							printf("%f / %f ",d,atof(p1));
							d=divs(d,atof(p1));	
							printf(" = %f \n",d);	
							clears(i-1,50*3);
							labels[i*50]='+';
							labels[(i-1)*50]='0';
							p1=&labels[(i+1)*50];
							sprintf(p1,"%f",d);
							
						}else{
							if (labels[i*50]=='\\'){
							p1=&labels[(i+1)*50];
							dd=d;
							printf("%f / %f ",d,atof(p1));
							d=divs(d,atof(p1));
							printf(" = %f\n",d);	
							clears(i-1,50*3);
							labels[i*50]='+';
							labels[(i-1)*50]='0';
							p1=&labels[(i+1)*50];
							sprintf(p1,"%f",d);
							}else{
							if (labels[i*50]=='*'){
							p1=&labels[(i+1)*50];
							dd=d;
							printf("%f * %f ",d,atof(p1));
							d=muls(d,atof(p1));	
							printf(" = %f \n",d);
							clears(i-1,50*3);
							labels[i*50]='+';
							labels[(i-1)*50]='0';
							p1=&labels[(i+1)*50];
							sprintf(p1,"%f",d);
							}else{						
								printf("\n error !!!!!!!!!\n");
									
							}
						}
					}
				}
		}
		
		}
    }

i=i+ppi;
ppi=0;
}	
}

int strchr1(char *argv){
		int i=-1;
		int pos=-1;
		int size=strlen(argv);
		for (i=0;i<size;i++){
			if(argv[i]==')') {
				pos=i;
				i=size+1;				
			}
		}
		return pos;
}


void priorityString(int sizes)
{
    int i=0;
    int ppi=0;
    double d=0.00;
    double dd=0.00;
    char *p;
    char *p1;
    for (i = 0;i<sizes; i++) {
		p=&labels[i*50];
		printf("%s",p);
	}
	printf("\n");
}

void clears(int p1,int size){
		int i;
		char* c=&labels[p1*50];
		memset(c,0,size);
}

double sums(double d1,double d2){
	return d1+d2;
}

double subs(double d1,double d2){
	return d1-d2;
}

double muls(double d1,double d2){
	return d1*d2;
}

double divs(double d1,double d2){
	return d1/d2;
}
