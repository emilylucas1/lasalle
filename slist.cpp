#include "slist.h"
/*
Class Library File
*/

// Constructor

slist::slist() {
  head = nullptr;
  tail = nullptr;
  length = 0;
}
slist::slist(int length1, Node *head1, Node *tail1) {
  length = length1;
  head = head1;
  tail = tail1;
}
// Destructor
slist::~slist() {
  Node *cur;
  Node *next;
  while (cur != nullptr) {
    next = cur->next;
    delete (cur);
    cur = next;
  }
}
// add(value)				//Adds a new value to the end of this
// list.
void slist::add(Airport *a) {
  Node *newAirport = new Node();
  newAirport->data = a;
  newAirport->next = nullptr;
  if (head == nullptr) {
    head = newAirport;
    tail = newAirport;
  } else {
    tail->next = newAirport;
    tail = newAirport;
  }
  length++;
}
// clear()					//Removes all elements from this
// slist.
void slist::clear() {
  if (this->head == nullptr) {
    this->head = nullptr;
    this->tail = nullptr;
    this->length = 0;
  } else {
    Node *cur = this->head;
    while (cur->next != nullptr) {
      Node *temp = cur;
      delete temp;
      cur = cur->next;
    }
    this->head = nullptr;
    this->tail = nullptr;
    this->length = 0;
  }
}
// equals(slist)				//Returns true if the two slists
// contain the same elements in the same order
bool slist::equals(slist *list1) {
  Node *cur = this->head;
  Node *cur2 = list1->head;
  while (cur != nullptr) {
    if (cur->data->code != cur2->data->code &&
        cur->data->longitude != cur2->data->longitude &&
        cur->data->latitude != cur2->data->latitude) {
      return false;
    }
    cur = cur->next;
    cur2 = cur2->next;
  }
  if (cur->next != cur2->next) {
    return false;
  } else {
    return true;
  }
}
// get(index)				//Returns the element at the specified
// index in this slist.
Node* slist::get(int index) {
  Node *cur = this->head;
  int count = 0;
  while (cur != nullptr) {
    if (count == index) {
      break;
    } else {
      cur = cur->next;
      count++;
    }
  }
  return cur;
}
// insert(index, value)		//Inserts the element into this list before
// the specified index.
void slist::insert(int index, Airport *a) {
  Node *newAirport = new Node;
  newAirport->data = a;
  if (index == 0) {
    newAirport->next = this->head;
    head = newAirport;
  } else {
    newAirport->next = get(index);
    get(index - 1)->next = newAirport;
  }
  length++;
}
// exchg(index1, index2)		//Switches the payload data of specified
// indexex.
void slist::exchange(int index1, int index2) {
  Airport *air = get(index1)->data;
  get(index1)->data = get(index2)->data;
  get(index2)->data = air;
}

void slist::exchange(Node* index1, Node* index2) {
  Airport *air = index1->data;
  index1->data = index2->data;
  index2->data = air;
}
// swap(index1,index2)		//Swaps node located at index1 with node
// at index2
void slist::swap(int index1, int index2) {

  // if(!())
  if(index1 == index2){
    return;
  }
  Node *n1 = get(index1);
  Node *n2 = get(index2);
  Node *prev1 = get(index1 - 1);
  Node *prev2 = get(index2 - 1);
  if(!(n1 == nullptr || n2 == nullptr)){
    if(prev1 != nullptr){
      prev1->next = n2;
    }
    if(prev2 != nullptr){
    prev2->next = n1;
    }
    Node *temp;
    temp = n1->next;
    n1->next = n2->next;
    n2->next =temp;

    if(prev1 == nullptr){
      head = n2;
    }
    else if(prev2 == nullptr){
      head = n1;
    }
  }
  //cout << "swapped :D";
}
// isEmpty()				//Returns true if this list contains no
// elements.
bool slist::isEmpty() {
  if (head == nullptr && length == 0 && tail == nullptr) {
    return true;
  } else {
    return false;
  }
}
// remove(index)			//Removes the element at the specified
// index from this list.
void slist::remove(int index) {
  if (index < 0 || index >= length) {
    return;
  }
  Node *cur = this->head;
  Node *prev = nullptr;
  int count = 0;
  while (cur != nullptr) {
    if (count == index) {
      if(prev != nullptr){
        prev->next = cur->next;
      }
      else{
        this->head = cur->next;
      }
      delete cur;
      length--;
    }
    prev = cur; 
    cur = cur->next;
    count++;
  }
}
// set(index, value)		//Replaces the element at the specified index in
// this list with a new value.
void slist::set(int index, Airport *a) {
  Node *cur = this->head;
  int count = 0;
  while (cur != nullptr) {
    if (count == index) {
      cur->data = a;
      break;
    }
    cur = cur->next;
    count++;
  }
}
// size()					//Returns the number of elements
// in this list.
int slist::size() { return length; }

// clear()					//Removes all elements from this
// list.

// equals(list)				//Returns true if the two lists contain
// the same elements in the same order.

// get(index)				//Returns the element at the specified
// index in this list.

// insert(index, value)		//Inserts the element into this list before the
// specified index.

// exchg(index1, index2)		//Switches the payload data of specified
// indexex.

// swap(index1,index2)		//Swaps node located at index1 with node at
// index2

// isEmpty()				//Returns true if this list contains no
// elements.

// remove(index)			//Removes the element at the specified
// index from this list.

// set(index, value)		//Replaces the element at the specified index in
// this list with a new value.

// size()					//Returns the number of elements
// in this list.

// DO NOT IMPLEMENT >>> subList(start, length)	//Returns a new list containing
// elements from a sub-range of this list.

// DO NOT IMPLEMENT >>> toString()				//Converts the
// list to a printable string representation.