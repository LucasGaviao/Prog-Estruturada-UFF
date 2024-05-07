#include <stdio.h>

int sum(int *vet, int t){
    if(t == 1){
        return vet[0];
    }
    return vet[0] + sum(&vet[1], t - 1);
}

int main(){
    int n;
    scanf("%d", &n);
    
    int i, vet[n];
    for (i = 0; i < n; i++){
        scanf("%d", &vet[i]);
    }

    int soma = sum(vet, n);
    printf("%d\n", soma);
    return 0;

}