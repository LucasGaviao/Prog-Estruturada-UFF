#include <stdio.h>

int somatorio(int n){
    if (n == 1){
        return 1;
    }
    return n + somatorio(n-1);
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%d\n", somatorio(n));
    return 0;
}

