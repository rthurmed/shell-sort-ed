#include <stdio.h>

#define MAX_ARRAY_SIZE 50
#define DEBUG 1

void printArray(int vetor[], int tamanho, int indexA, int indexB)
{
    int i = 0;
    for (i = 0; i < tamanho; i++)
    {
        if (i == indexA || i == indexB)
            printf("[%i]", vetor[i]);
        else
            printf(" %i ", vetor[i]);
    }
    printf("\n");
}

void shellSort(int vetor[], int tamanho)
{
    int h;   // Incremento de shell
    int i;   // Indice do vetor
    int j;   // Indica a nova posição do valor comparado
    int aux; // Variável auxiliar

    // Cálculo do incremento de shell
    h = 1;
    while (h <= tamanho / 3)
    {
        h = 3 * h + 1;
    }

    // Loop de alteração do incremento de shell
    while (h > 0)
    {
        if (DEBUG)
        {
            printf("\nh: %i\narray:\t", h);
            printArray(vetor, tamanho, -1, -1);
        }
        // Avança o indice da direita
        for (i = h; i < tamanho; i++)
        {
            aux = vetor[i];
            j = i; // j parte da posição i
            if (DEBUG)
            {
                printf("\t");
                printArray(vetor, tamanho, i - h, i);
            }
            // Fica em loop até encontrar a posição adequada
            while (j > h - 1               // j - h precisa estar no vetor
                   && vetor[j - h] >= aux) // j - h precisa ser menor que o valor a ser movido
            {
                if (DEBUG)
                    printf("%i > %i\t", vetor[j - h], aux);

                vetor[j] = vetor[j - h]; // Copia o valor anterior pro indice candidato
                j = j - h;               // Move o indice candidato h posição para trás

                if (DEBUG)
                {
                    vetor[j] = aux;
                    printArray(vetor, tamanho, j, i);
                }
            }
            // Atribui o valor à nova posição
            vetor[j] = aux;
        }
        // Atualiza o valor do incremento de shell
        h = h / 3;
    }
}

int main()
{
    // int array[8] = {5, 4, 7, 8, 3, 2, 9, 1}, t = 8;
    int array[MAX_ARRAY_SIZE], t = 0, in = 0;
    printf("Insira números para o array a ser ordenado: (-1 para terminar)\n");
    scanf("%i", &in);
    while (t < MAX_ARRAY_SIZE && in >= 0)
    {
        array[t] = in;
        t++;
        scanf("%i", &in);
    }
    printf("Array não ordenado: ");
    printArray(array, t, -1, -1);
    printf("Ordenando...\n");
    shellSort(array, t);
    printf("\nArray ordenado: ");
    printArray(array, t, -1, -1);
    return 0;
}