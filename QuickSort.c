//
//  QuickSort.c
//  QuickSort
//
//  Created by Lucas Bressan on 3/21/16.
//  Copyright © 2016 Lucas Bressan. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void swap(int *num1, int *num2){
    int numAux = *num1;
    *num1 = *num2;
    *num2 = numAux;
}

int getBestRandomPosition(int *numArray, int start, int end){
    int randomPositions[] = {-1, -1, -1};
    
    /* Assign the three random positions we need to randomPositions[]
     and makes sure that we don't have duplicated positions */
    for (int i = 0; i < 3; i++) {
        int startPositionAux = rand() % (end + 1 - start) + start;
        int j = -1;
        while(true){
            j++;
            if (randomPositions[j] == startPositionAux) {
                startPositionAux = rand() % (end + 1 - start) + start;
                j = -1;
            }
            if (j == 2) {
                break;
            }
        }
        randomPositions[i] = startPositionAux;
    }
    
    //Finding the middle term
    int min, mid = numArray[randomPositions[2]], max;
    if (numArray[randomPositions[0]] > numArray[randomPositions[1]]){
        max = randomPositions[0];
        min = randomPositions[1];
    } else {
        max = randomPositions[1];
        min = randomPositions[0];
    }
    
    if (numArray[randomPositions[2]] > numArray[max]){
        mid = max;
    }
    else if (numArray[randomPositions[2]] < numArray[min])
        mid = min;
    else
        mid = randomPositions[2];
    
    return mid;
}

int divide(int *numArray, int start, int end){
    /* If end - start < 2 it cant get and compare 3 positions so it
     just gets a random pivot in the given range */
    int pivotPostition = rand() % (end + 1 - start) + start;
    if (end - start >= 2) {
        pivotPostition = getBestRandomPosition(numArray, start, end);
    }
    swap(&numArray[end], &numArray[pivotPostition]);
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