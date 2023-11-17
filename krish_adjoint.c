#include <stdio.h>
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
}