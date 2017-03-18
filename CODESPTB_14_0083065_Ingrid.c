/* Universidade de Brasília

Ingrid Santana Lopes - 14/0083065
Projeto e Análise de Algoritmos*/


#include <stdio.h>
#include<stdlib.h>
#define max 100000
 
int main(){
	int n, i, testes, array[max], c, d, t, contador=0;

	scanf("%d", &testes);

	for(i=0; i<testes; i++){
 		contador =0;
		scanf("%d", &n);

		 
		for (c = 0; c < n; c++) {
			scanf("%d", &array[c]);
		}
		 
		for (c = 1 ; c <= n - 1; c++) {
			d = c;
	 
			while ( d > 0 && array[d] < array[d-1]) {
				contador++;
				t = array[d];
		     		array[d] = array[d-1];
		      		array[d-1] = t;
				d--;
			}
	}
 	printf("%d ", contador);

} 
return 0;
}
