/*Alunos: José Augusto Moreira, Henrique Melero e Vinicius Guerra.
Estrutura de dados 1
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

typedef struct float_vector Float_Vector;

Float_Vector *alocavetor(long int tamanho);
void imprimeVetor(Float_Vector *ptrvet, long int tamanho);
void swap(float *valor_a, float *valor_b);
void quick_sort(Float_Vector *ptrvet, long int inicio, long int fim, long int tamanho);

/**
 *  @brief Estrutura dos veteores ultilizados nos algoritimos.
 *
 */
struct float_vector
{
    long int tamanho;
    long int size;  // numero máximo de elementos
    float *valores; // ptrvet de floats
};

/**
 *  @brief Função para alocar um ptrvet de floats.
 *
 *  @param tamanho, tipo long int, recebe o tamanho do ptrvet de floats a ser alocado;
 *
 */

Float_Vector *alocavetor(long int tamanho)
{

    Float_Vector *ptrvet = (Float_Vector *)calloc(1, sizeof(Float_Vector));
    ptrvet->tamanho = tamanho;
    ptrvet->size = 0;
    ptrvet->valores = (float *)calloc(ptrvet->tamanho, sizeof(float));
    srand(time(NULL));
    for (long int i = 0; i < tamanho; i++)
    {
        float v = rand() % tamanho;
        ptrvet->valores[ptrvet->size++] = v;
    }
    if (ptrvet != NULL)
    {
        printf("ALOCADO");
    }
    return ptrvet;
}

/**
 *  @brief Função para imprimir um ptrvet de floats.
 *
 *  @param ptrvet, um ponteiro para o ptrvet de floats;
 *
 */

void imprimeVetor(Float_Vector *ptrvet, long int tamanho)
{
    Float_Vector *ptr = ptrvet;
    long int i;
    printf("\n ");
    for (i = 0; i < tamanho; i++)
    {
        printf("| %f |", ptr->valores[i]);
    }
}

/**
 *  @brief Função para realizar o swap entre os numeros nos algoritimos.
 *
 *  @param valor_a, recebe um dos valores a ser trocado;
 *  @param valor_b, recebe um dos valores a ser trocado;
 *
 */

void swap(float *valor_a, float *valor_b)
{
    float aux;
    aux = *valor_a;
    *valor_a = *valor_b;
    *valor_b = aux;
}
/**
 *@brief Menu function para realizar switch entre os tipos de sorts.
 **/
int menu()
{
    int op;
    printf("\n==========[ SORTS ] =========\n");
    printf("1 - QuickSort\n");
    printf("2 - MergeSort\n");
    printf("3 - BubbleSort \n");
    printf("4 - InsertionSort\n");
    scanf("%d", &op);
    return op;
}

/**
 * @brief função do Quicksort com melhorias realizadas.
 *
 * @param tamanho, recebe o tamanho do vetor.
 * @param vetor, recebe o vetor.
 * @param inicio, recebe o começo do vetor.
 * @param fim, recebe a ultima posiççao do vetor.
 *
 **/
void quick_sort(Float_Vector *vetor, long int inicio, long int fim, long int tamanho)
{
    long int pivo, esq, dir, meio;

    // Limites da esquerda e direita da região analisada
    esq = inicio;
    dir = fim;

    // Ajustando auxiliares do centro
    meio = (int)((esq + dir) / 2);
    pivo = vetor->valores[meio];

    while (dir > esq)
    {

        while (vetor->valores[esq] < pivo)
        {
            esq = esq + 1;
        }

        while (vetor->valores[dir] > pivo)
        {
            dir = dir - 1;
        }

        if (esq <= dir)
        {

            // Realiza uma troca
            swap(&vetor->valores[esq], &vetor->valores[dir]);

            // Faz os limites laterais caminharem para o centro
            esq = esq + 1;
            dir = dir - 1;
        }
    }

    // Recursão para continuar ordenando
    if (inicio < dir)
    {
        quick_sort(vetor, inicio, dir, tamanho);
    }

    // Recursão para continuar ordenando
    if (esq < fim)
    {
        quick_sort(vetor, esq, fim, tamanho);
    }
}

void merge(Float_Vector *vetor, long int esquerdo, long int meio, long int direito)
{
    long int i, j, k; // auxiliares

    long int n1 = meio - esquerdo + 1; // +1 por causa do indice 0
    long int n2 = direito - meio;

    float vetorL[n1], vetorR[n2]; // indice da direita apenas

    for (i = 0; i < n1; i++)
    {
        vetorL[i] = vetor->valores[esquerdo + i];
    }
    for (j = 0; j < n2; j++)
    {
        vetorR[j] = vetor->valores[meio + j + 1];
    }
    i = 0; // erro estava aqui aparentemente entrei com i,j=0; apos mudança funcionou.
    j = 0;
    k = esquerdo;

    while (i < n1 && j < n2)
    {
        if (vetorL[i] <= vetorR[j])
        {
            vetor->valores[k] = vetorL[i];
            i++;
        }
        else
        {
            vetor->valores[k] = vetorR[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        vetor->valores[k] = vetorL[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        vetor->valores[k] = vetorR[j];
        j++;
        k++;
    }
}

void merge_sort(Float_Vector *vetor, long int esquerdo, long int direito)
{

    if (esquerdo < direito)
    {
        long int meio = esquerdo + (direito - esquerdo) / 2;
        merge_sort(vetor, esquerdo, meio);
        merge_sort(vetor, meio + 1, direito);
        merge(vetor, esquerdo, meio, direito);
    }
}

/**
 * @brief função do bubble_sort com melhorias realizadas.
 *
 * @param tamanho, recebe o tamanho do vetor.
 * @param vetor, recebe o vetor.
 *
 **/
void bubble(Float_Vector *vetor, long int tamanho)
{

    for (int i = 0; i < tamanho - 1; i++)
    {
        for (int j = 0; j < tamanho - 1; j++)
        {

            if (vetor->valores[j] > vetor->valores[j + 1])
            {

                swap(&vetor->valores[j], &vetor->valores[j + 1]);
            }
        }
    }
}
/**
 * @brief função do insertionSort com melhorias realizadas.
 *
 * @param tamanho, recebe o tamanho do vetor.
 * @param vetor, recebe o vetor.
 *
 **/
void insertionSort(Float_Vector *vetor, long int tamanho)
{
    long int i, j, atual;

    for (i = 1; i < tamanho; i++)
    {

        // Elemento atual em análise
        atual = vetor->valores[i];

        // Elemento anterior ao analisado
        j = i - 1;

        // Analisando membros anteriores
        while ((j >= 0) && (atual < vetor->valores[j]))
        {

            // Posiciona os elmeentos uma posição para frente
            vetor->valores[j + 1] = vetor->valores[j];

            // Faz o j andar para trás
            j = j - 1;
        }

        // Agora que o espaço foi aberto, colocamos o atual (Menor número) na posição correta
        vetor->valores[j + 1] = atual;
    }
}