#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

/*questo programma produce un'immagine dell'attrattore di Lorenz */

#define val 3

/*funzione che genera numeri pseudorandom da una distribuzione uniforme (0,1)*/
double *lcg(int a, int c, int M, int n){
	double  x[n];
	double *randnum= malloc(sizeof(double)*n);
	int i;
	x[0]= fmod( a*1+c, M);
	
	for(i=0;i<n;i++){
		x[i+1]= (int)(a*x[i]+c)%M;
		randnum[i] = x[i+1]/M;
	}
	
	return randnum;

}


void lorenz(double x0, double y0, double z0,char* filename){
double rho, sigma, beta; /*parametri dell'attrattore*/
	int i,j, num_passi,tot,M;
	double dt;
	char scelta[2], term;
	double *randn;
	
	
	/*printf("Vuoi mantere i valori prestabiliti di rho=28, sigma=10, beta=8/3? \nScrivi \"no\" per modificarli\n");
	scanf("%s", &scelta[0]);
	if(strcmp(scelta,"no")==0){
		
		printf("inserisci rho, sigma, beta \n");
		scanf("%lf %lf %lf", &rho, &sigma, &beta);
		printf("i nuovi valori ora sono, rho: %lf, sigma %lf, beta %lf", rho,sigma, beta);
	}
	else{*/	
		rho=28; 
		sigma=10;
		beta=8/3.;
	/*}*/
	
	dt=0.01;
	num_passi=100;
	
	tot= (int)(num_passi/dt);
	double x[tot], y[tot], z[tot];

	


	/* condizioni iniziali */
	
	printf("Vuoi mantenere le condizioni iniziali? \nScrivi \"no\" per inserire l'M per l'inizializzazione random\n ");
	scanf("%s", &scelta[0]);
	if(strcmp(scelta,"no")==0){
		printf("inserisci M \n");
		if(scanf("%d%c", &M, &term) !=2 || term != '\n'){
		printf("ERRORE!! INSERIRE SOLO NUMERI INTERI. Riprova a runnare\n");
		}
		
		
		randn= (double *) malloc(sizeof(double)*val);
		randn = lcg(6935,7,M, val);
		/*printf("%lf %lf %lf \n",randn[0], randn[1], randn[2]); */
		
		x[0]= x0 + randn[0];
		y[0]= y0 + randn[1];
		z[0]= z0 + randn[2];
	}
	else{		
		
		x[0]= x0;
		y[0]= y0;
		z[0]= z0;

	}
	printf("Inizializzazione: %lf %lf %lf \n", x[0], y[0], z[0]);
	
	printf("\n");
	
	FILE *fp;
	fp=fopen(filename,"w");
	
	/*integrazione*/
	
	for(i=0;i<(tot)+1;i++){
		x[i+1] = x[i]+((sigma*(y[i]-x[i]))*dt);
		y[i+1] = y[i]+((rho*x[i]-(x[i]*z[i])-y[i])*dt);
		z[i+1] = z[i]+((x[i]*y[i]-beta*z[i])*dt);
		fprintf(fp,"%lf \t %lf \t %lf \n",x[i],y[i],z[i]);
	}
	
     	fclose(fp);

}



int main(){
	int i,n;
	double x0,y0,z0;
	char term;
	char filename[15];
	
	printf("Quante simulazioni vuoi ottenere? Inserisci un numero intero\n");
	if(scanf("%d%c", &n, &term) !=2 || term != '\n'){
		printf("ERRORE!! INSERIRE SOLO NUMERI INTERI. Riprova a runnare \n");
		n=0;
		exit(0);
		}
		
	printf("Inserisci le condizioni iniziali (x0,y0,z0)\n");
		if(scanf("%lf %lf %lf", &x0,&y0,&z0) !=3){
			printf("ERRORE!! INSERIRE SOLO NUMERI REALI. Riprova a runnare \n");
			exit(0);
		}
	
	for(i=0;i<n;i++){
		printf("Simulazione n.%d \n", i+1);
		sprintf(filename, "lorenz_%d.dat", i+1);

		lorenz(x0,y0,z0,filename);
	}
	
	
	

}
