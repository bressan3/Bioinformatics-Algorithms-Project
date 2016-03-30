//
//  List.h
//  QuickSort
//
//  Created by Lucas Bressan on 3/17/16.
//  Copyright © 2016 Lucas Bressan. All rights reserved.
//

#ifndef List_h
#define List_h

typedef struct sNode{
    struct sNode *next;
    int value;
}Node;

typedef struct sList{
    Node *start;
    int size;
}List;

// Starts a new list
List* createList();

// Creates a new node
Node* createNode(int value);

// Adds a value to a list
void addValue(List* list, int value);

// Returns the next node in relation to curNode
Node* nextNode(Node* curNode);

// Converts the linked list to an array of integers and returns it
int* convertToArray(List *list);

// Prints a linked list node by node in sequence (used for testing purposes)
void printList(List *list);

#endif /* List_h */
