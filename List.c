//
//  List.c
//  QuickSort
//
//  Created by Lucas Bressan on 3/17/16.
//  Copyright © 2016 Lucas Bressan. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "List.h"

//Creates an empty list so we can start populating it with values
List* createList(){
    List *list = malloc(sizeof(List));
    list->start = NULL;
    list->size = 0;
    
    return list;
}

Node* createNode(int value){
    Node *newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    
    return newNode;
}

void addValue(List* list, int value){
    Node *curNode = list->start;
    Node *newNode = createNode(value);
    if (curNode == NULL) {
        list->start = newNode;
    }
    else{
        while (curNode->next != NULL) {
            curNode = curNode->next;
        }
        curNode->next = newNode;
    }
    list->size++;
}

Node* nextNode(Node* curNode){
    return curNode->next;
}

int* convertToArray(List *list){
    int *numArray = malloc(sizeof(list->size));
    Node *curNode = list->start;
    for (int i = 0; i < list->size; i++) {
        numArray[i] = curNode->value;
        curNode = nextNode(curNode);
    }
    
    return numArray;
}

void printList(List *list){
    Node *curNode = list->start;
    while (curNode != NULL) {
        printf("%d, ", curNode->value);
        curNode = nextNode(curNode);
    }
}