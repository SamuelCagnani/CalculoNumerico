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
    int ordemColunas[dimensao];  // Para definir a ordem das colunas

    // Inicializa a ordem das colunas
    for(int i = 0; i < dimensao; i++)
        ordemColunas[i] = i;

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

    // Gauss com Pivoteamento Total
    for(int i = 0; i < dimensao - 1; i++)
    {
        // Encontra o maior elemento em valor absoluto para o pivô
        int maxLinha = i;
        int maxColuna = i;
        for(int j = i; j < dimensao; j++)
        {
            for(int k = i; k < dimensao; k++)
            {
                if(fabs(matriz[j][k]) > fabs(matriz[maxLinha][maxColuna]))
                {
                    maxLinha = j;
                    maxColuna = k;
                }
            }
        }

        // Troca as linhas, só se precisar
        if(maxLinha != i)
        {
            for(int k = 0; k < dimensao; k++)
            {
                float temp = matriz[i][k];
                matriz[i][k] = matriz[maxLinha][k];
                matriz[maxLinha][k] = temp;
            }
            // Troca os termos independentes
            float temp = termosIndependentes[i];
            termosIndependentes[i] = termosIndependentes[maxLinha];
            termosIndependentes[maxLinha] = temp;
        }

        // Troca as colunas, só se precisar
        if(maxColuna != i)
        {
            for(int k = 0; k < dimensao; k++)
            {
                float temp = matriz[k][i];
                matriz[k][i] = matriz[k][maxColuna];
                matriz[k][maxColuna] = temp;
            }
            // Atualiza a ordem das colunas
            int temp = ordemColunas[i];
            ordemColunas[i] = ordemColunas[maxColuna];
            ordemColunas[maxColuna] = temp;
        }

        // Gauss Simples
        for(int j = i + 1; j < dimensao; j++)
        {
            float m = -matriz[j][i] / matriz[i][i];
            termosIndependentes[j] += m * termosIndependentes[i];
            for(int k = i; k < dimensao; k++)
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

    // Reordena o resultado de acordo com a troca de colunas
    float resultadoFinal[dimensao];
    for(int i = 0; i < dimensao; i++)
        resultadoFinal[ordemColunas[i]] = resultante[i];

    printf("\n----------RESULTADOS----------\n");

    for(int i = 0; i < dimensao; i++)
        printf("resultado[%d] = %.3f\n", i + 1, resultadoFinal[i]);

    return 0;
}