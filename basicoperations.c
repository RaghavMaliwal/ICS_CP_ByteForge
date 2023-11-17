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

int **sum=(int**)malloc(n*sizeof(int*));
for(int i=0;i<n;i++)
    sum[i]=(int*)malloc(m*sizeof(int));

for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
            sum[i][j]=matrix_1[i][j]+matrix_2[i][j]; 
        }
    }

print(sum,n,m);
}

/*void difference_of_matrix(int matrix_1[100][100],int matrix_2[100][100],int n,int m){
int difference[100][100];
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        
        difference[i][j]=matrix_1[i][j]-matrix_2[i][j];
        
    }
}
print(difference,n,m);
}*/

/*void scalar_multiplication_of_matrix(int matrix_1[100][100],int matrix_2[100][100],int n,int m){

int k;
scanf("%d",&k);

int scalar[100][100];
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        
    scalar[i][j]=k*matrix_1[i][j];
    
    }
}
print(scalar,n,m);
}*/

/*void multiplication_of_matrix(int matrix_1[100][100],int matrix_2[100][100],int n,int m){

int product[100][100]; 
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
}*/

/*void transpose_of_matrix(int matrix_1[100][100],int n,int m){

int transpose[100][100];
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        
        transpose[i][j]=matrix_1[j][i];
        
    }
}
print(transpose,n,m); 
}*/

/*void cofactor_of_a_matrix() 
{
    
    printf("Enter rows and columns\n");
    int r;
    scanf("%d",&r);
    int A[r][r],B[r-1][r-1];
    printf("Enter matrix\n");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<r;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
    printf("matrice is\n");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<r;j++)
        {
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
    printf("enter the element you want a cofactor matrix of\n");
    int p,q;
    
    scanf("%d %d",&p,&q);
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<r;j++)
        {
            if((j!=q)&&(i!=p)){
                if((i<p)&&(j<q))
                {
                    B[i][j]=A[i][j];
                    printf("B[%d][%d]=A[%d][%d] i.e. %d\n",i,j,i,j,A[i][j]);
                }
                else if((i<p)&&(j>q))
                {
                    B[i][j-1]=A[i][j];
                     printf("B[%d][%d]=A[%d][%d] i.e. %d\n",i,j-1,i,j,A[i][j]);
                }
                else if((i>p)&&(j<q))
                {
                    B[i-1][j]=A[i][j];
                    printf("B[%d][%d]=A[%d][%d] i.e. %d\n",i-1,j,i,j,A[i][j]);
                }
                else if((i>p)&&(j>q)) 
                {
                 B[i-1][j-1]=A[i][j];
                 printf("B[%d][%d]=A[%d][%d] i.e. %d\n",i-1,j-1,i,j,A[i][j]);
                }
            }
            
        }
    }
    for(int i=0;i<r-1;i++)
    {
        for(int j=0;j<r-1;j++)
        {
            printf("%d ",B[i][j]);
        }
        printf("\n");
    }
    
} */   


int main() {

int n,m;
scanf("%d%d",&n,&m);


int **matrix_1=(int**)malloc(n*sizeof(int*));
for(int i=0;i<n;i++)
    matrix_1[i]=(int*)malloc(m*sizeof(int));

for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        
        scanf("%d",&matrix_1);
    }
}


int **matrix_2=(int**)malloc(n*sizeof(int*));
for(int i=0;i<n;i++)
    matrix_2[i]=(int*)malloc(m*sizeof(int));
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        
        scanf("%d",&matrix_2);
    }
}

sum_of_matrix(n,m,matrix_1,matrix_2);

return 0;
}
