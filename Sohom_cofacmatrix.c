#include <stdio.h>

int main() {
    // Write C code here
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
    return 0;
}
