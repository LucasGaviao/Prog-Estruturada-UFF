/*Crie um programa em C, que contenha uma função recursiva que receba dois
inteiros positivos k e n e calcule k^n. Utilize apenas multiplicações. O programa principal
deve solicitar ao usuário os valores de k e n e imprimir o resultado da chamada da
função.*/
#include <stdio.h>

long long int potencia(int k, int n){
    if (n == 0){
        return 1;
    }
    return k * potencia(k, n - 1);
}

int main(void){
    int k,n;
    scanf("%d %d", &k, &n);
    printf("%lld\n", potencia(k, n));
    return 0;
}

