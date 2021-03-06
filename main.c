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
    FILE *f;
    
    
    // Must be an absolute path
    f = fopen("/Users/Lucas/Documents/Github/Bioinformatics Algorithms/QuickSort/in.txt", "r+");
    // Checks if file exists in the specified path
    if (f == NULL) {
        printf("File not found!");
        exit(-1);
    }
    
    // Add the values from the file into a linked list
    char line[128];
    List *numList = createList();
    
    while(fgets (line, sizeof line, f) != NULL){
        if (isdigit(line[0]) || (line[0] == '-' && isdigit(line[1])))
            addValue(numList, atoi(line));
    }
    
    fclose(f);
    
    // Converts the linked list to an array
    int *numArray = convertToArray(numList);
    
    // Must be an absolute path
    f = fopen("/Users/Lucas/Documents/Github/Bioinformatics Algorithms/QuickSort/out.txt", "w");
    fprintf(f, "Ordered sequence:\n\n");
    
    // Writes the out.txt file with the final results of our ordering algorithm
    printf("QuickSort: ");
    quickSort(numArray, 0, numList->size - 1);
    for (int i = 0; i < numList->size; i++) {
        fprintf(f, "%d\n", numArray[i]);
        printf("%d ", numArray[i]);
    }printf("\n");
    
    fclose(f);
    
    // Frees alocated memory
    free(numList);
    free(numArray);
    
    printf("Done! Press any key to exit.");
    getchar();
    
    return 0;
}
