/* Universidade de Brasília

Ingrid Santana Lopes - 14/0083065
Projeto e Análise de Algoritmos*/


#include <stdio.h>
#include<stdlib.h>
#define max 100000



void Merge(int *A,int *L,int left,int *R,int right) {
	int i,j,k;

	i = 0; j = 0; k =0;

	while(j< right && i<left) {
		if(L[i]  > R[j]) A[k++] = R[j++];
		else A[k++] = L[i++];
	}
	while(i < left) A[k++] = L[i++];
	while(j < right) A[k++] = R[j++];
}

void MergeSort(int *A,int n) {
	int mid,i, *L, *R;
	if(n < 2) return;

	mid = n/2;
	L = (int*)malloc(mid*sizeof(int)); 
	R = (int*)malloc((n- mid)*sizeof(int)); 
	
	for(i = 0;i<mid;i++) L[i] = A[i];
	for(i = mid;i<n;i++) R[i-mid] = A[i];

	MergeSort(L,mid);
	MergeSort(R,n-mid);
	Merge(A,L,mid,R,n-mid);
        free(L);
        free(R);
}


int main (){
int seq[max];
char n;
int i=0, decimal=0;
int j,nElem;

do{
	scanf("%c",&n);
	if(n!=' ' && n!='\n'){
		if(decimal ==1){
			i--;
			seq[i] = seq[i]*10+n-48;
			i++;
		}
		else{
			seq[i++] = n-48;
		}
		decimal=1;
	}
	else{
		decimal=0;
	}

} while (n!='\n');

nElem = i;
getchar();
MergeSort(seq,nElem);

for(j = 0;j < nElem;j++) 
	printf("%d ",seq[j]);

return 0;
}


