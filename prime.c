#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define N 100

int main(){
	int i,j, jMax;

	for(i=1;i<N;i++){
		j=2;
		jMax = (int) sqrt(i)+1;
		while((j<jMax) && (i%j)==0) {

			j++;
		}
		if(j==jMax){
			printf("%d \n",i);
			
		}
		
	}
}
