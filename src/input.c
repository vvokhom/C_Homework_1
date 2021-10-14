//
// Created by vova- on 10/13/2021.
//

#include "../include/input.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define STR_LIMIT 10
#define MAX_INT 2147483646

bool isStrInt (char* str) { //Можно ли перевести сторку(хотя бы начало) в Int - до 9ти знаков
       return ((isdigit(str[0]) || str[0] ==  '-') && (strlen(str) < 10));
}

int inputInt() {

    char temp[STR_LIMIT];

    fgets(temp, STR_LIMIT, stdin);



    while (!isStrInt(temp)) {
        printf("Ошибка!\nПопробуйте снова:\n");
        fgets(temp, STR_LIMIT, stdin);
    }

    char* endptr; //Не применяется
    int result = strtol(temp, &endptr, 10);

    /*free(&endptr);
    free(&temp); */

    return result;

}

int* inputArrInt(int size) {
    int *numbers;



    numbers = malloc(size * sizeof(*numbers));

    for (int i=0; i<size; i++){
       numbers[i] = inputInt();
    }


    return numbers;

}

int** inputArrIntP(int size) {
    int *numbers;
    numbers = malloc(size * sizeof(*numbers));

    int** pointers;
    pointers = malloc(size * sizeof(*pointers));

    for (int i=0; i<size; i++){
        numbers[i] = inputInt();
        pointers[i] = &numbers[i];
    }


    return pointers;

}
