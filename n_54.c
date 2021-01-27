#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

	/*NIENTE SEED eniente funzione!! SENNo' il numero dato dalla funzione sarà sempre lo stesso*/
/*double casuale(int a, int b){
	double x;
	
	srand();
	x= a+ (double)rand()/RAND_MAX*(b-a);
	return x;
	
}*/


int main(){
	int i,a,b;
	double M, tot,c;
	
	printf("inserisci l'estremo inferiore dell'intervallo \n");
	scanf("%d",&a);
	
	printf("inserisci l'estremo superiore dell'intervallo \n");
	scanf("%d",&b);

	
	printf("inserisci il valore di M \n");
	scanf("%lf",&M);
	
	tot=0;
	i=0;
	srand(time(0));
	do{i++;
	c = a+ (double)rand()/RAND_MAX*(b-a);
	printf("%lf \n",c);
	tot= tot + c;
	printf("%d \n",i);
	}while((tot/i)<M);
	
	
}
