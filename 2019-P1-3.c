#include <stdio.h>
#include <stdlib.h>

void leia_matriz(int n, int **matriz);
void imprima_matriz(int n, int **matriz);
void multiplicar_matriz(int n, int **matA, int **matB, int **matR);

int main(){
    int n;
    scanf("%d", &n);

    int **mat = (int **)malloc(n * sizeof(int **));
    int **matT = (int **)malloc(n * sizeof(int **));
    int **matM = (int **)malloc(n * sizeof(int **));
    int **matM2 = (int **)malloc(n * sizeof(int **));
    int **matI = (int **)malloc(n * sizeof(int **));
    for (int i = 0; i < n; i++){
        mat[i] = (int *)malloc(n*sizeof(int));
        matT[i] = (int *)malloc(n*sizeof(int));
        matM[i] = (int *)malloc(n*sizeof(int));
        matM2[i] = (int *)malloc(n*sizeof(int));
        matI[i] = (int *)malloc(n * sizeof(int));
    }
    leia_matriz(n, mat);
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            matT[i][j] = mat[j][i];
            if (i == j){
                matI[i][j] = 1;
            }
            else{
                matI[i][j] = 0;
            }
        }
    }

    printf("Matriz Q: \n");
    imprima_matriz(n, mat);
    printf("Matriz Q Transposta: \n");
    imprima_matriz(n, matT);
    printf("Matriz Identidade: \n");
    imprima_matriz(n, matI);
    printf("Matriz QxQt: \n");
    multiplicar_matriz(n, mat, matT, matM);
    imprima_matriz(n, matM);
    printf("Matriz QtxQ: \n");
    multiplicar_matriz(n, matT, mat, matM2);
    imprima_matriz(n, matM2);

    int cont = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if((matM[i][j] == matM2[i][j]) && (matM[i][j] == matI[i][j])){
                cont += 1;
            }
        }
    }
    if (cont == (n*n)){
        printf("A Matriz Q eh ortogonal!!!\n");
    }
    else{
        printf("A Matriz Q n eh ortogonal :( \n");
    }
     for (int i = 0; i < n; i++) {
        free(mat[i]);
        free(matT[i]);
        free(matM[i]);
        free(matM2[i]);
        free(matI[i]);
    }
    free(mat);
    free(matT);
    free(matM);
    free(matM2);
    free(matI);
    return 0;
}

void leia_matriz(int n, int **matriz){
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
}

void imprima_matriz(int n, int **matriz){
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void multiplicar_matriz(int n, int **matA, int **matB, int **matR){
    int i, j, k;
    for (i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            matR[i][j] = 0;
            for(k = 0; k < n; k++){
                matR[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }
}