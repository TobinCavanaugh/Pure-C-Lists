#include <stdio.h>
#include "List.h"

void Iter(Node * node){
    int *dat = (int *) node->data;

    //Print it
    printf("%d\n", *dat);
}

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

    List_Iterate(list, Iter);

    int a = 12;
    printf("\n%d",List_Contains(list, (void *) &d, sizeof(int)));


    List_Clear(list);

    return 0;
}
