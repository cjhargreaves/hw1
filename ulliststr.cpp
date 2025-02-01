#include <cstddef>
#include <stdexcept>
#include <string>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

// add new string to node, if node is full or nullptr, need to create a new node
void ULListStr::push_back(const std::string& val) {
  // if no elements in list, or array in last node is full we cannot add more elements to it
  // then we create a node 
  if (tail_ == nullptr || tail_->last == ARRSIZE) {
    Item* newNode = new Item;

    // if the list is not empty
    // we need to set the tail's next pointer to our new item
    // and new item previous pointer to tail
    if (tail_ != nullptr) {
      tail_->next = newNode;
      newNode->prev = tail_;
    }

    tail_ = newNode;
    
    // if the head is null, then this new node is the only one in the list
    if (head_ == nullptr) {
      head_ = tail_;
    }
  }
  
  // logic to add new string
  std::string *arr = tail_->val;
  int currentIdx = tail_->last;
  arr[currentIdx] = val;
  tail_->last = currentIdx + 1;
  
  // increment size
  size_++;
}

// similar to push_back
void ULListStr::push_front(const std::string& val) {
  // check for elements in list
  if (head_ == nullptr || head_->first == 0) {
    Item* newNode = new Item;
    newNode->last = ARRSIZE; 
    newNode->first = ARRSIZE;
    
    // if the list is not empty
    // need to set the new node's next pointer to the head
    // and head prev to the new node
    if (head_ != nullptr) {
      newNode->next =head_;
      head_->prev = newNode;

    } else {
      // list was empty? this new node is also tail
      tail_ = newNode;

    }
    head_ = newNode;

  }

  // logic to add new string
  std::string *arr = head_->val;
  int currentIdx = head_->first - 1;
  arr[currentIdx] = val;
  head_->first = currentIdx;

  size_++;
}

// general idea for pop and push
// check if empty
// pop_back - decrease the last index by 1 (moves the pointer)
// pop_front - increase the index by 1 
// check now if the array is empty
// remove node if empty
// adjust size

void ULListStr::pop_back() {
  // check if llist is empty
  if (empty()) {
    return;
  }

  // check the decrement of last with first
  // if its the same, then its empty
  if (--tail_->last == tail_->first) {

    Item* temp = tail_;
    tail_ = tail_->prev;

    if (tail_) {
      tail_->next = nullptr;
    } else  {
      head_ = nullptr;
    }
    delete temp;
  }


  size_--;
}

void ULListStr::pop_front() {
  // check empty
  if (empty()) {
    return;
  }

  // check if array is empty
  if (++head_->first == head_->last) {
    Item* temp = head_;
    head_ = head_->next;

    if (head_) {
      head_->prev = nullptr;
    } else {
      tail_ = nullptr;
    }


    delete temp;
  }

  size_--;
}

std::string const & ULListStr::back() const {

  return tail_->val[tail_->last - 1];

}

std::string const & ULListStr::front() const {

  return head_->val[head_->first];

}

std::string* ULListStr::getValAtLoc(size_t loc) const {
  // if loc >= size then this loc does not exist
  if (loc >= size_) {
    return nullptr;
  } 
  
  // traverse list
  Item* current = head_;
  while (current != nullptr) {

    int index = current->first + loc;
    
    if (index >= current->first && index < current->last) {
      return &current->val[index];
    }

    int elements = current->last - current->first;
    loc = loc - elements;
    current = current->next;

  }
  return nullptr;
}



void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
