#include <stdio.h>

void shellSort(int vetor[], int tamanho)
{
    int h;      // Incremento de shell
    int i;      // Indice da esquerda
    int j;      // Indice da direita
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
        for (i = h; i < tamanho; i++)
        {
            for (j = 0; j < tamanho - h; j++)
            {
                if (vetor[i] < vetor[j])
                {
                    aux = vetor[i];
                    vetor[i] = vetor[j];
                    vetor[j] = aux;
                }
            }
        }
        h = h / 3;
    }
}

void printArray(int vetor[], int tamanho)
{
    int i = 0;
    for (i = 0; i < tamanho; i++)
    {
        printf("%i ", vetor[i]);
    }
    printf("\n");
}

int main()
{
    int v[] = {5, 4, 7, 8, 3, 2, 9, 1};
    printf("Array não ordenado:");
    printArray(v, 8);
    printf("Ordenando...\n");
    shellSort(v, 8);
    printf("Array ordenado:");
    printArray(v, 8);
    return 0;
}