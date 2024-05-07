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

