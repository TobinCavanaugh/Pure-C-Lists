#include <stdio.h>
#include "List.h"

int main() {

    //Create and initialize the list with the int d
    int d = 4;
    List *list = List_Create(&d, sizeof(int)); // create list with integer data

    //Append it with 23
    int y = 23;
    List_Append(list, (void *) &y, sizeof(int *));

    //Insert at 1 with 28
    int m = 28;
    List_Insert(list, (void *) &m, sizeof(int *), 1);

    //Get the head of the node
    Node *cur = list->head;

    //Iterate through the nodes until we run out, you could also use list->length
    while (cur != NULL) {
        //Get the int pointer in the current nodes data
        int *dat = (int *) cur->data;

        //Print it
        printf("%d\n", *dat);

        //Move to the next node
        cur = cur->next;
    }

    return 0;
}
