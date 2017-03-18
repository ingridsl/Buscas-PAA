/* Universidade de Brasília

Ingrid Santana Lopes - 14/0083065
Projeto e Análise de Algoritmos*/


#include <stdio.h>
#include <stdlib.h>

int bsearch1(int array[], int target,int first, int last){

	if (first > last)
		return -1;

	int middle = (first+last)/2;
		
		if (array[middle] < target)
			 return search1(array, target,middle+1, last);
		
		else if (array[middle] > target)
			return bsearch1(array, target, first, middle-1);

		while((middle!=-1)&&(array[middle]==target)){
			middle--;
		}
	
return middle+1;
}


int main(){
int c, n, i, tests, target;
 
scanf("%d",&n);

int *array = (int*) malloc (n*sizeof(int));
 
scanf("%d", &tests);
   for (c = 0; c < n; c++)
      scanf("%d",&array[c]);
 
	for(i=0; i<tests; i++){
		scanf("%d",&target);
		printf("%d\n",bsearch1(array,target,0,n));
	}

   return 0;   
}
