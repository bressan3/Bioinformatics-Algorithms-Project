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
#include "QuickSort.h"


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
    
    printf("Done! Press any key to exit.");
    getchar();
    
    return 0;
}
