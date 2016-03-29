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
#include <ctype.h>
#include "List.h"
#include "QuickSort.h"


int main(int argc, const char * argv[]) {
    
    printf("Reading File...\n");
    FILE *file;
    
    
    // Must be an absolute path
    file = fopen("/Users/Lucas/Documents/Github/Bioinformatics Algorithms/QuickSort/in.txt", "r");
    if (file == NULL) {
        printf("File not found!");
        exit(-1);
    }
    
    char line[128];
    List *numList = createList();
    
    while(fgets (line, sizeof line, file) != NULL){
        if (isdigit(line[0]))
            addValue(numList, atoi(line));
    }
    
    fclose(file);
    
    int *numArray = convertToArray(numList);
    
    // Must be an absolute path
    file = fopen("/Users/Lucas/Documents/Github/Bioinformatics Algorithms/QuickSort/out.txt", "w");
    fprintf(file, "Ordered sequence:\n\n");
    
    printf("QuickSort: ");
    quickSort(numArray, 0, numList->size - 1);
    for (int i = 0; i < numList->size; i++) {
        fprintf(file, "%d\n", numArray[i]);
        printf("%d ", numArray[i]);
    }printf("\n");
    
    fclose(file);
    
    free(numList);
    free(numArray);
    
    printf("Done! Press any key to exit.");
    getchar();
    
    return 0;
}
