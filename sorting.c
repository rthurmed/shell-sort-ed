#include <stdio.h>

#define ARRAY_SIZE 8

void printArray(int vetor[], int tamanho, int indexA, int indexB)
{
    int i = 0;
    for (i = 0; i < tamanho; i++)
    {
        if(i == indexA || i == indexB) printf("[%i] ", vetor[i]);
        else printf("%i ", vetor[i]);
    }
    printf("\n");
}

void shellSort(int vetor[], int tamanho)
{
    int h;      // Incremento de shell
    int i;      // Indice da direita
    int j;      // Indice da esquerda
    int aux;    // Variável auxiliar

    // Cálculo do incremento de shell
    h = 1;
    while (h < tamanho)
    {
        h = 3 * h + 1;
    }

    // Loop de alteração do incremento de shell
    while (h > 0)
    {
        printf("\nh: %i\narray:\t", h);
        printArray(vetor, tamanho, -1, -1);
        // Avança o indice da direita
        for (i = h; i < tamanho; i++)
        {
            j = i - h;
            printf("\t");
            printArray(vetor, tamanho, j, i);
            // Compara as duas posições
            if (vetor[j] > vetor[i])
            {
                printf("%i > %i\t", vetor[j], vetor[i]);
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
                printArray(vetor, tamanho, j, i);
            }
        }
        // Atualiza o valor do incremento de shell
        h = h / 3;
    }
}

int main()
{
    int v[ARRAY_SIZE] = {5, 4, 7, 8, 3, 2, 9, 1};
    printf("Array não ordenado: ");
    printArray(v, ARRAY_SIZE, -1, -1);
    printf("Ordenando...\n");
    shellSort(v, ARRAY_SIZE);
    printf("\nArray ordenado: ");
    printArray(v, ARRAY_SIZE, -1, -1);
    return 0;
}