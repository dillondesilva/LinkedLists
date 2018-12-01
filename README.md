# LinkedLists

This repository holds the required project files for a very basic and beginners Linked Lists module in C. It is based of the Linked List problems from UNSW's HS1511

## Installation

### Downloading as A Zip

To install these files as a Zip, click on the green "Clone or download" button at the top of the repository and then select "Download Zip" at the bottom right of the pop up box. 

### Cloning from CLI

To clone this repository and obtain all the files for this module, run the following command in your CLI

```
git clone git@github.com:codetilldrop/LinkedLists.git
```

## Usage
### Importing Module

To import this module into your projects, simply #include the following at the top of 
your code

```
#include "/LinkedList/list.h"
```

### API
#### Linked List Type
#### list newList (void)

Creates a new Linked List type

```
list myList = newList();
```

#### append (list, value)

Appends the value passed into the function into the specified list which is also passed into the functions.

```
list myList = newList();
append(myList, 42);
```

#### frontInsert (list, value)

Prepends the value passed into the function into the specified list which is also passed into the functions.

```
list myList = newList();
frontInsert(myList, 42);
```

#### showList (list)

Prints out the specified Linked List passed into the function

```
list myList = newList();
append(myList, 1);
append(myList, 2);
showList(myList);
// Expected output of above statement: 
// 1
// 2
```

#### int numItems (list l)

Shows the number of items which are in a list

```
list myList = newList();
append(myList, 10);
append(myList, 1);
append(myList, 11);
int numOfItems = numItems(myList);
printf("numOfItems is equivalent to %d\n", numOfItems);
```

#### int lookup (list l, int position)

Shows the value of a node at a given index of a linked list

```
list myList = newList();
append(myList, 10);
append(myList, 1);
append(myList, 11);
int secondElementVal = lookup(myList, 2)
printf("The 2nd element in the linked list is equivalent to %d\n",secondElementVal)
```

#### int deleteHead ()

Deletes the first node in a linked list

```
list myList = newList();
append(myList, 10);
append(myList, 1);
append(myList, 11);
showList(myList);
// Expected output of above statement:
// 10
// 1
// 11

deleteHead(myList);
showList(myList);
// Expected output of above statement:
// 1
// 11
```

#### int deleteLast (list l)

Deletes the last node in a linked list

```
list myList = newList();
append(myList, 10);
append(myList, 1);
append(myList, 11);
showList(myList);
// Expected output of above statement:
// 10
// 1
// 11

deleteLast(myList);
showList(myList);
// Expected output of above statement:
// 10
// 1
```

#### int concatenate (list to, list from);

Joins two linked lists together to form a new one

```
list firstList = newList();
append(firstList, 10);
append(firstList, 1);
append(firstList, 11);

list secondList = newList();
append(secondList, 100)
append(secondList, 101)
append(secondList, 110)

list finalList = concatenate(firstList, secondList);
showList(finalList);
// Expected output of above statement:
// 10
// 1
// 11
// 100
// 101
// 110
```