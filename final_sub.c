// C program to find Determinant of a matrix
#include <stdio.h>
#include<stdlib.h>

void getCofactor(float **mat, float **temp, int p, int q, int n)
{
	int i = 0, j = 0;
	for (int row = 0; row < n; row++)
	{
		for (int col = 0; col < n; col++) 
		{
			if (row != p && col != q) 
			{
				temp[i][j++] = mat[row][col];
				if (j == n - 1) 
				{
					j = 0;
					i++;
				}
			}
		}
	}
}

float determinantOfMatrix(float **mat, int n)
{
	float D = 0; 

	// Base case
	if (n == 1)
		return mat[0][0];

	// To store cofactors
	float **temp = (float**)malloc(n*sizeof(float*));
    for(int i=0; i<n; i++){
        temp[i] = (float*)malloc(n*sizeof(float));
    }

	int sign = 1; 

	for (int f = 0; f < n; f++) 
	{
		getCofactor(mat, temp, 0, f, n);
		D += sign * mat[0][f]* determinantOfMatrix(temp, n - 1);
		sign = -sign;
	}

	return D;
}

int main()
{
    int n;
    printf("Enter the order of the matrix:\n");
    scanf("%d", &n);
    float **mat = (float**)malloc(n*sizeof(float*));
    for(int i=0; i<n; i++){
        mat[i] = (float*)malloc(n*sizeof(float));
    }	
    printf("Enter the elements of the matrix:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%f", &mat[i][j]);
        }
    }
	// Function call
	printf("Determinant of the matrix is : %.4f",determinantOfMatrix(mat, n));
	return 0;
}
