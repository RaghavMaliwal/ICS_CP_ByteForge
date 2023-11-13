#include<stdio.h>

void print(int a[100][100],int n,int m){

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}

void sum_of_matrix(int matrix_1[100][100],int matrix_2[100][100],int n,int m){
int sum[100][100];
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
            sum[i][j]=matrix_1[i][j]+matrix_2[i][j]; 
        }
    }

print(sum,n,m);
}

void difference_of_matrix(int matrix_1[100][100],int matrix_2[100][100],int n,int m){
int difference[100][100];
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        
        difference[i][j]=matrix_1[i][j]-matrix_2[i][j];
        
    }
}
print(difference,n,m);
}

void scalar_multiplication_of_matrix(int matrix_1[100][100],int matrix_2[100][100],int n,int m){

int k;
scanf("%d",&k);

int scalar[100][100];
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        
    scalar[i][j]=k*matrix_1[i][j];
    
    }
}
print(scalar,n,m);
}

void multiplication_of_matrix(int matrix_1[100][100],int matrix_2[100][100],int n,int m){

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
}

void transpose_of_matrix(int matrix_1[100][100],int n,int m){

int transpose[100][100];
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        
        transpose[i][j]=matrix_1[j][i];
        
    }
}
print(transpose,n,m); 
}  
    


int main() {

int n,m;
scanf("%d%d",&n,&m);

int matrix_1[100][100];
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        
        scanf("%d",&matrix_1);
    }
}

int matrix_2[100][100];
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        
        scanf("%d",&matrix_2);
    }
}

return 0;
}
