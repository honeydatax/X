#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int count=0;
int count2=0;
char var0[1024];
char var3[160];
char varvar[64000];
char *i[1024];
char *ii[50];
char *iii[1024];
char labels[50*50];
char var1[]="a=10;b=3;c=8;d=4;e=2";
char var2[]=";";

int strchr1(char *argv);
void params(char *argv);
int lists(char *argv);
double PrintList(int sizes);
void priorityList(int sizes);
void priorityString(int sizes);
void clears(int p1,int size);
double solver(char *argv);
int ssplint(char *destiny,char *list[],char separete);
double getnumbers(char *s1);
double getvar(char *s1);
double subs(double d1,double d2);
double sums(double d1,double d2);
double muls(double d1,double d2);
double divs(double d1,double d2);

void main(int argc, char *argv[]){
	int n=0;
	char *c0=var0;
	char *c1;
	char *c2=var2;
	char *c3=varvar;
	char *c4=var3;
	char *c5;
	char argvs[1000];
	char aargvs[1000];
	char *aargvss=aargvs;
	char *argvss;
	int vc=0;
	strcpy(argvs,"");
	argvss=argvs;
	printf("\e[0;47;34m\n");
	strcpy(argvss,argv[1]);
	c1=argvss;
	printf("%s\n",c1);
	count=ssplint(c1,i,';');
	printf("vars count=%d\n",count);
	for(n=0;n<count;n++){
		vc=ssplint(i[n],ii,'=');		
			if (vc==2){
				iii[n]=ii[1];

			}
			if (vc==1){
				strcpy(aargvss,"(");
				strcat(aargvss,i[n]);
				strcat(aargvss,")");
				params(aargvss);

			}
	}


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
			if((labels[i*50]>'A'-1 && labels[i*50]<'Z'+1)||(labels[i*50]>'a'-1 && labels[i*50]<'z'+1)||(labels[i*50]>'0'-1 && labels[i*50]<'9'+1)||(labels[i*50]=='-' && labels[i*50+1]!=0)){
				if (i==0) {
					d=getnumbers(p);
				
				
			}}else{
				if (labels[i*50]=='+'){
					p1=&labels[(i+1)*50];
					dd=d;
					
					d1=getnumbers(p1);
					d=sums(d,d1);	
					if(d1!=0.00) printf("%f + %s=%f\n",dd,p1,d);
					ppi=1;
				}else{
					if (labels[i*50]=='-'){
					p1=&labels[(i+1)*50];
					dd=d;
					d=subs(d,getnumbers(p1));	
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
			if((labels[i*50]>'A'-1 && labels[i*50]<'Z'+1)||(labels[i*50]>'a'-1 && labels[i*50]<'z'+1)||(labels[i*50]>'0'-1 && labels[i*50]<'9'+1)||(labels[i*50]=='-' && labels[i*50+1]!=0)){
				
					d=getnumbers(p);
				
				
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
							printf("%f / %f ",d,getvar(p1));
							d=divs(d,getnumbers(p1));	
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
							printf("%f / %f ",d,getnumbers(p1));
							d=divs(d,getnumbers(p1));
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
							printf("%f * %f ",d,getnumbers(p1));
							d=muls(d,getnumbers(p1));	
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


double getnumbers(char *s1){
	double d=0;
	if (s1[0]>('0'-1) && s1[0]<('9'+1)){
		d=atof(s1);		
	}else{
		d=getvar(s1);
	}
	
return d;
}

double getvar(char *s1){
	int n=0;
	double d=0;
	for (n=0;n<count;n++){
		if(strcmp(s1,i[count-n-1])==0){
			d=atof(iii[count-n-1]);
			n=count+1;
		}
	}
	return d;
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
