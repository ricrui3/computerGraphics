#include "stdio.h"
#include "stdlib.h"

void MatrixMult(int Vector[], int matrix[], int tamV);
#define NELEMS(x)  (sizeof(x) / sizeof(x[0]))

int main(){
	int i;
	int vectr[3] = {1,2,3};
	int matrix[9] = {1,2,3,4,5,6,7,8,9};
	MatrixMult(vectr, matrix, 3);
	int a = -vectr[1];
	printf("%d\n", a);
	for (i = 0; i < 3; ++i) printf("%d\n", vectr[i]);
}

void MatrixMult(int Vector[], int matrix[], int tamV){
	int i, j, k;
	int auxVector[tamV];

	for (i = 0; i < tamV; ++i) auxVector[i] = Vector[i];

	for (i = 0; i < tamV; ++i){
		Vector[i] = 0;
		k = i;
		for (j = 0; j < tamV; ++j){
			Vector[i] += auxVector[j] * matrix[k];
			k += tamV;
		}
	}
}