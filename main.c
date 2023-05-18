#include <stdio.h>
#include "List.h"

/// Prints out the node data as an int
/// \param node
void PrintNode(Node * node){
    int *dat = (int *) node->data;

    //Print it
    printf("%d\n", *dat);
}

int main() {

    //Create and initialize the list with the int d
    int d = 4;
    List *list = List_Create(&d, sizeof(int));

    //Append it with 23
    int y = 23;
    List_Append(list, (void *) &y, sizeof(int));

    //Insert at 1 with 28
    int m = 28;
    List_Insert(list, (void *) &m, sizeof(int), 1);

    //Iterate through the list
    List_Iterate(list, PrintNode);

    //Print out hte index of y
    printf("%d",List_Contains(list, (void *) &y, sizeof(int)));

    //Destroy the list
    List_Destroy(list);

    return 0;
}
