#include <stdio.h>
#include "List.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define var __auto_type


int main() {


    int d = 4;
    List *list = List_Create(&d, sizeof(int)); // create list with integer data

    int y = 23;
    List_Append(list, (void *) &y, sizeof(int *));

    int m = 28;
    List_Insert(list, (void *) &m, sizeof(int *), 1);


    Node *cur = list->head;
    while (cur != NULL) {
        int *dat = (int *) cur->data;
        printf("%d\n", *dat);
        cur = cur->next;
    }

    return 0;
}
