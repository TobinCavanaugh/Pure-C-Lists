//
// Created by tobin on 4/27/2023.
//

#define var __auto_type

#include "List.h"
#include <memory.h>
#include <malloc.h>
#include <stdio.h>

int list_DoLogging = 0;

/// Does a malloc, if list_DoLogging is true then it also prints all the malloc requests it gets
/// \param size
/// \param message
/// \return
void *mallocLog(size_t size, char *message) {
    if (list_DoLogging) {
        printf("\n%s (%zu)", message, size);
    }

    var dat = malloc(size);

    if (dat == NULL) {
        printf("YO, this malloc is returning null in mallocLog in list.c! Get some more memory!");
        return NULL;
    }

    return dat;
}

/// TESTED\n
/// Creates a new list, with the initial data at the head
/// \param initialData
/// \param dataSize
/// \return
List *List_Create(const void *initialData, const size_t dataSize) {

    //Make a new list with default args
    //List newList = {0};
    List *newList = (List *) mallocLog(sizeof(List), "new list malloc");
    newList->head = NULL;
    newList->length = 0;

    //malloc the newhead
    var newHead = (Node *) mallocLog(sizeof(Node), "Creating Head ");

    //malloc the newheads data
    newHead->data = mallocLog(dataSize, "Creating newheads data ");

    //Copy the data into the newhead data
    memcpy(newHead->data, initialData, dataSize);

    //set the newheads next to null
    newHead->next = NULL;

    //set the lists head
    newList->head = newHead;
    newList->length = 1;

    return newList;
}

/// TESTED\n
/// Turns the list into a string
/// \param list
/// \param format First parameter is %s for the data, the second is %d for the index
/// \return
char *List_ToString(List *list, const char *format) {
    // If the list is empty, return NULL
    if (list->length == 0) {
        return NULL;
    }

    //Init the output size to one, for the sake of null terminating characters
    size_t outputSize = 1;

    //This counter is used for the %d formatting option
    size_t counter = 0;

    //Go th
    Node *currentNode = list->head;

    //Calculate the output size using snprintf and our formatting options
    while (currentNode != NULL) {
        outputSize += snprintf(NULL, 0, format, currentNode->data, counter);
        currentNode = currentNode->next;
        counter++;
    }

    // Allocate memory for the output string
    char *outputString = mallocLog(outputSize, "Malloc for the output string");

    //We reset the counter midway through, as it will need to be re-incremented
    counter = 0;

    // Write the data to the output string
    currentNode = list->head;

    size_t bytesWritten = 0;

    while (currentNode != NULL) {
        bytesWritten += snprintf(outputString + bytesWritten, outputSize - bytesWritten, format, currentNode->data,
                                 counter);
        currentNode = currentNode->next;
        counter++;
    }

    return outputString;
}

/// TESTED\n
/// Prints the list gotten from list to string using the format "%s (%d)\n"
/// \param list
void List_Print(List *list) {
    char *strArr = List_ToString(list, "%s (%d)\n");

    printf("%s", strArr);

    free(strArr);
}

/// Prints out the connection in the way you specify, uses printf style so do it based on your datatype
/// \param list
/// \param format Recommended "%s -> "
void List_PrintConnections(List *list, const char *format) {

    var cur = list->head;

    while (cur->next != NULL) {
        printf(format, cur->data);
        cur = cur->next;
    }
}

//// TESTED\n
/// Append to the end of the list, creates a new node
/// \param list
/// \param inData
/// \param dataSize
void List_Append(List *list, const void *inData, const size_t dataSize) {
    // Malloc a new node
    Node *newNode = (Node *) mallocLog(sizeof(Node), "New Node for list append");

    // Malloc newnodes inData
    newNode->data = mallocLog(dataSize, "Malloc new Node data for list append");

    //Copy the inData to the newnodes inData
    memcpy(newNode->data, inData, dataSize);

    //Set the next to NULL
    newNode->next = NULL;

    //If the list length is 0, then this newNode must be the new head
    if (list->length == 0) {
        list->head = newNode;
    }
        //Otherwise
    else {
        //Create a new node, this one is for accessing the youngest node in the list
        Node *accessNode = list->head;

        //Check until there is not a next
        while (accessNode->next != NULL) {
            accessNode = accessNode->next;
        }

        //Set the next to the newest node we just made
        accessNode->next = newNode;
    }

    //Increment the length
    list->length++;
}

/// Inserts into a list at int index
/// \param list
/// \param inData
/// \param dataSize
/// \param index
void List_Insert(List *list, const void *inData, const size_t dataSize, const unsigned int index) {

    //This mallocing is legit
    Node *newNode = (Node *) mallocLog(sizeof(Node), "Malloc the new node");
    newNode->data = mallocLog(dataSize, "Malloc the new data for the new node");
    memcpy(newNode->data, inData, dataSize);

    //if the length is 0, then this will be the only node
    if (list->length == 0) {
        list->head = newNode;
        list->length++;
        return;
    }

    //Out of bounds check
    if (index > list->length) {
        if (list_DoLogging) {
            printf("\n(List_Insert) index %d is out of bounds of list length %d", index, list->length);
        }
        return;
    }

    //if the index is 0, then we are inserting in place of the head
    if (index == 0) {
        newNode->next = list->head;
        list->head = newNode;

        list->length++;
        return;
    }

    //Get the parent and grandchild nodes (maybe you'd say that grandchild should be child instead but that doesnt make any sense it goes parent->child->grandchild not parent->???->child)
    var parent = List_NodeAt(list, index - 1);
    var grandChild = List_NodeAt(list, index);

    parent->next = newNode;
    newNode->next = grandChild;
}

/// TESTED\n
/// Returns a pointer to the node at index
/// \param list
/// \param index
/// \return
Node *List_NodeAt(List *list, const unsigned int index) {

    if (index >= list->length) {
        printf("\n%d out of bounds of %d", index, list->length);
        return NULL;
    }

    var accessNode = list->head;

    //Get the index youngest one
    for (int i = 0; i < index; i++) {
        accessNode = accessNode->next;
    }

    return accessNode;
}

/// TESTED\n
/// Returns the node data at index
/// \param list
/// \param index
/// \return
void *List_DataAt(List *list, const int index) {
    Node *node = List_NodeAt(list, index);

    if (node == NULL) {
        return NULL;
    }

    return node->data;
}

///TESTED\n
/// Reverses the lists order, head becomes tail and vice versa
/// \param list
void List_Reverse(List *list) {
    Node *prevNode = NULL;
    Node *curNode = list->head;

    while (curNode != NULL) {
        Node *nextNode = curNode->next;
        curNode->next = prevNode;
        prevNode = curNode;
        curNode = nextNode;
    }

    list->head = prevNode;
}

///TESTED\n
/// Remove from the list at the pointer to the node remove
/// \param list
/// \param remove
void List_RemoveAtNode(List *list, Node *remove) {

    if (remove == NULL) {
        return;
    }

    //Handles list head removal
    if (remove == list->head) {
        if (list->length > 1) {
            var oldHead = list->head;

            list->head = oldHead->next;

            free(oldHead->data);
            free(oldHead);
        }

        list->length--;
        return;
    }

    //Get the 'parent' node
    var parent = list->head;

    int indexToRemoveAt = 1;

    //Get the index at which the node to be removed is at
    while (parent->next != remove) {
        parent = parent->next;
        indexToRemoveAt++;
    }

    // If the index to remove at is within bounds, get the particular node
    if (list->length > indexToRemoveAt) {
        parent->next = List_NodeAt(list, indexToRemoveAt + 1);
    } else {
        parent->next = NULL;
    }

    //Free the data, it wants to be free
    free(remove->data);
    free(remove);

    list->length--;
}

/// TESTED\n
/// Remove from the list at the index index
/// \param list
/// \param index
void List_RemoveAtIndex(List *list, const unsigned int index) {
    var removeNode = List_NodeAt(list, index);
    List_RemoveAtNode(list, removeNode);
}
