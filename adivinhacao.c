#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>    

int numeroAdivinhado, numeroSecreto, tentativas = 0, jogoTerminado = 0, numerodetentativas;
float pontos = 1000;

int main()
{
    srand(time(0)); 
    numeroSecreto = rand() % 100;

    printf("*******************************************\n");
    printf("* Bem vindo ao nosso jogo de adivinhacao! *\n");
    printf("*******************************************\n");

    int nivel;
    printf("Qual o nivel de dificuldade voce pretende jogar: \n1 - Facil \n2 - Medio \n3 - Dificil \n");
    scanf("%i", &nivel);
    while(nivel < 1 && nivel > 3)
    {
        printf("Digite um valor valido:");
        scanf("%i", &nivel);
    }

    if (nivel == 1)
    {
        numerodetentativas = 15;
    }
    else if (nivel == 2)
    {
        numerodetentativas = 10;
    }
    else
    {
        numerodetentativas = 5;
    }

    while (jogoTerminado != 1)
    {
        if (tentativas > numerodetentativas)
        {
            printf("Voce perdeu o jogo! Fez muitas tentativas! \n");
            jogoTerminado = 1;
        }
        else
        {
            printf("Digite o numero que quer chutar : ");
            scanf("%i", &numeroAdivinhado);
            while(numeroAdivinhado < 0)
            {
                printf("Numero Invalido! Digite um numero positivo:");
                scanf("%i", &numeroAdivinhado);
            }

            if (numeroAdivinhado == numeroSecreto)
            {
                tentativas++;
                printf("Parabens! voce encontrou o numero secreto com %.2f pontos e %i tentativas!\n", pontos, tentativas);
                jogoTerminado = 1;
            }
            else
            {
                tentativas++;
                if (numeroSecreto > numeroAdivinhado)
                {
                    printf("Errou! O numero secreto eh maior que o numero digitado!\n");
                }
                else
                {
                    printf("Errou! O numero secreto eh menor que o numero digitado!\n");  
                }

            }
        } 
        pontos = pontos - ( abs( (numeroAdivinhado - numeroSecreto) ) / 2.0 );
    }

    return 0;
}