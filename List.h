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

List* createList();

Node* createNode(int value);

void addValue(List* list, int value);

Node* nextNode(Node* curNode);

int* convertToArray(List *list);

void printList(List *list);

#endif /* List_h */
