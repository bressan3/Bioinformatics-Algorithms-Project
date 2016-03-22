//
//  QuickSort.c
//  QuickSort
//
//  Created by Lucas Bressan on 3/21/16.
//  Copyright © 2016 Lucas Bressan. All rights reserved.
//

#include <stdio.h>


void swap(int *num1, int *num2){
    int numAux = *num1;
    *num1 = *num2;
    *num2 = numAux;
}

int divide(int *numArray, int start, int end){
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

void quickSort(int *numArray, int start, int end){
    if(start < end){
        int p = divide(numArray, start, end);
        quickSort(numArray, start, p - 1);
        quickSort(numArray, p + 1, end);
    }
}