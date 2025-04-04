#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "sorts.h" // Certifique-se de que o sorts.h declara corretamente todas as funções

#define SIZE_1 1000
#define SIZE_2 10000
#define SIZE_3 100000

// Wrappers para funções que exigem parâmetros adicionais
void QuickSortWrapper(int *arr, int size) {
    QuickSort(arr, 0, size - 1);
}

void MergeSortWrapper(int *arr, int size) {
    mergesort(arr, 0, size - 1);
}

// Preenchimento dos vetores
void fillArrayBestCase(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }
}

void fillArrayWorstCase(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = size - i;
    }
}

void fillArrayAverageCase(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % size;
    }
}

// Medidor de tempo
void measureSortTime(void (*sortFunc)(int*, int), int *arr, int size, const char *sortName, const char *caseType) {
    int *copy = malloc(size * sizeof(int));
    memcpy(copy, arr, size * sizeof(int));

    clock_t start = clock();
    sortFunc(copy, size);
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("%s - %s: %f seconds\n", sortName, caseType, time_taken);

    free(copy);
}

// Teste de todos os algoritmos com os 3 tipos de casos
void testSorts(int *arr, int size) {
    // Melhor caso
    fillArrayBestCase(arr, size);
    measureSortTime(bubblesort, arr, size, "Bubble Sort", "Best Case");
    measureSortTime(Bubblesort, arr, size, "Bubble Sort Sem Variavel", "Best Case");
    measureSortTime(insertionsort, arr, size, "Insertion Sort", "Best Case");
    measureSortTime(selectionsort, arr, size, "Selection Sort", "Best Case");
    measureSortTime(QuickSortWrapper, arr, size, "Quick Sort", "Best Case");
    measureSortTime(MergeSortWrapper, arr, size, "Merge Sort", "Best Case");
    measureSortTime(CountingSort, arr, size, "Counting Sort", "Best Case");
    measureSortTime(RadixSort, arr, size, "Radix Sort", "Best Case");
    measureSortTime(HeapSort, arr, size, "Heap Sort", "Best Case");

    // Pior caso
    fillArrayWorstCase(arr, size);
    measureSortTime(bubblesort, arr, size, "Bubble Sort", "Worst Case");
    measureSortTime(Bubblesort, arr, size, "Bubble Sort Sem Variavel", "Worst Case");
    measureSortTime(insertionsort, arr, size, "Insertion Sort", "Worst Case");
    measureSortTime(selectionsort, arr, size, "Selection Sort", "Worst Case");
    measureSortTime(QuickSortWrapper, arr, size, "Quick Sort", "Worst Case");
    measureSortTime(MergeSortWrapper, arr, size, "Merge Sort", "Worst Case");
    measureSortTime(CountingSort, arr, size, "Counting Sort", "Worst Case");
    measureSortTime(RadixSort, arr, size, "Radix Sort", "Worst Case");
    measureSortTime(HeapSort, arr, size, "Heap Sort", "Worst Case");

    // Caso médio
    fillArrayAverageCase(arr, size);
    measureSortTime(bubblesort, arr, size, "Bubble Sort", "Average Case");
    measureSortTime(Bubblesort, arr, size, "Bubble Sort Sem Variavel", "Average Case");
    measureSortTime(insertionsort, arr, size, "Insertion Sort", "Average Case");
    measureSortTime(selectionsort, arr, size, "Selection Sort", "Average Case");
    measureSortTime(QuickSortWrapper, arr, size, "Quick Sort", "Average Case");
    measureSortTime(MergeSortWrapper, arr, size, "Merge Sort", "Average Case");
    measureSortTime(CountingSort, arr, size, "Counting Sort", "Average Case");
    measureSortTime(RadixSort, arr, size, "Radix Sort", "Average Case");
    measureSortTime(HeapSort, arr, size, "Heap Sort", "Average Case");
}

int main() {
    srand(time(NULL));

    int *arr1 = malloc(SIZE_1 * sizeof(int));
    int *arr2 = malloc(SIZE_2 * sizeof(int));
    int *arr3 = malloc(SIZE_3 * sizeof(int));

    printf("\n---- TESTES COM %d ELEMENTOS ----\n", SIZE_1);
    testSorts(arr1, SIZE_1);

    printf("\n---- TESTES COM %d ELEMENTOS ----\n", SIZE_2);
    testSorts(arr2, SIZE_2);

    printf("\n---- TESTES COM %d ELEMENTOS ----\n", SIZE_3);
    testSorts(arr3, SIZE_3);

    free(arr1);
    free(arr2);
    free(arr3);

    return 0;
}
