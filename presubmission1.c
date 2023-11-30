#include<stdio.h>
#include<stdlib.h>
int ctrl;
//for controlling flow
float **matrix_1;
//for keeping data
int row, column;
//for keeping data abt matrix 1

//FUNCTIONS List

void print(float **a,int n,int m);
void sum_of_matrix(int n, int m,float **matrix_2);
void difference_of_matrix(int n, int m,float **matrix_2);
void scalar_multiplication_of_matrix(int n, int m,float k);
void PRE_multiplication_of_matrix(int n,int m,int k,int l,float**matrix_2);
void POST_multiplication_of_matrix(int n, int m,int k,int l,float **matrix_2);
void transpose_of_matrix(int n, int m);
float cofactor_of_a_element(int n);
void get_Cofactor(float **mat, float **temp, int p, int q, int n);
float determinant_of_matrix(float **mat, int n);
void adjoint_of_matrix(float **mat, int n);
void inverse_of_matrix(int n);
int input(int choice,int n,int m);

//FUNCTION LIST END 


void print(float **a,int n,int m)
{

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%.4f ",a[i][j]);
        }
        printf("\n");
    }
    printf(" Do you want to perform another operation on this matrix?\n IF YES:ENTER 'Y' ELSE 'N' ");
    char confirmation_specifier;
    scanf(" %c",&confirmation_specifier);
    
    if(confirmation_specifier=='Y'||confirmation_specifier=='y')
    {
        //now we already have a matrix i.e. matrix 1 and hence ctrl=0
        ctrl=0;
        //changing size of matrix_1 to store a
        matrix_1=(float**)realloc(matrix_1,n*sizeof(float*));
        for(int k=0;k<n;k++)
        {
            matrix_1[k]=(float*)realloc(matrix_1,m*sizeof(float));
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                matrix_1[i][j]=a[i][j];
            }
        }
        row=n;
        column=m;
    }
    else 
    {//need another matrix and operation so ctrl=1
        ctrl=1;
        
    }
    return;
}

//sum
void sum_of_matrix(int n, int m,float **matrix_2)
{

float **sum=(float**)malloc(n*sizeof(float*));
for(int k=0;k<n;k++){
    sum[k]=(float*)malloc(m*sizeof(float));
}

for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
            sum[i][j]=matrix_1[i][j]+matrix_2[i][j]; 
        }
    }

print(sum,n,m);
free(sum);
}

//difference
void difference_of_matrix(int n, int m,float **matrix_2)
{

float **difference=(float**)malloc(n*sizeof(float*));
for(int k=0;k<n;k++)
    difference[k]=(float*)malloc(m*sizeof(float));
    
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        
        difference[i][j]=matrix_1[i][j]-matrix_2[i][j];
        
    }
}
print(difference,n,m);
free(difference);
}

//scalar multiplication
void scalar_multiplication_of_matrix(int n, int m,float k)
{
    float **scalar=(float**)malloc(n*sizeof(float*));
    for(int k=0;k<n;k++)
    scalar[k]=(float*)malloc(m*sizeof(float));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scalar[i][j]=k*matrix_1[i][j];
        }
    }
    print(scalar,n,m);
    free(scalar);
}

//pre mult
void PRE_multiplication_of_matrix(int n,int m,int k,int l,float**matrix_2)
{
    float **product=(float**)malloc(k*sizeof(float));
    for(int x=0;x<k;x++)
    product[k]=(float*)malloc(m*sizeof(float));
    
    for(int x=0;x<k;x++)
    {
        for(int y=0;y<m;y++)
        {
            float temp=0;
            for(int z=0;z<l;z++)
            {
                temp+=matrix_1[x][z]*matrix_2[z][y];
            }
            product[x][y]=temp;
        }
    }
    print(product,k,m);
    free(product);
}

//post mult
void POST_multiplication_of_matrix(int n, int m,int k,int l,float **matrix_2)
{
    float **product=(float**)malloc(n*sizeof(float));
    for(int x=0;x<k;x++)
    product[k]=(float*)malloc(l*sizeof(float));
    
    for(int x=0;x<n;x++)
    {
        for(int y=0;y<l;y++)
        {
            float temp=0;
            for(int z=0;z<m;z++)
            {
                temp+=matrix_2[x][z]*matrix_1[z][y];
            }
            product[x][y]=temp;
        }
    }
    print(product,n,l);
    free(product);
}

//transpose
void transpose_of_matrix(int n, int m)
{

float **transpose=(float**)malloc(n*sizeof(float*));
for(int k=0;k<n;k++)
    transpose[k]=(float*)malloc(m*sizeof(float));

for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        
        transpose[i][j]=matrix_1[j][i];
        
    }
}
print(transpose,n,m); 
free(transpose);
}

//cofactor matrix
float cofactor_of_a_element(int n)
{

     float **cofactor=(float**)malloc(n*sizeof(float*));
    for(int i=0;i<n;i++)
        cofactor[i]=(float*)malloc(n*sizeof(float));

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
    float C=determinant_of_matrix(cofactor,n-1);
    free(cofactor);
    ctrl=1;
    //just as determinant you can't do anything with a number so user has to input new matrix
    return C;
}

//cofactor
void get_Cofactor(float **mat, float **temp, int p, int q, int n)
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

//determinant
float determinant_of_matrix(float **mat, int n)
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
		get_Cofactor(mat, temp, 0, f, n);
		D += sign * mat[0][f]
			* determinant_of_matrix(temp, n - 1);
		sign = -sign;
	}
	
	ctrl=1;
	//because determinant isn't a matrix and you cannot use it further
	return D;
}

//adjoint
void adjoint_of_matrix(float **mat, int n) 
{

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
            get_Cofactor(mat, temp, i, j, n);
            sign = ((i + j) % 2 == 0) ? 1 : -1;
            adjoint[j][i] = sign * determinant_of_matrix(temp, n - 1);
        }
    }
    

    print(adjoint,n,n);
    free(adjoint);
    free(temp);
}

//inverse
void inverse_of_matrix(int n)
{
    float **inv = (float**)malloc(n*sizeof(float*));
    for(int i=0; i<n; i++)
    {
        inv[i] = (float*)malloc(n*sizeof(float));
    }
    float **temp = (float**)malloc(n*sizeof(float*));
    for(int i=0; i<n; i++){
        temp[i] = (float*)malloc(n*sizeof(float));
    }
    
    
    int sign=1;
    float k=determinant_of_matrix(matrix_1, n);
    if(k == 0)
    {
        printf("Given Matrix is NOT INVERTIBLE\n");
        return;
    }
    
    else
    {
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                get_Cofactor(matrix_1, temp, i, j, n);
                sign = ((i + j) % 2 == 0) ? 1 : -1;
                inv[j][i] = (sign * determinant_of_matrix(temp, n - 1))/k;
            }
        }
        
    }
    print(inv,n,n);
    free(inv);
    free(temp);
}

//input
int input(int choice,int n,int m)
{
    switch(choice)
    {
        case 1 : 
        {
              printf("Do you want sum_of_matrix\nIF YES:ENTER 'Y' ELSE 'N' ");
              char confirmation_specifier;
              scanf(" %c",&confirmation_specifier);
              
              if(confirmation_specifier == 'Y'||confirmation_specifier == 'y')
              {
                  //initialize matrix 2
                  float **matrix_2=(float**)malloc(n*sizeof(float*));
                  for(int i=0;i<n;i++)
                  {
                      matrix_2[i]=(float*)malloc(m*sizeof(float));
                  }
                  
                  printf("\nENTER MATRIX_2 :\n");
                  for(int i=0;i<n;i++)
                  {
                      for(int j=0;j<m;j++)
                      {
                        scanf("%f",&matrix_2[i][j]);
                      }
                  }
                  
                  sum_of_matrix(n,m,matrix_2);
              }
              else
              {
                  return 0;
              }

             break;
 
        }
                 
        case 2 : 
        {
            printf("Do you want difference_of_matrix\n IF YES:ENTER 'Y' ELSE 'N' ");
            char confirmation_specifier;
            scanf(" %c",&confirmation_specifier);
            
            if(confirmation_specifier == 'Y'||confirmation_specifier == 'y')
            {
                float **matrix_2=(float**)malloc(n*sizeof(float*));
                for(int i=0;i<n;i++)
                {
                  matrix_2[i]=(float*)malloc(m*sizeof(float));
                }
                
                printf("\nENTER MATRIX_2 :\n");
                for(int i=0;i<n;i++)
                {
                  for(int j=0;j<m;j++)
                  {
                      
                      scanf("%f",&matrix_2[i][j]);
                  }
                }
                difference_of_matrix(n,m,matrix_2);
                
            }
            
            else{
                return 0;
            }
        }
        break;
        
        case 3 :
        {
            printf("Do you want PreMultiplication_of_matrix\n IF YES:ENTER 'Y' ELSE 'N' ");
            char confirmation_specifier;
            scanf(" %c",&confirmation_specifier);
            
            if(confirmation_specifier == 'Y'||confirmation_specifier == 'y')
            {
              float **matrix_2=(float**)malloc(n*sizeof(float*));
              for(int i=0;i<n;i++)
              {
                  matrix_2[i]=(float*)malloc(m*sizeof(float));
              }
              
              printf("Enter number of rows of 2nd matrix :\n");
              int k,l=n;
              scanf("%d",&k);
              
              printf("\nENTER MATRIX_2 :\n");
              for(int i=0;i<k;i++)
              {
                  for(int j=0;j<l;j++){
                      
                      scanf("%f",&matrix_2[i][j]);
                  }
              }
                PRE_multiplication_of_matrix(n,m,k,l,matrix_2);
                
            }
            else{
                return 0;
            } 
        }
        break;
        
        case 4 :
        {
            printf("Do you want PostMultiplication_of_matrix\n IF YES:ENTER 'Y' ELSE 'N' ");
            char confirmation_specifier;
            scanf(" %c",&confirmation_specifier);

            if(confirmation_specifier == 'Y'||confirmation_specifier == 'y')
            {
                float **matrix_2=(float**)malloc(n*sizeof(float*));
                for(int i=0;i<n;i++)
                  {
                      matrix_2[i]=(float*)malloc(m*sizeof(float));
                  }
                  printf("Enter number of columns of 2nd matrix :\n");
                  int k=m,l;
                  scanf("%d",&l);
                  
                  printf("\nENTER MATRIX_2 :\n");
                  for(int i=0;i<k;i++)
                  {
                      for(int j=0;j<l;j++)
                      {
                          scanf("%f",&matrix_2[i][j]);
                      }
                  }
                POST_multiplication_of_matrix(n,m,k,l,matrix_2);
            }
            
            else{
                return 0;
            }
        }
        break;
        
        case 5 :
        {
            printf("Do you want scalar_multiplication_of_matrix\n IF YES:ENTER 'Y' ELSE 'N' ");
            char confirmation_specifier;
            scanf(" %c",&confirmation_specifier);
            
            if(confirmation_specifier == 'Y'||confirmation_specifier == 'y')
            {
                printf("Enter scalar multiplier: ");
                float k;
                scanf("%f",&k);
                scalar_multiplication_of_matrix(n,m,k);
            }
            
            else{
                return 0;
            }
        }
        break;
        
        case 6 :
        {
            printf("Do you want transpose_of_matrix\n IF YES:ENTER 'Y' ELSE 'N' ");
            char confirmation_specifier;
            scanf(" %c",&confirmation_specifier);
            
            if(confirmation_specifier == 'Y'||confirmation_specifier == 'y')
            {
                transpose_of_matrix(n,m);
            }
            else{
                return 0;
            }
        }
        break;
        
        case 7 :
        {
            printf("Do you want cofactor_of_matrix\n IF YES:ENTER 'Y' ELSE 'N' ");
            char confirmation_specifier;
            scanf(" %c",&confirmation_specifier);
            if(confirmation_specifier == 'Y'||confirmation_specifier == 'y')
            {
                if(n!=m)
                {
                    printf("Operation incompatible\n");
                    return 0;
                }
                printf("%.4f",cofactor_of_a_element(n));
            }
            else{
                return 0;
            }
        }
        break;

        case 8 :
        {   
            printf("Do you want determinant_of_matrix\n IF YES:ENTER 'Y' ELSE 'N' ");
            char confirmation_specifier;
            scanf(" %c",&confirmation_specifier);
            if(confirmation_specifier == 'Y'||confirmation_specifier == 'y')
            {
                if(n!=m)
                {
                    printf("Operation incompatible\n");
                    return 0;
                }
                printf("%.4f",determinant_of_matrix(matrix_1,n));
            }

            else{
                return 0;
            }
        }
        break;
        
        case 9 :
        {
            printf("Do you want adjoint_of_matrix\n IF YES:ENTER 'Y' ELSE 'N' ");
            char confirmation_specifier;
            scanf(" %c",&confirmation_specifier);
            if(confirmation_specifier == 'Y'||confirmation_specifier == 'y')
            {
                if(n!=m)
                {
                    printf("Operation incompatible\n");
                    return 0;
                }
                adjoint_of_matrix(matrix_1,n);
            }
            else{
                return 0;
            }
        }
        break;
        
        case 10 :
        {
            printf("Do you want inverse_of_matrix\n IF YES:ENTER 'Y' ELSE 'N' ");
            char confirmation_specifier;
            scanf(" %c",&confirmation_specifier);
            if(confirmation_specifier == 'Y'||confirmation_specifier == 'y')
            {
                if(n!=m)
                {
                    printf("Operation incompatible\n");
                    return 0;
                }
                inverse_of_matrix(n);
                break;
            }

            else{
                return 0;
            }
        }
        break;
        
        default:
        {
            printf("Please enter valid choice\n");
        }
        break;
    }
    return 0;
}

//main
int main() 
{

printf("\n                                   WELCOME TO THE MATRIX \n");
printf("                              A project made by ADITYA,KRISH,RAGHAV,SOHOM\n");


    printf("\nExit                 : 0\nSum                  : 1\nDifference           : 2\nPreMultiplication    : 3\nPostMultiplication   : 4\nScalar Multipication : 5\nTranspose            : 6\nCofactor             : 7\nDeterminant          : 8\nAdjoint              : 9\nInverse              : 10\n");
    int input_specifier;
    ctrl=1;
    printf("\nENTER CHOICE OF OPERATION: ");
    scanf("%d",&input_specifier);
    
    while(input_specifier!=0)
    {
        if(ctrl==1)
        {
                printf("\nENTER NUMBER OF ROWS AND COLUMNS :\n");
                scanf("%d%d",&row,&column);
                printf("Enter %d X %d Matrix\n",row,column);
                matrix_1=(float**)malloc(row*sizeof(float*));
                for(int i=0;i<row;i++)
                {
                  matrix_1[i]=(float*)malloc(column*sizeof(float));
                }
                
                for(int i=0;i<row;i++){
                  for(int j=0;j<column;j++){
                      
                      scanf("%f",&matrix_1[i][j]);
                  }
              }
                input(input_specifier,row,column);
        }
        else 
        {
            printf("\nENTER CHOICE OF OPERATION: ");
            scanf("%d",&input_specifier);
            input(input_specifier,row,column);
        
        }
    }
    free(matrix_1);
    printf("Thank you for using our Matrix Calculator");

return 0;
}