//
// Created by vova- on 10/13/2021.
//
#include <stdio.h>
#include <stdlib.h>

#include "../include/count.h"

int comp (const int* elem1, const int* elem2)
{
    if (*elem1 > *elem2) return  1;
    if (*elem1 > *elem2) return -1;
    return 0;
}

int*** histogram (int* arr[], int size) {

    qsort(arr, size, sizeof(int*), comp);

    int *list[size];
    int *histo[size];
    int ind = 0;
    int count;

    for (int i = 0; i<size;){
        *(list[ind]) = *(arr[i]);
        count = 1;
        while (*(arr[i+count]) == *(arr[i+count-1])) {
            count++;
            if (i+count+2 >= size){
                break;
            }
        }
        i += count;
        *(histo[ind - 1]) = count;
        ind++;
    }

    int** result[2];

    result[0] = list;
    result[1] = histo;

    return  result;
}