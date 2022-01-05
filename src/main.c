#include <stdio.h>

#include "../include/input.h"
#include "../include/count.h"

int main() {
    int size = inputInt();
    int** numbers = inputArrIntP(size);

    printf("Hello, World!\n");
    printf("%i", *numbers[1]);

    int*** res = histogram(numbers, size);
    for (int i = 0; i < size; i++) {
        printf("%i : %i", *res[0][i], *res[1][i]);
    }


    return 0;
}
