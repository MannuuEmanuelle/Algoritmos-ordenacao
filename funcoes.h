#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 10000 // Tamanho do array

// Função para preencher o array com valores aleatórios
void preencherAleatorio(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        arr[i] = rand() % 10000; // Números de 0 a 9999
    }
}

// Função para copiar um array
void copiarArray(int origem[], int destino[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        destino[i] = origem[i];
    }
}

// Função Bubble Sort
void bubbleSort(int arr[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Função Selection Sort
void selectionSort(int arr[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < tamanho; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// Função Insertion Sort
void insertionSort(int arr[], int tamanho) {
    for (int i = 1; i < tamanho; i++) {
        int chave = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = chave;
    }
}

// Função Merge Sort
void merge(int arr[], int esq, int meio, int dir) {
    int n1 = meio - esq + 1;
    int n2 = dir - meio;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[esq + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[meio + 1 + j];

    int i = 0, j = 0, k = esq;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int esq, int dir) {
    if (esq < dir) {
        int meio = esq + (dir - esq) / 2;
        mergeSort(arr, esq, meio);
        mergeSort(arr, meio + 1, dir);
        merge(arr, esq, meio, dir);
    }
}

// Função Quick Sort
void quickSort(int arr[], int baixo, int alto) {
    if (baixo < alto) {
        int pivo = arr[alto], i = baixo - 1;
        for (int j = baixo; j < alto; j++) {
            if (arr[j] < pivo) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[alto];
        arr[alto] = temp;
        int p = i + 1;

        quickSort(arr, baixo, p - 1);
        quickSort(arr, p + 1, alto);
    }
}

// Função Counting Sort
void countingSort(int arr[], int tamanho) {
    int max = 10000, count[max + 1], output[tamanho];

    for (int i = 0; i <= max; i++)
        count[i] = 0;
    for (int i = 0; i < tamanho; i++)
        count[arr[i]]++;
    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];
    for (int i = tamanho - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (int i = 0; i < tamanho; i++)
        arr[i] = output[i];
}

// Função para medir tempo de execução de cada algoritmo
void testarOrdenacao(void (*algoritmo)(int[], int), int arr[], int tamanho, const char *nome) {
    int copia[TAMANHO];
    copiarArray(arr, copia, tamanho);

    clock_t inicio = clock();
    algoritmo(copia, tamanho);
    clock_t fim = clock();

    double tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("%s: %lf segundos\n", nome, tempo);
}

// Testes para Merge Sort e Quick Sort
void testarMergeSort(int arr[], int tamanho) {
    int copia[TAMANHO];
    copiarArray(arr, copia, tamanho);

    clock_t inicio = clock();
    mergeSort(copia, 0, tamanho - 1);
    clock_t fim = clock();

    double tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Merge Sort: %lf segundos\n", tempo);
}

void testarQuickSort(int arr[], int tamanho) {
    int copia[TAMANHO];
    copiarArray(arr, copia, tamanho);

    clock_t inicio = clock();
    quickSort(copia, 0, tamanho - 1);
    clock_t fim = clock();

    double tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Quick Sort: %lf segundos\n", tempo);
}


