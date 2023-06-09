
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


void List_Append(List *list, const void *inData, const size_t dataSize);

void List_Clear(List *list);

int List_Contains(List *list, void *data, size_t size);

List *List_Create(const void *initialData, const size_t dataSize);

void *List_DataAt(List *list, const int index);

void List_Destroy(List * list);

void List_Insert(List *list, const void *inData, const size_t dataSize, const unsigned int index);

void List_Iterate(List *list, void (*Iterator)(Node *));

Node *List_NodeAt(List *list, const unsigned int index);

void List_PrintConnections(List *list, const char *format);

void List_RemoveAtIndex(List *list, const unsigned int index);

void List_RemoveAtNode(List *list, Node *remove);

void List_Reverse(List *list);

