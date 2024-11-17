/*
    By: Samuel de Mello Cagnani
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
    int dimensao;
    char resposta[4];

    printf("Digite a ordem da matriz: ");
    scanf("%d", &dimensao);

    float matriz[dimensao][dimensao];
    float L[dimensao][dimensao];
    float U[dimensao][dimensao];
    float termosIndependentes[dimensao];
    float y[dimensao];
    float resultante[dimensao];

    // Inicializando L e U
    for (int i = 0; i < dimensao; i++) {
        for (int j = 0; j < dimensao; j++) {
            L[i][j] = (i == j) ? 1 : 0;
            U[i][j] = 0;
        }
    }

    // Lendo a matriz
    printf("Digite a matriz:\n");
    for(int i = 0; i < dimensao; i++) {
        for(int j = 0; j < dimensao; j++) {
            printf("matriz[%d][%d]: ", i + 1, j + 1);
            scanf("%f", &matriz[i][j]);
        }
    }

    do {
        printf("Digite os termos independentes:\n");
        for(int i = 0; i < dimensao; i++) {
            printf("termos[%d]: ", i + 1);
            scanf("%f", &termosIndependentes[i]);
        }

        // Decomposição LU
        for (int i = 0; i < dimensao; i++) {
            for (int j = i; j < dimensao; j++) {
                float soma = 0;
                for (int k = 0; k < i; k++)
                    soma += L[i][k] * U[k][j];
                U[i][j] = matriz[i][j] - soma;
            }
            for (int j = i + 1; j < dimensao; j++) {
                float soma = 0;
                for (int k = 0; k < i; k++)
                    soma += L[j][k] * U[k][i];
                L[j][i] = (matriz[j][i] - soma) / U[i][i];
            }
        }

        // Exibindo as matrizes L e U
        printf("\nMatriz L:\n");
        for (int i = 0; i < dimensao; i++) {
            for (int j = 0; j < dimensao; j++) {
                printf("%.3f ", L[i][j]);
            }
            printf("\n");
        }

        printf("\nMatriz U:\n");
        for (int i = 0; i < dimensao; i++) {
            for (int j = 0; j < dimensao; j++) {
                printf("%.3f ", U[i][j]);
            }
            printf("\n");
        }

        // Solução de Ly = b (substituição direta)
        for (int i = 0; i < dimensao; i++) {
            float soma = 0;
            for (int j = 0; j < i; j++)
                soma += L[i][j] * y[j];
            y[i] = (termosIndependentes[i] - soma);
        }

        // Exibindo y
        printf("\nVetor y:\n");
        for (int i = 0; i < dimensao; i++) {
            printf("y[%d] = %.3f\n", i + 1, y[i]);
        }

        // Solução de Ux = y (retro solução)
        for (int i = dimensao - 1; i >= 0; i--) {
            float soma = 0;
            for (int j = i + 1; j < dimensao; j++)
                soma += U[i][j] * resultante[j];
            resultante[i] = (y[i] - soma) / U[i][i];
        }

        // Exibindo os resultados
        printf("\n----------RESULTADOS----------\n");
        for (int i = 0; i < dimensao; i++)
            printf("resultado[%d] = %.3f\n", i + 1, resultante[i]);

        // Pergunta para continuar ou encerrar
        printf("\nDeseja inserir novos termos independentes? (sim/nao): ");
        scanf("%s", resposta);

    } while (strcmp(resposta, "sim") == 0);

    printf("Programa encerrado.\n");
    return 0;
}
