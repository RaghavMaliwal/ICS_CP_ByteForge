#include<stdio.h>
#include<stdlib.h>

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

void scalar_multiplication_of_matrix(int n, int m,int **matrix_1,int **matrix_2){

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

void multiplication_of_matrix(int n, int m,int **matrix_1,int **matrix_2){

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

void transpose_of_matrix(int n, int m,int **matrix_1){

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
void cofact(int n,int **matrix_1){

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
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            printf("%d ",cofactor[i][j]);
        }
        printf("\n");
    }
}

#include<stdio.h>
#include<math.h>
/*******
Function that calculates the determinant of a square matrix using Gauss-Elimination :
Pass the square matrix as a parameter, and calculate and return the dete
Parameters: order(n),matrix[n][n]
********/
/*double determinant(int n, double a[n][n]){
    double det=1;
    int i;
    int swapCount=gaussElimination(n,n,a);
    for(i=0;i<n;i++){
        det =det*a[i][i];
    }
    return det*pow(-1,swapCount);
}
/********
Function that perform Gauss Elimination
Pass the square matrix as a parameter, and calculate and store the upperTriangular(Gauss-Eliminated Matrix) in it
Parameters: rows(m),columns(n),matrix[m][n]
********/
/*int gaussElimination(int m, int n, double a[m][n]){
    int i,j,k;
    int swapCount=0;
    for(i=0;i<m-1;i++){
        //Partial Pivoting
        for(k=i+1;k<m;k++){
            //If diagonal element(absolute vallue) is smaller than any of the terms below it
            if(fabs(a[i][i])<fabs(a[k][i])){
                //Swap the rows
                swapCount++;
                for(j=0;j<n;j++){                
                    double temp;
                    temp=a[i][j];
                    a[i][j]=a[k][j];
                    a[k][j]=temp;
                }
            }
        }
        //Begin Gauss Elimination
        for(k=i+1;k<m;k++){
            double  term=a[k][i]/ a[i][i];
            for(j=0;j<n;j++){
                a[k][j]=a[k][j]-term*a[i][j];
            }
        }
    }
    return swapCount;       
}
/*******
Function that reads the elements of a matrix row-wise
Parameters: rows(m),columns(n),matrix[m][n] 
*******/
/*void readMatrix(int m, int n, double matrix[m][n]){
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%lf",&matrix[i][j]);
        }
    } 
}
/*******
Function that prints the elements of a matrix row-wise
Parameters: rows(m),columns(n),matrix[m][n] 
*******/
/*void printMatrix(int m, int n, double matrix[m][n]){
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%lf\t",matrix[i][j]);
        }
        printf("\n");
    } 
}
/*******
Function that copies the elements of a matrix to another matrix
Parameters: rows(m),columns(n),matrix1[m][n] , matrix2[m][n]
*******/
/*void copyMatrix(int m, int n, double matrix1[m][n], double matrix2[m][n]){
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            matrix2[i][j]=matrix1[i][j];
        }
    } 
}
 
int main(){
    int n,i,j;
    printf("Enter the order of the matrix:\n(No. of rows/columns (n))\n");
    scanf("%d",&n);
    //Declare a matrix to store the user given matrix
    double a[n][n];
    printf("\nEnter the elements of matrix:\n");
    readMatrix(n,n,a); 
    printf("\nThe determinant using Gauss Eliminiation is:\n\n%lf\n",determinant(n,a));
     
}*/

/*#include <stdio.h>
#define size 20
void show_matrix(int adj[size][size], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}
int determinant(int mat[size][size], int n) {
    int det = 0;
    if (n == 1) {
        return mat[0][0];
    }
    int temp[size][size];
    int sign = 1;
    for (int f = 0; f < n; f++) {
        getCofactor(mat, temp, 0, f, n);
        det += sign * mat[0][f] * determinant(temp, n - 1);
        sign = -sign;
    }
    return det;
}
void getCofactor(int mat[size][size], int temp[size][size], int p, int q, int n) {
    int i = 0, j = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (row != p && col != q) {
                temp[i][j++] = mat[row][col];

                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}
void adjoint(int mat[size][size], int adj[size][size], int n) {
    if (n == 1) {
        adj[0][0] = 1;
        return;
    }
    int sign = 1;
    int temp[size][size];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            getCofactor(mat, temp, i, j, n);
            sign = ((i + j) % 2 == 0) ? 1 : -1;
            adj[j][i] = sign * determinant(temp, n - 1);
        }
    }
}
int main() {
    int n;
    printf("Order of the matrix\nEnter the no of rows/columns(n) : ");
    scanf("%d",&n);
    printf("Enter the elements of the matrix:\n");
    int mat[size][size];
    int p1=0,p2;
    while( p1 < n) {
        for (p2=0; p2 < n; p2++) {
            scanf("%d", &mat[p1][p2]);
        }
    p1++;
    }
    printf("\nInput matrix:\n");
    int adj[size][size];
    show_matrix(mat, n);
    printf("\nAdjoint matrix:\n");
    adjoint(mat, adj, n);
    show_matrix(adj, n);
    return 0;
}*/

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

sum_of_matrix(n,m,matrix_1,matrix_2);
difference_of_matrix(n,m,matrix_1,matrix_2);


return 0;
}