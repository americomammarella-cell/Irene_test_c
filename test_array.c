
#include <stdio.h>
#include <string.h>

int main(void) {

    char parola[100];
    char lettere[100];
    int num_lettere[100];
    int num_nl, numero, i, j;

    num_nl = 0;

    printf("Inserisci la parola...\n");
    scanf("%99s", parola);

    for (i = 0; i < 100; i++)
        num_lettere[i] = 0;

    for (i = 0; i < strlen(parola); i++) {
        for (j = 0; j < num_nl; j++) {
            if (lettere[j] == parola[i]) {
                num_lettere[j]++;
                break;
            }
        }
        if (j == num_nl) {  
            lettere[num_nl] = parola[i];
            num_lettere[num_nl] = 1;
            num_nl++;
        }
    }

    printf("\nElenco delle lettere e numerosita' nella stringa inserita:\n");
    for (j = 0; j < num_nl; j++) {
        printf("Lettera '%c': %d volte\n", lettere[j], num_lettere[j]);
    }

    return 0;
}
