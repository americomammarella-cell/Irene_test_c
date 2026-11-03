
#include <stdio.h>

int main(void) {

    int i;

    for (i = 1; i <= 100; i++) {

        printf("Esamino il numero: %d\n", i);

        if (i % 7 == 0) {
            printf("\nTrovato! Il numero e' %d\n", i);
            break;
        }
    }

    printf("\nCiclo terminato. Valore finale di i = %d\n", i);

    return 0;
}
