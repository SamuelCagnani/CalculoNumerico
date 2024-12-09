/*
    Samuel de Mello Cagnani 
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

    // Gauss Jordan
    float m;
    for(int i = 0; i < dimensao; i++)
        for(int j = 0; j < dimensao; j++)
        {
            if(i != j)
            {
                m = (matriz[j][i] * (-1)) / matriz[i][i];
                termosIndependentes[j] += m * termosIndependentes[i];
                for(int k = 0; k < dimensao; k++)
                    matriz[j][k] += (m * matriz[i][k]);
            }    
        }


    // Solução Gauss
    for(int i = 0; i < dimensao; i++)
        resultante[i] = termosIndependentes[i] / matriz[i][i];

    printf("\n----------RESULTADOS----------\n");

    for(int i = 0; i < dimensao; i++)
        printf("resultado[%d] = %.3f\n", i + 1, resultante[i]);

    return 0;
}