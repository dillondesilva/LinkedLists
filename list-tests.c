#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "list.h"
 
 
// Unit Testing on the List type
static void testList (void);
 
int main (int argc, char *argv[])  {
    printf ("Beginning Linked List Tests...\n");
    testList();
    printf ("All tests passed!\n");
 
    return EXIT_SUCCESS;
}
 
 
static void testList (void) {
    // create empty list
    list myList = malloc (sizeof (*myList));
    myList->head = NULL;
    // myList is a struct which has an element head which
    // points to the first node of the list aka the head
 
 
    // simple test on numItems
    assert (numItems (myList) == 0);
 
    // attach one node to the list
    link ptrToNewNode = malloc (sizeof (node));
    assert (ptrToNewNode != NULL); 
    ptrToNewNode->value = 1;
    ptrToNewNode->next = NULL;
 
    myList->head = ptrToNewNode;  
 
    // simple test on numItems
    printf ("testing numItems()\n");  
    assert (numItems (myList) == 1);
    
    // attach a second node to the list
    ptrToNewNode = malloc (sizeof (node));
    assert (ptrToNewNode != NULL);  
 
    ptrToNewNode->value = 2;
    ptrToNewNode->next = NULL;
 
    myList->head->next = ptrToNewNode;
 
    assert (numItems (myList) == 2);
    
    printf ("testing prepend which is known as frontInsert()\n");   
    // insert a node containing 0 at te head, ie before 
    // the 1->2->X list, to produce 0->1->2->X
 
    frontInsert (myList, 0); 
    assert (myList != NULL);
    assert (myList->head != NULL);
    assert (myList->head->value == 0);
    assert (myList->head->next  != NULL);
    assert (myList->head->next->value == 1);
 
    assert (numItems (myList) == 3);

    printf ("testing append()\n");  
    // insert at end 
    append (myList, 4);
 
    assert (myList != NULL);
    assert (myList->head != NULL);
    assert (myList->head->next != NULL);
    assert (myList->head->next->next != NULL);
    assert (myList->head->next->next->next != NULL);
    assert (myList->head->next->next->next->value == 4);
    assert (myList->head->next->next->next->next  == NULL);
    
    printf ("testing showList()\n");  
    showList (myList);
    assert (numItems (myList) == 4);
    
    printf ("testing lookup()\n"); 
    // test lookup
    assert (lookup (myList,0)==0);
    assert (lookup (myList,1)==1);
    assert (lookup (myList,2)==2);
    assert (lookup (myList,3)==4);

    printf ("testing newList()\n");
    list testList = newList();
    assert (testList->head == NULL);
 
 
    printf ("testing deleteHead()\n");
    // create a 3 element list
    testList->head = malloc (sizeof (node));
    testList->head->value = 3;
    testList->head->next  = malloc (sizeof (node));
    testList->head->next->value = 1;
    testList->head->next->next  = malloc (sizeof (node));
    testList->head->next->next->value = 4;
    testList->head->next->next->next  = NULL;
 
    deleteHead (testList);
 
    assert (testList != NULL);
    assert (testList->head != NULL);
    assert (testList->head->value == 1);
    assert (testList->head->next != NULL);
    assert (testList->head->next->value == 4);
    assert (testList->head->next->next == NULL);
 
    deleteHead (testList);
 
    assert (testList != NULL);
    assert (testList->head != NULL);
    assert (testList->head->value == 4);
    assert (testList->head->next == NULL);
 
    deleteHead (testList);
 
    assert (testList != NULL);
    assert (testList->head == NULL);
 
 
    printf ("testing deleteLast()\n");
    // create a 3 element list
    testList->head = malloc (sizeof (node));
    testList->head->value = 3;
    testList->head->next  = malloc (sizeof (node));
    testList->head->next->value = 1;
    testList->head->next->next  = malloc (sizeof (node));
    testList->head->next->next->value = 4;
    testList->head->next->next->next  = NULL;
 
    deleteLast (testList);
 
    assert (testList != NULL);
    assert (testList->head != NULL);
    assert (testList->head->value == 3);
    assert (testList->head->next != NULL);
    assert (testList->head->next->value == 1);
    assert (testList->head->next->next == NULL);
 
    deleteLast (testList);
 
    assert (testList != NULL);
    assert (testList->head != NULL);
    assert (testList->head->value == 3);
    assert (testList->head->next == NULL);
 
    deleteLast (testList);
 
    assert (testList != NULL);
    assert (testList->head == NULL);
 
 
    printf ("testing concatenate()\n");
 
    // (3,2) -> (5,0)
    // create a 3 element list
    testList->head = malloc (sizeof (node));
    testList->head->value = 3;
    testList->head->next  = malloc (sizeof (node));
    testList->head->next->value = 1;
    testList->head->next->next  = malloc (sizeof (node));
    testList->head->next->next->value = 4;
    testList->head->next->next->next  = NULL;
 
    // create a two element list
    list testListB = newList();
 
    testListB->head = malloc (sizeof (node));
    testListB->head->value = 1;
    testListB->head->next  = malloc (sizeof (node));
    testListB->head->next->value = 5;
    testListB->head->next->next  = NULL;
 
    concatenate (testList, testListB);
    assert (testListB != NULL);
    assert (testListB->head == NULL);
 
    assert (testList != NULL);
    assert (testList->head != NULL);
    assert (testList->head->value == 3);
    assert (testList->head->next != NULL);
    assert (testList->head->next->value == 1);
    assert (testList->head->next->next != NULL);
    assert (testList->head->next->next->value == 4);
    assert (testList->head->next->next->next != NULL);
    assert (testList->head->next->next->next->value == 1);
    assert (testList->head->next->next->next->next != NULL);
    assert (testList->head->next->next->next->next->value == 5);
    assert (testList->head->next->next->next->next->next == NULL);
 
 
    // (5,0) -> (5,0)
    concatenate (testList, testListB);
    assert (testListB != NULL);
    assert (testListB->head == NULL);
 
    assert (testList != NULL);
    assert (testList->head != NULL);
    assert (testList->head->value == 3);
    assert (testList->head->next != NULL);
    assert (testList->head->next->value == 1);
    assert (testList->head->next->next != NULL);
    assert (testList->head->next->next->value == 4);
    assert (testList->head->next->next->next != NULL);
    assert (testList->head->next->next->next->value == 1);
    assert (testList->head->next->next->next->next != NULL);
    assert (testList->head->next->next->next->next->value == 5);
    assert (testList->head->next->next->next->next->next == NULL);
 
    // (0,5) -> (5,0)
    concatenate (testListB, testList);
    assert (testList != NULL);
    assert (testList->head == NULL);
 
    assert (testListB != NULL);
    assert (testListB->head != NULL);
    assert (testListB->head->value == 3);
    assert (testListB->head->next != NULL);
    assert (testListB->head->next->value == 1);
    assert (testListB->head->next->next != NULL);
    assert (testListB->head->next->next->value == 4);
    assert (testListB->head->next->next->next != NULL);
    assert (testListB->head->next->next->next->value == 1);
    assert (testListB->head->next->next->next->next != NULL);
    assert (testListB->head->next->next->next->next->value == 5);
    assert (testListB->head->next->next->next->next->next == NULL);
}