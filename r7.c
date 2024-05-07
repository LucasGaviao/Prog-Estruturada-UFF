#include <stdio.h>

void inveterVetor100(int *vet, int t){
    if (t <= 1){
        return vet;
    }
    int tmp = vet[t -1];
    vet[t-1] = vet[0];
    vet[0] = tmp;
    for(int i = 0; i < t; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");
    return inveterVetor100(&vet[1], t - 2);
}

int main(){
    int vetor[100];
    for (int i = 0; i < 100; i++){
        vetor[i] = i;
    }
    inveterVetor100(vetor, 100);
    for (int j = 0; j < 100; j++){
        printf("%d ", vetor[j]);
    }
    return 0;
}