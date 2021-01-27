#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define EPSILON 1.e-5 /*la precisione richiesta*/


int main(){
	int i;
	double a,b,c,delta,p;
	a=0.;
	b=M_PI;
	
	delta = fabs(a - b);
	i =1;
	printf("Questo programma trova la soluzione dell'equazione cos(x)=0 in (0,PI) \n");
	
	while(delta>EPSILON){
		c=(a+b)/2;
		p= cos(a)*cos(c);
		
		if(p<0.){
		
		b=c;
		}
		else if(p>0.){
		a=c;
		}
		else{
		a=b=c;
		
		}
	printf("iternazione n. %d x = %f \n",i++,0.5*(a+b));
	delta= fabs(a-b);
	}
	printf("La soluzione trovata vale : %f\n",c);
	printf("La soluzione vera vale: %f\n",0.5*M_PI);
	printf("la differenza e': %e \n", fabs(0.5*M_PI -c));
	
}
