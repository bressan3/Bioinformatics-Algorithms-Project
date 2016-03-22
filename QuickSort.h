//
//  QuickSort.h
//  QuickSort
//
//  Created by Lucas Bressan on 3/21/16.
//  Copyright © 2016 Lucas Bressan. All rights reserved.
//

#ifndef QuickSort_h
#define QuickSort_h

// Get pointers to num1 and num2 and invert the values
void swap(int *num1, int *num2);

int divide(int *numArray, int start, int end);

void quickSort(int *numArray, int start, int end);


#endif /* QuickSort_h */
