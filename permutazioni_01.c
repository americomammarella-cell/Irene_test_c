
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void scambia(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

int prossimaPermutazione(char s[], int n) {
    int i = n - 2;

    // 1. Cerca da destra il primo carattere
    //    più piccolo del successivo
    while (i >= 0 && s[i] >= s[i + 1])
        i--;

    if (i < 0)
        return 0;  // Non ci sono altre permutazioni

    // 2. Cerca da destra un carattere maggiore di s[i]
    int j = n - 1;
    while (s[j] <= s[i])
        j--;

    // 3. Scambia i due caratteri
    scambia(&s[i], &s[j]);

    // 4. Inverte la parte finale della parola
    int sinistra = i + 1;
    int destra = n - 1;

    while (sinistra < destra) {
        scambia(&s[sinistra], &s[destra]);
        sinistra++;
        destra--;
    }

    return 1;
}

int main(void) {
    char parola[100];
    int num_perm = 0;
   
    printf("Inserisci una parola: ");
    scanf("%99s", parola);

    int n = strlen(parola);

    // Ordina inizialmente la parola
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (parola[i] > parola[j])
                scambia(&parola[i], &parola[j]);
        }
    }

    do {
        printf("%s\n", parola);
        num_perm++;
    } while (prossimaPermutazione(parola, n));

    printf("Numero di permutazioni: %d\n", num_perm);
    return 0;
}