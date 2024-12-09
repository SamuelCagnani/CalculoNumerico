/*
    Samuel de Mello Cagnani 
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

    // Gauss Parcial
    float m;
    for(int i = 0; i < dimensao - 1; i++)
    {
        // Pivo
        int max = i;
        for(int j = i + 1; j < dimensao; j++)
        {
            if(fabs(matriz[j][i]) > fabs(matriz[max][i]))
                max = j;
        }

        if(max != i)
        {
            for(int k = 0; k < dimensao; k++)
            {
                float temp = matriz[i][k];
                matriz[i][k] = matriz[max][k];
                matriz[max][k] = temp;
            }

            float temp = termosIndependentes[i];
            termosIndependentes[i] = termosIndependentes[max];
            termosIndependentes[max] = temp;
        }

        // Gauss Simples
        for(int j = i + 1; j < dimensao; j++)
        {
            m = -matriz[j][i] / matriz[i][i];
            termosIndependentes[j] += m * termosIndependentes[i];
            for(int k = 0; k < dimensao; k++)
                matriz[j][k] += m * matriz[i][k];
        }
    }

    // Retro Solução 
    for(int i = dimensao - 1; i >= 0; i--)
    {
        auxiliar = 0;
        for(int j = i + 1; j < dimensao; j++)
            auxiliar += matriz[i][j] * resultante[j];

        resultante[i] = (termosIndependentes[i] - auxiliar) / matriz[i][i];
    }

    printf("\n----------RESULTADOS----------\n");

    for(int i = 0; i < dimensao; i++)
        printf("resultado[%d] = %.3f\n", i + 1, resultante[i]);

    return 0;
}