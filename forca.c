#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ERROS 6

int desenho(int erros) {
    if (erros == 0) {
        printf(" ____\n|    |\n|   \n|  \n|    \n|\n|\n");
    } else if (erros == 1) {
        printf(" ____\n|    |\n|    O\n|  \n|    \n|\n|\n");
    } else if (erros == 2) {
        printf(" ____\n|    |\n|    O\n|    |\n|    \n|\n|\n");
    } else if (erros == 3) {
        printf(" ____\n|    |\n|    O\n|    |\n|   /\n|\n|\n");
    } else if (erros == 4) {
        printf(" ____\n|    |\n|    O\n|    |\n|   / \\\n|\n|\n");
    } else {
        printf(" ____\n|    |\n|    O\n|   /|\n|   / \\\n|\n|\n");
    }
    return 0;
}

int main(int argc, char *argv[0]) {
    
    system("cls || clear");

    if (argc != 2) {
        printf("Digite: %s <nomedoarquivo>\n", argv[0]);
    return 1;
    }

    char *filename = argv[1];
    FILE *fp = fopen(filename, "r");

    if (!fp) {
        printf("Erro: não consigo abrir esse arquivo %s\n", filename);
    return 1;
    }

    int n;
    fscanf(fp, "%d\n", &n);

    char palavra[20], palavraMascarada[20], letra, vet[] = "         ";
    int i, tamanhoPalavra, erros = 0, acertos = 0, jaDigitou = 0;
    srand(time(NULL));

    (fgets(palavra, sizeof(palavra) - 1, fp));

    int aleatorio = rand() % n;

    for (int i = 1; i <= aleatorio; i++) {
        if (fgets(palavra, sizeof(palavra), fp) == NULL) {
            printf("Erro ao ler a linha %d do arquivo!\n", aleatorio);
            return 1;
        }
    }

    tamanhoPalavra = strlen(palavra) - 1;
    for (i = 0; i < tamanhoPalavra; i++) {
        palavraMascarada[i] = '_';
    }
    palavraMascarada[i] = '\0';

    printf("Bem-vindo ao jogo da forca!\n");
    printf("A palavra tem %d letras.\n\n", tamanhoPalavra);

    while (erros < MAX_ERROS && acertos < tamanhoPalavra) {
        desenho(erros);

        printf("Palavra: %s\n", palavraMascarada);
        printf("Tentativas restantes: %d\n", MAX_ERROS - erros);
        printf(" %s ", vet);
        printf("\nDigite uma letra: ");
        scanf(" %c", &letra);
        system("cls || clear");

        if (!isalpha(letra)) {
            printf("Entrada invalida! Digite uma letra.\n");
            continue;
        }

        letra = tolower(letra);
        jaDigitou = 0;

        for (i = 0; i < tamanhoPalavra; i++) {
            if (palavra[i] == letra) {
                if (palavraMascarada[i] != '_') {
                    printf("Voce ja digitou essa letra! Tente novamente.\n");
                    jaDigitou = 1;
                }
                palavraMascarada[i] = letra;
                acertos++;
            }
        }

        if (!jaDigitou && !strchr(palavra, letra)) {
            vet[2*erros] = letra;
            vet[2*erros-1] = '-';
            erros++;
            printf("Letra incorreta! Tente novamente.\n");
        }

        printf("\n");
    }
    
    system("cls || clear");
    if (acertos == tamanhoPalavra) {
        printf("Voce acertou! A palavra era: %s\n", palavra);
    } else {
        printf("Voce perdeu! A palavra era: %s\n", palavra);
    }

    return 0;
}
