#include <stdio.h>
void PrintSparse(int X[20][3]) {
    int i, j;
    printf("\nTuple representation of Sparse Matrix is:\n");
    for (i = 0; i <= X[0][2]; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d\t", X[i][j]);
        }
        printf("\n");
    }
}
void Sparse(int A[10][10], int m, int n, int S[20][3]) {
    int i, j, k = 1;
    S[0][0] = m;
    S[0][1] = n;

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (A[i][j] != 0) {
                S[k][0] = i;
                S[k][1] = j;
                S[k][2] = A[i][j];
                k++;
            }
        }
    }
    S[0][2] = k - 1;
    PrintSparse(S);
}
void AddSparse(int S[20][3], int T[20][3], int rl, int cl, int r2, int c2) {
    int A[20][3], m, n, i, j, k;
    rl = S[0][0];
    r2 = T[0][0];
    cl = S[0][1];
    c2 = T[0][1];

    if (rl != r2 || cl != c2) {
        printf("Incompatible Matrix size\n");
    } else {
        A[0][0] = S[0][0];
        A[0][1] = S[0][1];
        m = 1;
        n = 1;
        k = 1;

        for (i = 0; i < rl; i++) {
            for (j = 0; j < cl; j++) {
                if (S[m][0] == i && S[m][1] == j && T[n][0] == i && T[n][1] == j) {
                    A[k][0] = S[m][0];
                    A[k][1] = S[m][1];
                    A[k][2] = S[m][2] + T[n][2];
                    m++;
                    n++;
                    k++;
                } else if (S[m][0] == i && S[m][1] == j) {
                    A[k][0] = S[m][0];
                    A[k][1] = S[m][1];
                    A[k][2] = S[m][2];
                    m++;
                    k++;
                } else if (T[n][0] == i && T[n][1] == j) {
                    A[k][0] = T[n][0];
                    A[k][1] = T[n][1];
                    A[k][2] = T[n][2];
                    n++;
                    k++;
                }
            }
        }
        A[0][2] = k - 1;
        printf("SUM:\n");
        for (i = 0; i <= A[0][2]; i++) {
            for (j = 0; j < 3; j++) {
                printf("%d\t", A[i][j]);
            }
            printf("\n");
        }
    }
}

int main() {
    int A[10][10], B[10][10], m1, n1, m2, n2, S[20][3], T[20][3], i, j;

    printf("Enter the number of rows and columns of the first matrix: ");
    scanf("%d %d", &m1, &n1);
    printf("Enter the matrix:\n");
    for (i = 0; i < m1; i++) {
        for (j = 0; j < n1; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    printf("Matrix 1:\n");
    for (i = 0; i < m1; i++) {
        for (j = 0; j < n1; j++) {
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }
    Sparse(A, m1, n1, S);

    printf("Enter the number of rows and columns of the Second matrix: ");
    scanf("%d %d", &m2, &n2);
    printf("Enter the matrix:\n");
    for (i = 0; i < m2; i++) {
        for (j = 0; j < n2; j++) {
            scanf("%d", &B[i][j]);
        }
    }
    printf("Matrix 2:\n");
    for (i = 0; i < m2; i++) {
        for (j = 0; j < n2; j++) {
            printf("%d\t", B[i][j]);
        }
        printf("\n");
    }
    Sparse(B, m2, n2, T);

    AddSparse(S, T, m1, n1, m2, n2);

    return 0;
}
