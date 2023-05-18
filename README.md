# Pure-C-Lists
A simple pure C .h and .c file for generic-ish linked lists.


Pure C Lists is based off the concept of void pointers (void \*) meaning that theoretically you can have mix and matched lists if you wish.

The main idea behind using void pointers is that any node can contain any data. As C doesn't contain generics, void pointers are an admittedly dangerous solution, so wear steel toed boots!

These methods have been tested, though I would NOT call them production ready.

There are methods for printing the data out, but as we are using void pointers, it's hard for me to predict what you will put in there, so its best to just write your own, luckily its pretty easy.




## Example:

```
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

```
```
4
28
23
2 
Process finished with exit code 0
```


## Building with Pure C lists
Quite honestly I'm brand new to this, but it doesn't contain any weirdness to my understanding. You're best bet is likely just to toss the list.c and list.h files into your project.

I use cmake, and heres an example of what my cmake file looks like:
```
cmake_minimum_required(VERSION 3.25)
project(PureCLists C)

set(CMAKE_C_STANDARD 23)

add_executable(PureCLists main.c List.c)
```

#### Methods:
![image showing the methods of the list.h file](git/header.png? "Methods")

#### Structs:
![image structs in the list.h file](git/typedef.png? "Structs")

I began learning C about 5 days ago as of this readme, so let me know if any of my code contains memory leaks or just bad ideas.
