#include<stdio.h>
#include<stdlib.h>
#define size 20

void print(int **a,int n,int m){

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}

void sum_of_matrix(int n, int m,int **matrix_1,int **matrix_2){

int **sum=(int)malloc(n*sizeof(int));
for(int k=0;k<n;k++){
    sum[k]=(int*)malloc(m*sizeof(int));
}

for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
            sum[i][j]=matrix_1[i][j]+matrix_2[i][j]; 
        }
    }

print(sum,n,m);
}

void difference_of_matrix(int n, int m,int **matrix_1,int **matrix_2){

int **difference=(int)malloc(n*sizeof(int));
for(int k=0;k<n;k++)
    difference[k]=(int*)malloc(m*sizeof(int));
    
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        
        difference[i][j]=matrix_1[i][j]-matrix_2[i][j];
        
    }
}
print(difference,n,m);
}

void scalar_multiplication_of_matrix(int n, int m,int **matrix_1){

int k;
scanf("%d",&k);

int **scalar=(int)malloc(n*sizeof(int));
for(int k=0;k<n;k++)
    scalar[k]=(int*)malloc(m*sizeof(int));
    
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        
    scalar[i][j]=k*matrix_1[i][j];
    
    }
}
print(scalar,n,m);
}

void PRE_multiplication_of_matrix(int n, int m,int **matrix_1,int **matrix_2){

int **product=(int)malloc(n*sizeof(int));
for(int k=0;k<n;k++)
    product[k]=(int*)malloc(m*sizeof(int));

for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        int z=0;
        for(int k=0;k<n;k++){
        z=z+matrix_2[i][k]*matrix_1[k][j];
    }
        product[i][j]=z;
    }
}

void POST_multiplication_of_matrix(int n, int m,int **matrix_1,int **matrix_2){

int **product=(int)malloc(n*sizeof(int));
for(int k=0;k<n;k++)
    product[k]=(int*)malloc(m*sizeof(int));

for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        int z=0;
        for(int k=0;k<n;k++){
        z=z+matrix_1[i][k]*matrix_2[k][j];
    }
        product[i][j]=z;
    }
}

print(product,n,m);
}

void transpose_of_a_matrix(int n, int m,int **matrix_1){

int **transpose=(int)malloc(n*sizeof(int));
for(int k=0;k<n;k++)
    transpose[k]=(int*)malloc(m*sizeof(int));

for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        
        transpose[i][j]=matrix_1[j][i];
        
    }
}
print(transpose,n,m); 
}
void cofactor_of_a_element(int n,int **matrix_1){

     int **cofactor=(int)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        cofactor[i]=(int*)malloc(n*sizeof(int));

    printf("enter the element you want a cofactor matrix of\n");
    int p,q;
    scanf("%d %d",&p,&q);
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if((j!=q)&&(i!=p)){
                if((i<p)&&(j<q))
                {
                    cofactor[i][j]=matrix_1[i][j];
                    //printf("B[%d][%d]=A[%d][%d] i.e. %d\n",i,j,i,j,A[i][j]);
                }
                else if((i<p)&&(j>q))
                {
                    cofactor[i][j-1]=matrix_1[i][j];
                    // printf("B[%d][%d]=A[%d][%d] i.e. %d\n",i,j-1,i,j,A[i][j]);
                }
                else if((i>p)&&(j<q))
                {
                    cofactor[i-1][j]=matrix_1[i][j];
                    //printf("B[%d][%d]=A[%d][%d] i.e. %d\n",i-1,j,i,j,A[i][j]);
                }
                else if((i>p)&&(j>q)) 
                {
                    cofactor[i-1][j-1]=matrix_1[i][j];
                 //printf("B[%d][%d]=A[%d][%d] i.e. %d\n",i-1,j-1,i,j,A[i][j]);
                }
            }
            
        }
    }

    printf("Cofactor of the given element is : %d",determinant_of_a_matrix(cofactor,n-1));
}

void get_Cofactor(float **mat, float **temp, int p, int q, int n){
	
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

float determinant_of_Matrix(float **matrix_1, int n)
{
	float D = 0; 
    
	// Base case
	if (n == 1)
		return matrix_1[0][0];

	// To store cofactors
	float **temp = (float**)malloc(n*sizeof(float*));
    for(int i=0; i<n; i++){
        temp[i] = (float*)malloc(n*sizeof(float));
    }

	int sign = 1; 
	for (int f = 0; f < n; f++) 
	{
		get_Cofactor(matrix_1, temp, 0, f, n);
		D += sign * matrix_1[0][f]
			* determinantOfMatrix(temp, n - 1);
		sign = -sign;
	}

	return D;
}


void adjoint_of_a_matrix(int **matrix_1, int n) {

    float **adjoint = (float**)malloc(n*sizeof(float*));
    for(int i=0; i<n; i++){
        adjoint[i] = (float*)malloc(n*sizeof(float));
    }
    
    if (n == 1) {
        adjoint[0][0] = 1.0;
        return;
    }
    int sign = 1;
    float **temp = (float**)malloc(n*sizeof(float*));
    for(int i=0; i<n; i++){
        temp[i] = (float*)malloc(n*sizeof(float));
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            get_Cofactor(matrix_1, temp, i, j, n);
            sign = ((i + j) % 2 == 0) ? 1 : -1;
            adjoint[j][i] = sign * determinant(temp, n - 1);
        }
    }

    print(adjoint,n,m);
}

void inverse_of_a_matrix(int matrix1[size][size],float adj[size][size],int n){
    
int k=determinant_of_a_matrix(matrix1, n);
   
if(k == 0){
        printf("Given Matrix is NOT INVERTIBLE");
    }
else{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.4f ", (adj[i][j])/k);
        }
        printf("\n");
    }
}
}

int main() {

int n,m;
scanf("%d%d",&n,&m);


int **matrix_1=(int)malloc(n*sizeof(int));
for(int i=0;i<n;i++)
    matrix_1[i]=(int*)malloc(m*sizeof(int));

for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        
        scanf("%d",&matrix_1[i][j]);
    }
}


int **matrix_2=(int)malloc(n*sizeof(int));
for(int i=0;i<n;i++)
    matrix_2[i]=(int*)malloc(m*sizeof(int));
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        
        scanf("%d",&matrix_2[i][j]);
    }
}

return 0;
}
