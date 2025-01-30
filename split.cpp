/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/
#include <cstddef>
#include "split.h"

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{

  // Node*& is a reference to a pointer
  // allows the function to modify the address the pointer is holding
  // this allows us to point the pointer to a different node
  
  // base case
  // if in is nullptr we have reached the end
  // set odds and evens to null and return
  if (in == nullptr) {
    evens = nullptr;
    odds = nullptr;
    return;
  }

  // saving next node to call recursively
  Node* saved_node = in->next;

  // disconnect in node from list
  in->next = nullptr;
  
  // check if even or odd
  if (in->value % 2 == 0) {
    // make evens point to the same pointer as in
    evens = in;
    in = nullptr;
    split(saved_node, odds, evens->next);
  } else {
    odds = in;
    in = nullptr;
    split(saved_node, odds->next, evens);
  }
  
}

/* If you needed a helper function, write it here */
