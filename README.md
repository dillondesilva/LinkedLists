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

#### int numItems (list l)

Shows the number of items which are in a list

```
list myList
