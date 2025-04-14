#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf(" ,_     _        \n");
    printf(" |\\\\_,-~/        \n");
    printf(" / _  _ |    ,--. \n");
    printf("(  @  @ )   / ,-'\n");
    printf(" \\  _T_/-._( (   BEM VINDOS\n");
    printf(" /         `. \\  AO JOGO DE ADIVINHACAO \n");
    printf("|         _  \\ | \n");
    printf(" \\ \\ ,  /      | \n");
    printf("  || |-_\\__   /  \n");
    printf(" ((_/`(____,-'    \n");    
    int segundos = time(0);
    srand(segundos);

    int nivel;
    printf("Nivel de dificuldade\n");
    printf("(1) Facil  (2) Medio  (3) Dificil\n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);

    int numerosecreto = rand() % 100 + 1;
    int chute;
    int tentativas = 0;
    double pontos = 1000.0;
    int numerotentativa;

    if (nivel == 1) {
        numerotentativa = 20;
    } else if (nivel == 2) {
        numerotentativa = 15;
    } else {
        numerotentativa = 6;
    }

    while (tentativas < numerotentativa) {
        printf("Tentativa %d de %d\n", tentativas + 1, numerotentativa);
        printf("Qual o seu chute? ");
        scanf("%d", &chute);

        if (chute < 0) {
            printf("Voce nao pode chutar numeros negativos!\n");
            continue;
        }

        printf("Seu chute foi %d\n", chute);

        int maior = chute > numerosecreto;
        int acertou = (chute == numerosecreto);

        if (acertou) {
            printf("Parabens! Voce acertou!\n");
            break;
        } else {
            if (tentativas == numerotentativa - 1) {
                printf("Voce errou, tente novamente! Voce nao acertou nas %d tentativas.\n", numerotentativa);
            } else {
                if (maior) {
                    printf("Seu chute foi maior do que o numero secreto!\n");
                } else {
                    printf("Seu chute foi menor do que o numero secreto!\n");
                }
            }
        }

        tentativas++;

        double pontosperdidos = (double)abs(chute - numerosecreto) / 2.0;
        pontos -= pontosperdidos;
    }

    if (tentativas == numerotentativa && chute != numerosecreto) {
        printf("Suas tentativas acabaram, o numero secreto era %d\n", numerosecreto);
    }

    printf("Sua pontuacao final e de %.2f\n", pontos);
    return 0;
}
