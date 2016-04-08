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

/* Gets three random positions from numArray in between start and end
 and then returns the the position that holds median value between those three */
void getBestRandomPosition(int *numArray, int start, int end);

/* "Divides" the list. Returns the index where the list was divided (pivot)
 Also swaps the numbers so they get in their proper order */
int divide(int *numArray, int start, int end);

/* "Divides" a list and by calling divide() and quickSort() recursevely
 and puts the elements from the array in the proper order */
void quickSort(int *numArray, int start, int end);


#endif /* QuickSort_h */
