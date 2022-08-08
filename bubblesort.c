#include <iostream>

using namespace std;

int main(){
    
    int vetor = {7, 3, 0, 1, 3, 8, 2, 9};

    return 0;
}
void swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

void bubble(int vector[], int size)
{
    for (int i=0; i<size -1; i++)
    {
        for(int j = 0; j < size -1; j++)
        {
            if(vector[j]> vector[j + 1])
            {
                swap(&vector[j], &vector[j + 1]);
            }
        }
    }
}
void printVector(const int *vector, int size)
{
    
}
