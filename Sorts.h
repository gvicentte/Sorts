#infdef SORTS_H
#define SORTS_H
#include <stdio.h>
#include <stdbool.h>

int GetMax(int *v, int n) {
    int max = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] > max) {
            max = v[i];
        }
    }
    return max;
}

void insertionsort(int *v, int n){
    int aux, i, j;
    for(i=1;i<n;i++){
        aux=v[i];
        for(j=i-1;j>=0 && aux<v[j];j--){
            v[j+1]=v[j];
        }
        v[j+1]=aux;
    }
}

void selectionsort(int *v,int n){
    int aux,i,j,menor;
    for(i=0;i<n-1;i++){
        menor=i;
        for(j=i+1;j<n;j++){
            if(v[j]<v[menor]){
                menor=j;
            }
        }
        aux=v[i];
        v[i]=v[menor];
        v[menor]=aux;
    }
}

void bubblesort(int *v,int n){
    int aux,i,j;
    bool k=true;
    for(i=0;i<n-1 && k;i++){
        k=false;
        for(j=0;j<n-1-i;j++){
            if(v[j]>v[j+1]){
                k=true;
                aux=v[j];
                v[j]=v[j+1];
                v[j+1]=aux;
            }
        }
    }
}

void merge(int *v,int in,int m,int f){
    int vet[f-in+1];
    int i,j,k;
    for(i=in,j=m+1,k=0;i<=m && j<=f;k++){
        if(v[i]<=v[j]){
            vet[k]=v[i];
            i++;
        }
        else{
            vet[k]=v[j];
            j++;
        }
    }
    for(;i<=m;i++,k++){
        vet[k]=v[i];
    }
    for(;j<=f;j++,k++){
        vet[k]=v[j];
    }
    for(k=0,i=in;i<=f;k++,i++){
        v[i]=vet[k];
    }
}

void mergesort(int *v,int i,int f){
    int m;
    if(i<f){
        m=(i+f)/2;
        mergesort(v,i,m);
        mergesort(v,m+1,f);
        merge(v,i,m,f);
    }
}

void Heapify(int *v,int n,int i){
    int l,r,maior,aux;
    l=2*i+1;
    r=2*i+2;
    if(l<n && v[l]>v[i]){
        maior=l;
    }
    else{
        maior=i;
    }
    if(r<n && v[r]>v[maior]){
        maior=r;
    }
    if(maior!=i){
        aux=v[maior];
        v[maior]=v[i];
        v[i]=aux;
        Heapify(v,n,maior);
    }
}

void BuildHeap(int *v,int n){
    int i;
    for(i=(n-2)/2;i>=0;i--){
        Heapify(v,n,i);
    }
}

void HeapSort(int *v,int n){
    int aux;
    BuildHeap(v,n);
    while(n){
        aux=v[0];
        v[0]=v[n-1];
        v[n-1]=aux;
        n--;
        Heapify(v,n,0);
    }
}

int Partition(int *v,int p,int r){
    int i,j,x,aux;
    x=v[p]; //Pivo pode ser uma função que escolhe aleatório
    j=r+1;
    i=p-1;
    while(1){
        do{
            j--;
        }while(v[j]>x);
        do{
            i++;
        }while(v[i]<x);
        if(i<j){
            aux=v[i];
            v[i]=v[j];
            v[j]=aux;
        }
        else{
            return j;
        }
    }
}

void QuickSort(int *v,int p,int r){
    if(p<r){
        int q;
        q=Partition(v,p,r);
        QuickSort(v,p,q);
        QuickSort(v,q+1,r);
    }
}

void CountingSort(int *v,int n){
    int maior=GetMax(v,n);
    int v1[maior+1]={};
    int aux[n];
    int i;
    for(i=0;i<n;i++){
        v1[v[i]]++;
    }
    for(i=1;i<=maior;i++){
        v1[i]=v1[i-1]+v1[i];
    }
    for(i=n-1;i>=0;i--){
        aux[v1[v[i]]-1]=v[i];
        v1[v[i]]--;
    }
    for(i=0;i<n;i++){
        v[i]=aux[i];
    }
}

void CountingSortR(int *v,int n,int exp){
    int aux[n];
    int cont[10]={};
    for (int i=0;i<n;i++){
        cont[(v[i]/exp)%10]++;
    }
    for (int i=1;i<10;i++){
        cont[i]+=cont[i-1];
    }
    for (int i=n-1;i>=0;i--){
        aux[cont[(v[i]/exp)%10]-1]=v[i];
        cont[(v[i]/exp)%10]--;
    }
    for (int i=0;i<n;i++){
        v[i]=aux[i];
    }
}

void RadixSort(int *v, int n){
    int max=GetMax(v,n);
    for (int exp=1;max/exp > 0;exp*=10){
        CountingSortR(v,n,exp);
    }
}

#endif
