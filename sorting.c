#include <stdio.h>

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
        // Avança o indice da direita
        for (i = h; i < tamanho; i++)
        {
            j = i - h;
            // Compara as duas posições
            if (vetor[j] > vetor[i])
            {
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
        // Atualiza o valor do incremento de shell
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
    printf("Array não ordenado: ");
    printArray(v, 8);
    printf("Ordenando...\n");
    shellSort(v, 8);
    printf("Array ordenado: ");
    printArray(v, 8);
    return 0;
}