#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ERROS 6
#define NUM_PALAVRAS 33

char palavras[NUM_PALAVRAS][33] =
{

    "axioma",
    "azulejo",
    "blitz",
    "catarro",
    "cocar",
    "crespo",
    "cripta",
    "duplex",
    "fucsia",
    "girar",
    "gnostico",
    "haicai",
    "hera",
    "hífen",
    "ictericia",
    "indigno",
    "intrigante",
    "jazz",
    "linfa",
    "marfim",
    "onix",
    "psique",
    "quartzo",
    "quiz",
    "quorum",
    "tonto",
    "torpor",
    "valsa",
    "vaporizar",
    "vertiginoso",
    "vicissitude",
    "vortice",
    "xilofone"

};

int main()
{
    char palavra[20], palavraMascarada[20], letra, vet[6];
    int i, tamanhoPalavra, erros = 0, acertos = 0, jaDigitou = 0;
    srand(time(NULL));

    strcpy(palavra, palavras[rand() % NUM_PALAVRAS]);

    tamanhoPalavra = strlen(palavra);
    for (i = 0; i < tamanhoPalavra; i++)
    {
        palavraMascarada[i] = '_';
    }
    palavraMascarada[i] = '\0';

    printf("Bem-vindo ao jogo da forca!\n");
    printf("A palavra tem %d letras.\n\n", tamanhoPalavra);

    while (erros < MAX_ERROS && acertos < tamanhoPalavra)
    {
        if(erros == 0)
        {
            printf(" ____\n|    |\n|   \n|  \n|    \n|\n|\n");
        }
        else if(erros == 1)
        {
            printf(" ____\n|    |\n|    O\n|  \n|    \n|\n|\n");
        }
         else if(erros == 2)
        {
            printf(" ____\n|    |\n|    O\n|    |\n|    \n|\n|\n");
        }
         else if(erros == 3)
        {
            printf(" ____\n|    |\n|    O\n|   /|\n|    \n|\n|\n");
        }
         else if(erros == 4)
        {
            printf(" ____\n|    |\n|    O\n|   /|\\\n|    \n|\n|\n");
        }
         else if(erros == 5)
        {
            printf(" ____\n|    |\n|    O\n|   /|\\\n|   /\n|\n|\n");
        }

        printf("Palavra: %s\n", palavraMascarada);
        printf("Tentativas restantes: %d\n", MAX_ERROS - erros);
        printf(" %s ", vet);
        printf("\nDigite uma letra: ");
        scanf(" %c", &letra);
        system("clear");

        if (!isalpha(letra))
        {
            printf("Entrada inválida! Digite uma letra.\n");
            continue;
        }

        letra = tolower(letra);
        jaDigitou = 0;

        for (i = 0; i < tamanhoPalavra; i++)
        {
            if (palavra[i] == letra)
            {
                if (palavraMascarada[i] != '_')
                {
                    printf("Você já digitou essa letra! Tente novamente.\n");
                    jaDigitou = 1;
                    break;
                }
                palavraMascarada[i] = letra;
                acertos++;
            }
        }

        if (!jaDigitou && !strchr(palavra, letra))
        {
            vet[erros]=letra;
            erros++;
            printf("Letra incorreta! Tente novamente.\n");
        }

        printf("\n");
    }

    if (acertos == tamanhoPalavra)
    {
        printf("Você conseguiu!!! A palavra era: %s\n", palavra);
    }
    else
    {
        printf("Você perdeu! A palavra era: %s\n", palavra);
    }

    return 0;
}
