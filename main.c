#include <stdio.h>
#include "List.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define var __auto_type


int main() {


    char dat[10] = "head";

    var list = List_Create(dat, strlen(dat) + 1);


    for (int i = 0; i < 4; i++) {

        sprintf(dat, "%d", i + 1);

        List_Append(list, (void *) dat, sizeof(int *));
    }

    printf("%d\n", list->length);

    List_Print(list);

    printf("\n");

    char nDat[10] = "new Data";
    List_Insert(list, nDat, sizeof(nDat) + 1, 0);


    List_Print(list);

    return 0;
}
