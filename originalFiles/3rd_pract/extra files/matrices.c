#include "stdio.h"
#include "stdlib.h"

void MatrixMult(int Vector[], int matrix[4][4]){
	int i,j;
	int auxVector[4];

	for (i = 0; i < 4; ++i)
	{
		auxVector[i] = Vector[i];
		printf("%d", auxVector[i]);
	}

	printf("\n");

	for (i = 0; i < 4; ++i)
	{
		Vector[i] = 0;
		for (j = 0; j < 4; ++j)
		{
			printf("%d ", auxVector[j]*matrix[i][j]);
			Vector[i] += auxVector[j] * matrix[i][j];
		}
		printf("\n");
	}
}

int main()
{
	int i;
	int A[4] = {1,2,3,4};
	int B[4][4] = {{1,2,3,4} ,{5,6,7,8} ,{9,10,11,12} ,{13,14,15,16}};

	MatrixMult(A,B);

	for (i = 0; i < 4; ++i)
	{
		printf("%d \n", A[i]);
	}

	return 0;
}