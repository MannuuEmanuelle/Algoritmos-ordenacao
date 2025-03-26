#include "funcoes.h"

int main() {
    srand(time(NULL));

    int arr[TAMANHO];
    preencherAleatorio(arr, TAMANHO);

    printf("Testando algoritmos de ordenação com %d elementos:\n", TAMANHO);
    
    testarOrdenacao(bubbleSort, arr, TAMANHO, "Bubble Sort");
    testarOrdenacao(selectionSort, arr, TAMANHO, "Selection Sort");
    testarOrdenacao(insertionSort, arr, TAMANHO, "Insertion Sort");
    testarMergeSort(arr, TAMANHO);
    testarQuickSort(arr, TAMANHO);
    testarOrdenacao(countingSort, arr, TAMANHO, "Counting Sort");

    return 0;
}