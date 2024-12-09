/*
    Samuel de Mello Cagnani 
*/

#include <stdio.h>
#include <math.h>

// Definição das funções
float funcao1(float x) {
    return exp(x) - sin(x) - 2; // f(x) = e^x - sin(x) - 2
}

float funcao2(float x) {
    return pow(x, 2) - cos(x); // f(x) = x^2 - cos(x)
}

float funcao3(float x) {
    return x - 2 * sin(x) - 1; // f(x) = x - 2sin(x) - 1
}

float funcao4(float x) {
    return pow(x, 2) - 5; // f(x) = x^2 - 5
}

int main() {
    int escolha;
    float (*funcao)(float); // Ponteiro para a função escolhida
    float a, b, erro, raiz;
    int maxIteracoes, iteracao = 0;

    // Menu para escolher a função
    printf("Escolha a funcao para aproximar a raiz:\n");
    printf("1) f(x) = e^x - sin(x) - 2\n");
    printf("2) f(x) = x^2 - cos(x)\n");
    printf("3) f(x) = x - 2sin(x) - 1\n");
    printf("4) f(x) = x^2 - 5\n");
    printf("Sua escolha: ");
    scanf("%d", &escolha);

    // Associar a função escolhida
    switch (escolha) {
        case 1:
            funcao = funcao1;
            break;
        case 2:
            funcao = funcao2;
            break;
        case 3:
            funcao = funcao3;
            break;
        case 4:
            funcao = funcao4;
            break;
        default:
            printf("Escolha invalida.\n");
            return 1;
    }

    // Leitura dos limites do intervalo
    printf("\nDigite o intervalo [a, b]:\n");
    printf("a: ");
    scanf("%f", &a);
    printf("b: ");
    scanf("%f", &b);

    // Verificar se f(a) * f(b) < 0
    if (funcao(a) * funcao(b) >= 0) {
        printf("Nao ha garantia de raiz no intervalo dado.\n");
        return 1;
    }

    // Ler tolerância de erro e número máximo de iterações
    printf("Digite o erro toleravel: ");
    scanf("%f", &erro);
    printf("Digite o numero maximo de iteracoes: ");
    scanf("%d", &maxIteracoes);

    // Método das Bisseções
    printf("\nIteracoes do Metodo das Bissecoes:\n");
    do {
        // Calcular ponto médio
        raiz = (a + b) / 2.0;
        printf("Iteracao %d: x = %.5f, f(x) = %.5f\n", iteracao + 1, raiz, funcao(raiz));

        // Verificar a condição de parada
        if (fabs(funcao(raiz)) < erro) {
            break;
        }

        // Ajustar intervalo
        if (funcao(a) * funcao(raiz) < 0) {
            b = raiz;
        } else {
            a = raiz;
        }

        iteracao++;
    } while (iteracao < maxIteracoes);

    // Exibir resultado final
    printf("\n----------RESULTADO FINAL----------\n");
    printf("Raiz aproximada: x = %.5f\n", raiz);
    printf("Erro estimado: %.5f\n", fabs(funcao(raiz)));
    printf("Numero de iteracoes: %d\n", iteracao);

    return 0;
}
