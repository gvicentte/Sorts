#ifndef SORTS_H
#define SORTS_H
#include <stdio.h>
#include <stdbool.h>

int GetMax(int *v, int n);
void insertionsort(int *v, int n);
void selectionsort(int *v,int n);
void bubblesort(int *v,int n);
void Bubblesort(int *v,int n);
void merge(int *v,int in,int m,int f);
void mergesort(int *v,int i,int f);
void Heapify(int *v,int n,int i);
void BuildHeap(int *v,int n);
void HeapSort(int *v,int n);
int Partition(int *v,int p,int r);
void QuickSort(int *v,int p,int r);
void CountingSort(int *v,int n);
void CountingSortR(int *v,int n,int exp);
void RadixSort(int *v, int n);

#endif // SORTS_H