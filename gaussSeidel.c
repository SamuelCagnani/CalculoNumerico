/*
    Samuel de Mello Cagnani 
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() 
{
    int dimensao, maxIteracoes;
    printf("Digite a ordem da matriz: ");
    scanf("%d", &dimensao);

    float matriz[dimensao][dimensao];
    float termosIndependentes[dimensao];  // Vetor B original
    float resultante[dimensao];           // Vetor X (solucao atual)
    float bAtual[dimensao];               // Vetor B atual (calculado como A * X)

    // Inicializar chute inicial com zeros
    for (int i = 0; i < dimensao; i++)
        resultante[i] = 0.0;

    // Ler matriz A
    printf("Digite a matriz:\n");
    for (int i = 0; i < dimensao; i++)
        for (int j = 0; j < dimensao; j++) 
        {
            printf("matriz[%d][%d]: ", i + 1, j + 1);
            scanf("%f", &matriz[i][j]);
        }

    // Ler vetor B original (termos independentes)
    printf("Digite os termos independentes (B original):\n");
    for (int i = 0; i < dimensao; i++) 
    {
        printf("B[%d]: ", i + 1);
        scanf("%f", &termosIndependentes[i]);
    }

    // Número máximo de iterações
    printf("Digite o numero de iteracoes desejadas: ");
    scanf("%d", &maxIteracoes);

    int iteracao = 0;
    float erroNorma2 = 0;

    // Exibir chute inicial
    printf("\nChute Inicial:\n");
    for (int i = 0; i < dimensao; i++)
        printf("x[%d] = %.5f\n", i + 1, resultante[i]);

    // Calcular B inicial (A * X inicial)
    for (int i = 0; i < dimensao; i++) 
    {
        float soma = 0.0;
        for (int j = 0; j < dimensao; j++)
            soma += matriz[i][j] * resultante[j];
        bAtual[i] = soma;
    }

    // Calcular e exibir erro inicial
    erroNorma2 = 0.0;
    for (int i = 0; i < dimensao; i++)
        erroNorma2 += pow(termosIndependentes[i] - bAtual[i], 2);
    erroNorma2 = sqrt(erroNorma2);
    printf("Erro Inicial: %.5f\n", erroNorma2);

    // Iterações do método de Gauss-Seidel
    do 
    {
        printf("\nIteracao %d:\n", iteracao + 1);
        
        for (int i = 0; i < dimensao; i++) 
        {
            float soma = termosIndependentes[i];
            for (int j = 0; j < dimensao; j++) 
            {
                if (i != j)
                    soma -= matriz[i][j] * resultante[j];
            }
            resultante[i] = soma / matriz[i][i];
            printf("x[%d] = %.5f\n", i + 1, resultante[i]);
        }

        // Calcular B atual
        for (int i = 0; i < dimensao; i++) 
        {
            float soma = 0.0;
            for (int j = 0; j < dimensao; j++)
                soma += matriz[i][j] * resultante[j];
            bAtual[i] = soma;
        }

        // Calcular erro 
        erroNorma2 = 0.0;
        for (int i = 0; i < dimensao; i++)
            erroNorma2 += pow(termosIndependentes[i] - bAtual[i], 2);
        erroNorma2 = sqrt(erroNorma2);
        printf("Erro: %.5f\n", erroNorma2);

        iteracao++;
    } while (iteracao < maxIteracoes);

    // Exibir resultados finais
    printf("\n----------RESULTADOS FINAIS----------\n");
    printf("Apos %d iteracoes:\n", maxIteracoes);
    for (int i = 0; i < dimensao; i++)
        printf("x[%d] = %.5f\n", i + 1, resultante[i]);

    return 0;
}
