/*
    By: Samuel de Mello Cagnani
*/

#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int dimensao;
    float auxiliar = 0.0;

    printf("Digite a ordem da matriz: ");
    scanf("%d", &dimensao);

    float matriz[dimensao][dimensao];
    float termosIndependentes[dimensao];
    float resultante[dimensao];

    printf("Digite a matriz:\n");
    for(int i = 0; i < dimensao; i++)
        for(int j = 0; j < dimensao; j++)
        {
            printf("matriz[%d][%d]: ", i + 1, j + 1);
            scanf("%f", &matriz[i][j]);
        }
    
    printf("Digite os termos independentes:\n");
    for(int i = 0; i < dimensao; i++)
    {
        printf("termos[%d]: ", i + 1);
        scanf("%f", &termosIndependentes[i]);
    }

    // Retro Solução
    for(int i = dimensao - 1; i >= 0; i--)
    {
        auxiliar = 0;
        for(int j = i + 1; j < dimensao; j++)
            auxiliar += matriz[i][j] * resultante[j];

        resultante[i] = (termosIndependentes[i] - auxiliar) / (float) matriz[i][i];
    }

    printf("\n----------RESULTADOS----------\n");

    for(int i = 0; i < dimensao; i++)
        printf("resultado[%d] = %.2f\n", i + 1, resultante[i]);

    return 0;
}