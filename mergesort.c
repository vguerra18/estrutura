#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mergesort(int arr[], int inicio, int fim);
void merge(int arr[], int inicio, int meio, int fim);

int main(){
    int arr[] = {3, 0, 7, 1, 5, 2, 5, 6};

}

int mergesort (int arr[], int inicio, int fim)
{
    if(inicio < fim)
    {
        int meio = inicio + (fim - inicio) / 2;

        mergesort(arr, inicio, meio);
        mergesort(arr , meio + 1, fim);
        merge(arr, inicio, meio, fim);
    }
}

void merge(int arr[], int inicio, int meio, int fim){
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    int L[n1];
    int R[n2];

    for(int i = 0; i < n1; i++){
        L[i] = arr[i + 1];
    }
    for(int i = 0; i < n2; i++){
        R[i] = arr[meio + i];
    }

    int i = 0, j = 0, k = 0;
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else 
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
}