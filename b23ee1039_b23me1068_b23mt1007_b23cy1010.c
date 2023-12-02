#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int ctrl;
//for controlling flow 
//1 when all inputs are needed and 0 when some matrix from the result is being used
float **matrix_1;
//for keeping data
int row, column;
//for keeping data about matrix 1

//FUNCTIONS List

void print(float **a,int n,int m);
void post_result_op(float**result,int n,int m);
void sum_of_matrix(int n, int m,float **matrix_2);
void difference_of_matrix(int n, int m,float **matrix_2);
void scalar_multiplication_of_matrix(int n, int m,float k);
void PRE_multiplication_of_matrix(int n,int m,int k,int l,float**matrix_2);
void POST_multiplication_of_matrix(int n, int m,int k,int l,float **matrix_2);
void transpose_of_matrix(int n, int m);
float cofactor_of_a_element(int p, int q,int n);
void get_Cofactor(float **mat, float **temp, int p, int q, int n);
float determinant_of_matrix(float **mat, int n);
void adjoint_of_matrix(float **mat, int n);
void inverse_of_matrix(int n);
int input(int choice,int n,int m);
void menu();

//FUNCTION LIST END 

//Print function
void print(float **result,int n,int m)
{
    //Printing function
    printf("\nResult =>\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%.1f ",result[i][j]);
        }
        printf("\n");
    }
    
    //Calling function to intitiate reusability of answer
    post_result_op(result,n,m);
    return;
}

//post_result_op
void post_result_op(float**result,int n,int m)
{
    //Asking the user
    printf("\nDo you want to perform another operation on this matrix?\nIf Yes: Enter 'Y'  Else: Enter 'N' => ");
    char confirmation_specifier;
    scanf(" %c",&confirmation_specifier);
    
    //Y means the user re uses the resultant matrix
    if(confirmation_specifier=='Y'||confirmation_specifier=='y')
    {
        //now we already have a matrix i.e. matrix_1 that needs to be operated on and hence ctrl=0
        ctrl=0;
        //changing size of matrix_1 to store resultant matrix
        matrix_1=(float**)realloc(matrix_1,n*sizeof(float*));
        for(int k=0;k<n;k++)
        {
            matrix_1[k]=(float*)realloc(matrix_1,m*sizeof(float));
        }
        memcpy( matrix_1, result, n * m * sizeof(float) );

        row=n;
        column=m;
    }
    else 
    {//Enter another matrix and operation so ctrl=1
        ctrl=1;
        system("cls");
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
    for(int j=0;j<m;j++)
    {
            //Elements of the sum matrix are sum of repsective elements of input matrices
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
        //Elements of the difference matrix are difference of repsective elements of input matrices
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
            //Elements of the resultant matrix are product of repsective elements of input matrix with scalar multiple
            scalar[i][j]=k*matrix_1[i][j];
        }
    }
    print(scalar,n,m);
    free(scalar);
}

//pre mult
//matrix_2*matrix_1
void PRE_multiplication_of_matrix(int n,int m,int k,int l,float**matrix_2)
{
    
    float **product=(float**)malloc(k*sizeof(float));
    for(int x=0;x<k;x++)
    product[x]=(float*)malloc(m*sizeof(float));
    
    for(int x=0;x<k;x++)
    {
        for(int y=0;y<m;y++)
        {
            float temp=0;
            for(int z=0;z<l;z++)
            {
                //storing sum of products in a temporary variable which is finally assigned to respective element of product matrix
                temp+=matrix_2[x][z]*matrix_1[z][y];
            }
            product[x][y]=temp;
        }
    }
    print(product,k,m);
    free(product);
}

//post mult
//matrix_1*matrix_2
void POST_multiplication_of_matrix(int n, int m,int k,int l,float **matrix_2)
{
    float **product=(float**)malloc(n*sizeof(float));
    for(int x=0;x<k;x++)
    product[x]=(float*)malloc(l*sizeof(float));
    
   
    for (int x = 0; x < n; x++)
{
    for (int y = 0; y < l; y++)
    {
        float temp = 0;
        for (int z = 0; z < m; z++)
        {//storing sum of products in a temporary variable which is finally assigned to respective element of product matrix
            temp += matrix_1[x][z] * matrix_2[z][y];
        }
        product[x][y] = temp;
        
    }
    
}

    print(product,n,l);
    free(product);
}

//transpose
void transpose_of_matrix(int n, int m)
{
    float **transpose = (float **)malloc(m * sizeof(float *));
    for (int k = 0; k < m; k++)
        transpose[k] = (float *)malloc(n * sizeof(float));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            //i,j th lement = j,i th element
            transpose[i][j] = matrix_1[j][i];
        }
    }

    print(transpose, m, n);
    free(transpose);
}


//cofactor matrix
float cofactor_of_a_element(int p,int q,int n)
{

     float **cofactor=(float**)malloc(n*sizeof(float*));
    for(int i=0;i<n;i++)
        cofactor[i]=(float*)malloc(n*sizeof(float));

    
    
    


    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if((j!=q)&&(i!=p)){
                //inputting cofactor elements
                if((i<p)&&(j<q))
                {
                    cofactor[i][j]=matrix_1[i][j];
                    
                }
                else if((i<p)&&(j>q))
                {
                    cofactor[i][j-1]=matrix_1[i][j];
                    
                }
                else if((i>p)&&(j<q))
                {
                    cofactor[i-1][j]=matrix_1[i][j];
                    
                }
                else if((i>p)&&(j>q)) 
                {
                    cofactor[i-1][j-1]=matrix_1[i][j];
                 
                }
            }
            
        }
    }
    float C=determinant_of_matrix(cofactor,n-1);
    free(cofactor);
    ctrl=1;
    //just as determinant you can't do anything with a number so user has to input new matrix
    return (C*pow(-1,(p+q)));
    }
    


//cofactor
//Internal fuunction. Not directly called by user
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
    //base case
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
    //determinant function re used
    float k=determinant_of_matrix(matrix_1, n);
    if(k == 0)
    {
        system("cls");
        printf("Given Matrix is NOT INVERTIBLE\n\n");
        ctrl=1;
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
//contains switch cases, initializes respective inputs as per the required operation
//Confirms the choice and calls the respective function otherwise the system clears out while ctrl internally becomes 1 and the whole process starts over
int input(int choice,int n,int m)
{
    switch(choice)
    {
        case 0:
        {
            system("cls");
            break;
        }
        case 1 : 
        {
              printf("\nDo you want sum_of_matrix\nIf Yes: Enter 'Y'  Else: Enter 'N' =>");
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
                  
                  printf("\nEnter Matrix_2 (same order):\n");
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
                    ctrl=1;
                    system("cls");
                  return 0;
              }

             break;
 
        }
                 
        case 2 : 
        {
            printf("\nDo you want difference_of_matrix\nIf Yes: Enter 'Y'  Else: Enter 'N' => ");
            char confirmation_specifier;
            scanf(" %c",&confirmation_specifier);
            
            if(confirmation_specifier == 'Y'||confirmation_specifier == 'y')
            {
                float **matrix_2=(float**)malloc(n*sizeof(float*));
                for(int i=0;i<n;i++)
                {
                  matrix_2[i]=(float*)malloc(m*sizeof(float));
                }
                
                printf("\nEnter Matrix_2 (same order):\n");
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
                ctrl=1;
                system("cls");
                return 0;
            }
        }
        break;
        
        case 3 :
        {
            printf("\nDo you want PreMultiplication_of_matrix\nIf Yes: Enter 'Y'  Else: Enter 'N' => ");
            char confirmation_specifier;
            scanf(" %c",&confirmation_specifier);

            if(confirmation_specifier == 'Y'||confirmation_specifier == 'y')
            {
                printf("\nEnter number of rows and columns of 2nd matrix :\n");
                int k,l;
                  scanf("%d%d",&k,&l);
                  
                  if(l!=n) 
                {system("cls");     
                 printf("Matrix multiplication not possible\n\n");
                 ctrl=1;
                  break;
                }

                float **matrix_2=(float**)malloc(k*sizeof(float*));
                for(int i=0;i<k;i++)
                  {
                      matrix_2[i]=(float*)malloc(l*sizeof(float));
                  }
                  
                  

                  printf("\nEnter Matrix_2 :\n");
                  for(int i=0;i<k;i++)
                  {
                      for(int j=0;j<l;j++)
                      {
                        scanf("%f",&matrix_2[i][j]);
                      }
                  }
                  
                PRE_multiplication_of_matrix(n,m,k,l,matrix_2);
            }
            
            else{
                ctrl=1;
                system("cls");
                return 0;
            }
        }
        break;
        
        case 4 :
        {
            printf("\nDo you want PostMultiplication_of_matrix\nIf Yes: Enter 'Y'  Else: Enter 'N' => ");
            char confirmation_specifier;
            scanf(" %c",&confirmation_specifier);

            if(confirmation_specifier == 'Y'||confirmation_specifier == 'y')
            {
                printf("\nEnter number of rows and columns of 2nd matrix :\n");
                int k,l;
                  scanf("%d%d",&k,&l);
                  
                  if(k!=m) 
                {system("cls");     
                 printf("Matrix multiplication not possible\n\n");
                 ctrl=1;
                  break;
                }

                float **matrix_2=(float**)malloc(k*sizeof(float*));
                for(int i=0;i<k;i++)
                  {
                      matrix_2[i]=(float*)malloc(l*sizeof(float));
                  }
                  
                  

                  printf("\nEnter Matrix_2 :\n");
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
                ctrl=1;
                system("cls");
                return 0;
            }
        }
        break;
        
        case 5 :
        {
            printf("\nDo you want scalar_multiplication_of_matrix\nIf Yes: Enter 'Y'  Else: Enter 'N' => ");
            char confirmation_specifier;
            scanf(" %c",&confirmation_specifier);
            
            if(confirmation_specifier == 'Y'||confirmation_specifier == 'y')
            {
                printf("\nEnter scalar multiplier: \n");
                float k;
                scanf("%f",&k);
                scalar_multiplication_of_matrix(n,m,k);
            }
            
            else{
                ctrl=1;
                system("cls");
                return 0;
            }
        }
        break;
        
        case 6 :
        {
            printf("\nDo you want transpose_of_matrix\nIf Yes: Enter 'Y'  Else: Enter 'N' => ");
            char confirmation_specifier;
            scanf(" %c",&confirmation_specifier);
            
            if(confirmation_specifier == 'Y'||confirmation_specifier == 'y')
            {
                transpose_of_matrix(n,m);
            }
            else{
                ctrl=1;
                system("cls");
                return 0;
            }
        }
        break;
        
        case 7 :
        {
            printf("\nDo you want cofactor_of_matrix\nIf Yes: Enter 'Y'  Else: Enter 'N' => ");
            char confirmation_specifier;
            scanf(" %c",&confirmation_specifier);
            if(confirmation_specifier == 'Y'||confirmation_specifier == 'y')
            {
                if(n!=m)
                {
                    system("cls");
                    printf("\nOperation incompatible\n\n");
                    ctrl=1;
                    return 0;
                    
                }
                //Requesting indices of the element for which cofactor is to be calculated
                    printf("\nEnter the indices of the element you want a cofactor matrix of\n");
                        int p,q;
                        scanf("%d %d",&p,&q);
                        --p;
                        --q;
    //--p, --q has been done to change the values of p and q from a better user interface to the program's interface
    // user will generally consider 1st element to be 1,1 but in the program it is 0,0
                if(p+1<n||q+1<n){
                printf("\nCo-factor = %.1f\n\n",cofactor_of_a_element(p,q,n));
                ctrl=1;
                return 0;}
                else 
                {
                    system("cls");
                    printf("Operation incompatible\n\n");
                    return 0;
                }
            }
            else{
                ctrl=1;
                system("cls");
                return 0;
            }
        }
        break;

        case 8 :
        {   
            printf("\nDo you want determinant_of_matrix\nIf Yes: Enter 'Y'  Else: Enter 'N' => ");
            char confirmation_specifier;
            scanf(" %c",&confirmation_specifier);
            if(confirmation_specifier == 'Y'||confirmation_specifier == 'y')
            {
                if(n!=m)
                {
                    system("cls");
                    printf("\nOperation Incompatible\n\n");
                    ctrl=1;
                    return 0;
                }
                printf("\n\nDeterminant of matrix = %.1f\n\n",determinant_of_matrix(matrix_1,n));
                ctrl=1;
                return 0;
                

            }

            else{
                ctrl=1;
                system("cls");
                return 0;
            }
        }
        break;
        
        case 9 :
        {
            printf("\nDo you want adjoint_of_matrix\nIf Yes: Enter 'Y'  Else: Enter 'N' =>");
            char confirmation_specifier;
            scanf(" %c",&confirmation_specifier);
            if(confirmation_specifier == 'Y'||confirmation_specifier == 'y')
            {
                if(n!=m)
                {
                    system("cls");
                    printf("\nOperation incompatible\n\n");
                    ctrl=1;
                    return 0;
                }
                adjoint_of_matrix(matrix_1,n);
            }
            else{
                ctrl=1;
                system("cls");
                return 0;
            }
        }
        break;
        
        case 10 :
        {
            printf("\nDo you want inverse_of_matrix\nIf Yes: Enter 'Y' Else: Enter 'N' =>");
            char confirmation_specifier;
            scanf(" %c",&confirmation_specifier);
            if(confirmation_specifier == 'Y'||confirmation_specifier == 'y')
            {
                if(n!=m)
                {
                    system("cls");
                    printf("\nOperation incompatible\n\n");
                    ctrl=1;
                    return 0;
                }
                inverse_of_matrix(n);
                break;
            }

            else{
                ctrl=1;
                system("cls");
                return 0;
            }
        }
        break;
        
        default:
        {
            printf("\nPlease enter valid choice\n");
        }
        break;
    }
    return 0;
}

//menu
void menu()
{
    printf("\n                                   WELCOME TO THE MATRIX OPERATION TOOLKIT \n");
    printf("                              A project made by ADITYA,KRISH,RAGHAV,SOHOM\n");


    printf("\nExit                 : 0\nSum                  : 1\nDifference           : 2\nPreMultiplication    : 3\nPostMultiplication   : 4\nScalar Multipication : 5\nTranspose            : 6\nCofactor             : 7\nDeterminant          : 8\nAdjoint              : 9\nInverse              : 10\n");
    return;
}

//main
int main() 
{
    

    int input_specifier;
    ctrl=1;
        
    do
    {//ctrl=1 means all inputs are required from the user end
        if(ctrl==1)
        {

                menu(); 
                printf("\nEnter choice of operation : ");
                scanf("%d",&input_specifier);


                if(input_specifier==0) break;
                else if(input_specifier<0||input_specifier>10) 
                {
                    system("cls");
                    printf("\nPlease enter valid choice\n\n");
                    main();
                }
                

                printf("\nEnter number of rows and columns :\n");
                scanf("%d%d",&row,&column);

                
                //checking if operation is inclusive to rectangular matrices
                if(input_specifier==7||input_specifier==8||input_specifier==9||input_specifier==10)
                {
                    
                    if(row!=column){
                    system("cls");
                    printf("Operation Incompatible\n\n");
                    main();
                    
                    break;}
                }
                
                printf("\nEnter %d X %d Matrix\n",row,column);
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
       //else or ctrl=0 means matrix_1 has been borrowed from the previous operation 
        else 
        {
            printf("\nEnter choice of operation: ");
            scanf("%d",&input_specifier);

            if(input_specifier==0) break;

            input(input_specifier,row,column);
        
        }
    }while(input_specifier!=0);
    //exits only when choice is 0
    
    free(matrix_1);
    printf("\nThank you for using our Matrix Calculator!\n");
    //Last message when program ends or user exits

return 0;
}
