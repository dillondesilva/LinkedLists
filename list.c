#include "list.h"
#include <stdlib.h>
#include <stdio.h>

// print out a list
void showList (list listToPrint) {
  link nextNode = listToPrint->head;
  int itemCount = 0;
  if (nextNode != NULL) {
    while (nextNode != NULL) {
      int nodeValue = nextNode->value;
      printf("Node %d has a value of %d\n", itemCount, nodeValue);
      nextNode = nextNode->next;
      itemCount++;
    } 
  } 
}
 
// inset item at the front of the list
void frontInsert (list l, int item) {
  link ptrNodeToInsert = malloc(sizeof (node));
  ptrNodeToInsert->value = item;
  ptrNodeToInsert->next = NULL;

  link nextNode = l->head;

  if (nextNode == NULL) {
    l->head = ptrNodeToInsert;
  } else {
    link prevRootNode = l->head;
    ptrNodeToInsert->next = prevRootNode;
    l->head = ptrNodeToInsert;
  }
}
 
// count the number of items in the list
int numItems (list l) {
  link nextNode = l->head;
  int itemCount = 0;
  if (nextNode != NULL) {
    while (nextNode != NULL) {
      nextNode = nextNode->next;
      itemCount++;
    } 
  } 
  return itemCount;
}

// insert at end of list
void append (list l, int value) {
  link ptrNodeToInsert = malloc(sizeof (node));
  ptrNodeToInsert->value = value;
  ptrNodeToInsert->next = NULL;

  link nextNode = l->head;

  if (nextNode == NULL) {
    l->head = ptrNodeToInsert;
  } else {
    while (nextNode->next != NULL) {
      nextNode = nextNode->next;
    } 

    nextNode->next = ptrNodeToInsert;
  }
}

// find the value stored at position i
// i MUST be a valid position in the list
// dont call this on positions outside the list
int lookup (list l, int position) {
  link nextNode = l->head;
  int itemCount = 0;
  while (itemCount != position) {
    nextNode = nextNode->next;
    itemCount++;
  } 

  int value = nextNode->value;
  return value;
}

list newList (void) {
  list myList = malloc (sizeof (*myList));
  myList->head = NULL;
  return myList;
}

// delete the first node
void deleteHead (list l) {
  link nextNode = l->head;

  if (nextNode == NULL) {
    printf("There is no root node to delete\n");
  } else {
    link newRootNode = l->head->next;
    l->head = newRootNode;
  }
}

// delete the end node
void deleteLast (list l) {
  link nextNode = l->head;

  if (nextNode == NULL) {
    printf("No nodes to delete\n");
  } else {
    link prevNode = NULL;
    while (nextNode->next != NULL) {
      prevNode = nextNode;
      nextNode = nextNode->next;
    } 

    if (prevNode == NULL) {
      free (l->head);
      l->head = NULL;
    } else {
      free (prevNode->next);
      prevNode->next = NULL;
    }
  }
}

// join two lists

// move all the elements from the second list to the end of
// the first list (in order).  this leaves the second list
// empty and all the elements in the first list. 
void concatenate (list to, list from) {
  link toNode = to->head;
  link fromNode = from->head;
  
  if (toNode == NULL) {
    to->head = fromNode;
  } else {
    while (toNode->next != NULL) {
      toNode = toNode->next;
    }

    toNode->next = fromNode;
  }

  from->head = NULL;
}