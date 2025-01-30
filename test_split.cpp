/*
 *
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/
#include <cstddef>
#include <iostream>
#include "split.h"

using namespace std;

void print_linkedlist(Node* head);
void delete_linkedlist(Node* head);

int main(int argc, char* argv[])
{

  Node* NodeOne = new Node(10, nullptr);
  Node* NodeTwo = new Node(8, NodeOne);
  Node* NodeThree = new Node(5, NodeTwo);
  Node* NodeFour = new Node(2, NodeThree);

  print_linkedlist(NodeFour);

  Node* evens = nullptr;
  Node* odds = nullptr;
  split(NodeFour, odds, evens);
  cout << "after split" << endl;
  
  cout << "evens" << endl;
  print_linkedlist(evens);
  cout << endl;
  cout << "odds" << endl;
  print_linkedlist(odds);
  cout << endl;

  delete_linkedlist(evens);
  delete_linkedlist(odds);
}

void print_linkedlist(Node* head) {

  if (head == nullptr) {
    return;
  }

  cout << head->value << " "; 
  print_linkedlist(head->next);
  
}

void delete_linkedlist(Node* head) {

  while (head != nullptr) {
    Node* temp = head;
    head = head->next;
    delete temp;
  }

}

