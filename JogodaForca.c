#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_ERROS 6

int main() {
    char palavra[100], palavraMascarada[100], letra;
    int i, tamanhoPalavra, erros = 0, acertos = 0, jaDigitou = 0;

    // Escreva a palavra aqui !!!
    strcpy(palavra, "blitz");

    tamanhoPalavra = strlen(palavra);
    for (i = 0; i < tamanhoPalavra; i++) {
        palavraMascarada[i] = '_';
    }
    palavraMascarada[i] = '\0';

    printf("Bem-vindo ao jogo da forca!\n");
    printf("A palavra tem %d letras.\n\n", tamanhoPalavra);

    while (erros < MAX_ERROS && acertos < tamanhoPalavra) {
        printf("Palavra: %s\n", palavraMascarada);
        printf("Tentativas restantes: %d\n", MAX_ERROS - erros);

        printf("Digite uma letra: ");
        scanf(" %c", &letra);

        if (!isalpha(letra)) {
            printf("Entrada inválida! Digite uma letra.\n");
            continue;
        }

        letra = tolower(letra);
        jaDigitou = 0;

        for (i = 0; i < tamanhoPalavra; i++) {
            if (palavra[i] == letra) {
                if (palavraMascarada[i] != '_') {
                    printf("Você já digitou essa letra! Tente novamente.\n");
                    jaDigitou = 1;
                    break;
                }
                palavraMascarada[i] = letra;
                acertos++;
            }
        }

        if (!jaDigitou && !strchr(palavra, letra)) {
            erros++;
            printf("Letra incorreta! Tente novamente.\n");
        }
        printf("\n");
    }

    if (acertos == tamanhoPalavra) {
        printf("Parabéns! Você venceu o jogo da forca.\n");
    } else {
        printf("Você perdeu! A palavra era: %s\n", palavra);
    }

    return 0;
}
