#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite
//
//
using namespace std;

int main(int argc, char* argv[])
{
  ULListStr *newList = new ULListStr();

  
  newList->push_front("hello");
  newList->push_front("another");
  newList->push_front("test");
  newList->push_front("meow");
  
  // front will be meow
  // back will be hello
  cout << "front: " << newList->front() << endl;
  cout << "back: " << newList->back() << endl;

  // changing elements
  newList->set(0, "first changed");
  newList->set(1, "second changed");

  cout << "index 1: " << newList->get(0) << endl;
  cout << "index 2: " << newList->get(1) << endl;

  newList->pop_front();
  newList->pop_back();

  // new front will be test
  // new back will be another
  cout << "new front: " << newList->front() << endl;
  cout << "new back: " << newList->back() << endl;



  newList->clear();

  delete newList;


}
