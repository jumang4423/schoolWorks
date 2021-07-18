/*

author : ryoma okuda 
id     : s1270174

*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define RND 10
#define BASE 2 // Strassenの性能を出すためには、この値の調整が重要

//#define DEBUG
extern void start_timer(unsigned int *);
extern unsigned get_elapsed_time(unsigned int *);
extern unsigned int start_tm;
void mat_gen(int **, int **, int **, int, int);

void strassen(int **, int **, int **, int);
void n3_product(int **, int **, int **, int);

FILE *fp, *fp2;

int main(int argc, char *argv[])
{

    char filename[2][100], c;
    int fileflag = 0;

    int i, j, mat_size, n, err;
    int **A, **B, **C, **C2;

    if (argc <= 1)
    {
        fprintf(stderr, "error: argument which indicates the problem size is required.\n");
        exit(1);
    }
    mat_size = atoi(argv[1]);

    if (mat_size == -1)
    { // FILE IO
        fileflag = 1;

        printf("Enter the filename of matA:\n=>");
        scanf("%100s", filename[0]);
        printf("\n");

        fp = fopen(filename[0], "r");
        if (fp == NULL)
        {
            printf("error: file not found.\n");
            exit(1);
        }
        fscanf(fp, "%d", &mat_size);

        printf("Enter the filename of matB:\n=>");
        scanf("%100s", filename[1]);
        printf("\n");

        fp2 = fopen(filename[1], "r");
        if (fp == NULL)
        {
            printf("error: file not found.\n");
            exit(2);
        }
        fscanf(fp2, "%d", &n);

        if (mat_size != n)
        {
            printf("error: Sizes of matrix are incompatible.\n");
            exit(3);
        }
    }

    /* Get the memory space for arrays A, B, C. */
    A = (int **)malloc(mat_size * sizeof(int *));
    B = (int **)malloc(mat_size * sizeof(int *));
    C = (int **)malloc(mat_size * sizeof(int *));
    C2 = (int **)malloc(mat_size * sizeof(int *));
    for (i = 0; i < mat_size; i++)
    {
        A[i] = (int *)malloc(mat_size * sizeof(int));
        B[i] = (int *)malloc(mat_size * sizeof(int));
        C[i] = (int *)malloc(mat_size * sizeof(int));
        C2[i] = (int *)malloc(mat_size * sizeof(int));
    }

    /* Generate the matrix (Initialization) */
    mat_gen(A, B, C, mat_size, fileflag);

    /* O(n^3) matrix product  Function CALL*/
    start_timer(&start_tm);
    n3_product(A, B, C2, mat_size);
    printf("Normal    %dx%d     : elapsed time is %10.6f sec. \n", mat_size, mat_size,get_elapsed_time(&start_tm) * 1.0e-6);

    /* Strassen's algorithm  Function CALL*/
    start_timer(&start_tm);
    strassen(A, B, C, mat_size);
    printf("Strassen  %dx%d     : elapsed time is %10.6f sec. \n", mat_size, mat_size, get_elapsed_time(&start_tm) * 1.0e-6);

    /* Numerical error check */
    for (i = 0; i < mat_size; i++)
    {
        for (j = 0; j < mat_size; j++)
        {
            err = C2[i][j] - C[i][j];
            if (err != 0)
                printf("Error at(%d,%d) : %d\n", i, j, err);
        }
    }
    for (i = 0; i < mat_size; i++)
    {
        free(A[i]);
        free(B[i]);
        free(C[i]);
        free(C2[i]);
    }
    free(A);
    free(B);
    free(C);
    free(C2);

    return 0;
}

void strassen(int **A, int **B, int **C, int size)
{
    int i, j, mid;
    int **X, **Y, **P1, **P2, **P3, **P4, **P5, **P6, **P7;

    if (size <= BASE)
    { //行列がある規定のサイズ以下になったら、通常の乗算に持ち込む
        n3_product(A, B, C, size);
        return;
    }

    mid = size / 2; //行列の中央

    /* Allocate the memory for 2-D arrays  */
    X = (int **)malloc(mid * sizeof(int *));
    Y = (int **)malloc(mid * sizeof(int *));
    P1 = (int **)malloc(mid * sizeof(int *));
    P2 = (int **)malloc(mid * sizeof(int *));
    P3 = (int **)malloc(mid * sizeof(int *));
    P4 = (int **)malloc(mid * sizeof(int *));
    P5 = (int **)malloc(mid * sizeof(int *));
    P6 = (int **)malloc(mid * sizeof(int *));
    P7 = (int **)malloc(mid * sizeof(int *));
    for (i = 0; i < mid; i++)
    {
        X[i] = (int *)malloc(mid * sizeof(int *));
        Y[i] = (int *)malloc(mid * sizeof(int *));
        P1[i] = (int *)malloc(mid * sizeof(int *));
        P2[i] = (int *)malloc(mid * sizeof(int *));
        P3[i] = (int *)malloc(mid * sizeof(int *));
        P4[i] = (int *)malloc(mid * sizeof(int *));
        P5[i] = (int *)malloc(mid * sizeof(int *));
        P6[i] = (int *)malloc(mid * sizeof(int *));
        P7[i] = (int *)malloc(mid * sizeof(int *));
    }

    // ここで初期化しないとNumerical error 発生
    for (i = 0; i < mid; i++)
    {
        for (j = 0; j < mid; j++)
        {
            X[i][j] = 0;
            Y[i][j] = 0;
            P1[i][j] = 0;
            P2[i][j] = 0;
            P3[i][j] = 0;
            P4[i][j] = 0;
            P5[i][j] = 0;
            P5[i][j] = 0;
            P6[i][j] = 0;
            P7[i][j] = 0;
        }
    }

    /* Compute P1  = (A12 - A22)(B21 + B22)*/
    for (i = 0; i < mid; i++)
    {
        for (j = 0; j < mid; j++)
        {
            X[i][j] = A[i][j + mid] - A[mid + i][mid + j]; // mid は行列を４分割する前の中央線に相当する。これをうまく使いこなすこと
            Y[i][j] = B[mid + i][j] + B[mid + i][mid + j]; // X,Y は AとBを分割した部分行列、ということになる
        }
    }

    strassen(X, Y, P1, mid);

    /* P2 = (A11 + A22)(B11 + B22) */
    for (i = 0; i < mid; i++)
    {
        for (j = 0; j < mid; j++)
        {
            X[i][j] = A[i][j] + A[mid + i][mid + j];
            Y[i][j] = B[i][j] + B[mid + i][mid + j];
        }
    }
    strassen(X, Y, P2, mid);

    /* P3 = (A11 - A21)(B11 + B12) */
    for (i = 0; i < mid; i++)
    {
        for (j = 0; j < mid; j++)
        {
            X[i][j] = A[i][j] - A[mid + i][j];
            Y[i][j] = B[i][j] + B[i][mid + j];
        }
    }
    strassen(X, Y, P3, mid);

    /* P4 = (A11 + A12)B22 */
    for (i = 0; i < mid; i++)
    {
        for (j = 0; j < mid; j++)
        {
            X[i][j] = A[i][j] + A[i][mid + j];
            Y[i][j] = B[mid + i][mid + j];
        }
    }
    strassen(X, Y, P4, mid);

    /* P5 = A11(B12 - B22) */
    for (i = 0; i < mid; i++)
    {
        for (j = 0; j < mid; j++)
        {
            X[i][j] = A[i][j];
            Y[i][j] = B[i][mid + j] - B[mid + i][mid + j];
        }
    }
    strassen(X, Y, P5, mid);

    /* P6 = A22(B21 - B11) */
    for (i = 0; i < mid; i++)
    {
        for (j = 0; j < mid; j++)
        {
            X[i][j] = A[mid + i][mid + j];
            Y[i][j] = B[mid + i][j] - B[i][j];
        }
    }
    strassen(X, Y, P6, mid);

    /* P7 = (A21 + A22)B11 */
    for (i = 0; i < mid; i++)
    {
        for (j = 0; j < mid; j++)
        {
            X[i][j] = A[mid + i][j] + A[mid + i][mid + j];
            Y[i][j] = B[i][j];
        }
    }
    strassen(X, Y, P7, mid);

    /* Calc C11,C12,C21,C22 */
    for (i = 0; i < mid; i++)
    {
        for (j = 0; j < mid; j++)
        { // つまり P1 から P7 を使って C を求める
            C[i][j] = P1[i][j] + P2[i][j] - P4[i][j] + P6[i][j];
            C[i][mid + j] = P4[i][j] + P5[i][j];
            C[mid + i][j] = P6[i][j] + P7[i][j];
            C[mid + i][mid + j] = P2[i][j] - P3[i][j] + P5[i][j] - P7[i][j];
        }
    }

    /* Free the allocated memory */
    for (i = 0; i < mid; i++)
    {
        free(X[i]);
        free(Y[i]);
        free(P1[i]);
        free(P2[i]);
        free(P3[i]);
        free(P4[i]);
        free(P5[i]);
        free(P6[i]);
        free(P7[i]);
    }
    free(X);
    free(Y);
    free(P1);
    free(P2);
    free(P3);
    free(P4);
    free(P5);
    free(P6);
    free(P7);

    return;
}

/* The conventional O(n^3) matrix multiplication. */
void n3_product(int **A, int **B, int **C, int n)
{ //線形代数でおなじみの、普通の行列積の解き方
    int i, j, k;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            for (k = 0; k < n; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void mat_gen(int **A, int **B, int **C, int n, int flag)
{
    int i, j, t;

    switch (flag)
    {
    case 0:
        srand(time(NULL));

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                t = rand();
                if (t < RND)
                    A[i][j] = t;
                else
                    A[i][j] = t % RND;
                t = rand();
                if (t < RND)
                    B[i][j] = t;
                else
                    B[i][j] = t % RND;

                C[i][j] = 0;
            }
        }
        break;

    case 1:
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                fscanf(fp, "%d", &A[i][j]);
                fscanf(fp2, "%d", &B[i][j]);
                C[i][j] = 0;
            }
        }

        break;

    default:
        break;
    }
}