#include<stdio.h>
                   
int main(){

    printf("\n                                   WELCOME TO THE MATRIX \n");
    printf("                              A project made by ADITYA,KRISH,RAGHAV,SOHOM\n");

    // printf("\nTo perform Matrix operation : ENTER 1\n");
    // printf("\nTo know the type of your matrix : ENTER 2\n");
    //printf("\nTo know the type of your matrix : ENTER 3\n");

    printf("\nSum                  : 1\nDifference           : 2\nPreMultiplication       : 3\nPostMultiplication      : 3\nScalar Multipication : 5\nTranspose            : 6\nCofactor             : 7\nDeterminant           : 8\nAdjoint              : 9\nInverse              : 10\n");
    int input_specifier;    
    printf("\nENTER THE VALUE:");
    scanf("%d",&input_specifier);

    switch(input_specifier)

        case 1 : 
            printf(" Do you want sum_of_matrix\n IF YES:ENTER 'Y' ELSE 'N' ");
            char confirmation_specifier;
            scanf("%c",&confirmation_specifier);

            if(confirmation_specifier == 'Y'){
                sum_of_matrix(n,m,matrix_1,matrix_2);
            break;
            }

            else{
                input();
            }
            

        case 2 : 
            printf("Do you want difference_of_matrix\n IF YES:ENTER 'Y' ELSE 'N' ");
            char confirmation_specifier;
            scanf("%c",&confirmation_specifier);

            if(confirmation_specifier == 'Y'){
                difference_of_matrix(n,m,matrix_1,matrix_2);
            break;
            }

            else{
                input();
            }
            
        case 3 : 
        printf("Do you want PreMultiplication_of_matrix\n IF YES:ENTER 'Y' ELSE 'N' ")
            char confirmation_specifier;
            scanf("%c",&confirmation_specifier);

            if(confirmation_specifier == 'Y'){
                PRE_multiplication_of_matrix(n,m,matrix_1,matrix_2);
            break;
            }

            else{
                input();
            } 
        } 

        case 4 : 
            printf("Do you want PostMultiplication_of_matrix\n IF YES:ENTER 'Y' ELSE 'N' ");
            char confirmation_specifier;
            scanf("%c",&confirmation_specifier);

            if(confirmation_specifier == 'Y'){
                POST_multiplication_of_matrix(n,m,matrix_1,matrix_2);
            break;
            }

            else{
                input();
            }
            
        
        case 5 : 
        printf("Do you want scalar_multiplication_of_matrix\n IF YES:ENTER 'Y' ELSE 'N' ");
            char confirmation_specifier;
            scanf("%c",&confirmation_specifier);

            if(confirmation_specifier == 'Y'){
                scalar_multiplication_of_matrix(n,m,matrix_1);
            break;
            }

            else{
                input();
            }
            
        
        case 6 :
        printf("Do you want transpose_of_matrix\n IF YES:ENTER 'Y' ELSE 'N' ");
            char confirmation_specifier;
            scanf("%c",&confirmation_specifier);

            if(confirmation_specifier == 'Y'){
                transpose_of_matrix(n,m,matrix_1);
            break;
            }

            else{
                input();
            } 
            

        case 7 : 
        printf("Do you want cofactor_of_matrix\n IF YES:ENTER 'Y' ELSE 'N' ");
            char confirmation_specifier;
            scanf("%c",&confirmation_specifier);

            if(confirmation_specifier == 'Y'){
                cofactor_of_matrix(n,m,matrix_1);
            break;
            }

            else{
                input();
            }

        case 8 : 
        printf("Do you want determinant_of_matrix\n IF YES:ENTER 'Y' ELSE 'N' ");
            char confirmation_specifier;
            scanf("%c",&confirmation_specifier);

            if(confirmation_specifier == 'Y'){
                determinant_of_matrix(n,m,matrix_1);
            break;
            }

            else{
                input();
            }
        
        case 9 : 
        printf("Do you want adjoint_of_matrix\n IF YES:ENTER 'Y' ELSE 'N' ");
            char confirmation_specifier;
            scanf("%c",&confirmation_specifier);

            if(confirmation_specifier == 'Y'){
                adjoint_of_matrix(n,m,matrix_1);
            break;
            }

            else{
                input();
            }
        
        case 10 : 
        printf("Do you want inverse_of_matrix\n IF YES:ENTER 'Y' ELSE 'N' ");
            char confirmation_specifier;
            scanf("%c",&confirmation_specifier);

            if(confirmation_specifier == 'Y'){
                inverse_of_matrix(n,m,matrix_1);
            break;
            }

            else{
                input();
            }

}
