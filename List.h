//
// Created by tobin on 4/27/2023.
//
#include <memory.h>

#ifndef LISTTEST__LIST_H
#define LISTTEST__LIST_H

typedef struct Node {
    void *data;
    struct Node *next;
} Node;

typedef struct List {
    Node *head;
    int length;
} List;

#endif //LISTTEST__LIST_H

void List_RemoveAtIndex(List *list, const unsigned int index);

void List_RemoveAtNode(List *list, Node *remove);

void List_Reverse(List *list);

void *List_DataAt(List *list, const int index);

Node *List_NodeAt(List *list, const unsigned int index);

void List_Insert(List *list, const void *inData, const size_t dataSize, const unsigned int index);

void List_Append(List *list, const void *inData, const size_t dataSize);

void List_Print(List *list);

char *List_ToString(List *list, const char *format);

List *List_Create(const void *initialData, const size_t dataSize);

void List_PrintConnections(List *list, const char *format);