//
//  main.c
//  QuickSort
//
//  Created by Lucas Bressan on 3/16/16.
//  Copyright © 2016 Lucas Bressan. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "List.h"


void swap(int *num1, int *num2){
    int numAux = *num1;
    *num1 = *num2;
    *num2 = numAux;
}

int particiona(int *numArray, int start, int end){
    int pivot = numArray[end];
    int wallIndex = start;
    for (int i = start; i < end; i++) {
        if (numArray[i] <= pivot) {
            swap(&numArray[i], &numArray[wallIndex]);
            wallIndex++;
        }
    }
    swap(&numArray[wallIndex], &numArray[end]);
    return wallIndex;
}

void quickSort(int vet[], int inicio, int fim){
    if(inicio < fim){
        int p = particiona(vet, inicio, fim);
        quickSort(vet, inicio, p - 1); //particiona o vetor antes do pivo (indice final p - 1).
        quickSort(vet, p + 1, fim); //particiona o vetor depois do pivo (indice inicial p + 1).
    }
}

int main(int argc, const char * argv[]) {
    
    List *numList = createList();
    char keyboardInput[10];
    while (true) {
        printf("Enter a value for the list. Type end to finish: ");
        gets(keyboardInput);
        if (strcmp(keyboardInput, "end")) {
            addValue(numList, atoi(keyboardInput));
        } else break;
    }
    
    int *numArray = malloc(sizeof(numList->size));
    numArray = convertToArray(numList);
    
    printf("QuickSort: ");
    
    quickSort(numArray, 0, numList->size - 1);
    for (int i = 0; i < numList->size; i++) {
        printf("%d ", numArray[i]);
    }printf("\n");
    
    free(numList);
    free(numArray);
    
    return 0;
}
