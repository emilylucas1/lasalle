#include <cstring>
#include <iostream>
#include <string>
using namespace std;

class Airport {
public:
  char code[5];
  double longitude;
  double latitude;
};
struct Node {
  Airport *data;
  Node *next;
  Node() {
    data = nullptr;
    next = nullptr;
  };
};
class slist {



public:
  int length;
  Node *head;
  Node *tail;
  slist();
  slist(int length1, Node *head1, Node *tail1);
  // Destructor
  ~slist();
  // add(value)				//Adds a new value to the end of this
  // slist.
  void add(Airport *a);
  // clear()					//Removes all elements from this
  // list.
  void clear();
  // equals(list)				//Returns true if the two lists
  // contain the same elements in the same order
  bool equals(slist *list1);
  // get(index)				//Returns the element at the specified
  // index in this list.
  Node *get(int index);
  // insert(index, value)		//Inserts the element into this list
  // before the specified index.
  void insert(int index, Airport *a);
  // exchg(index1, index2)		//Switches the payload data of specified
  // indexex.
  void exchange(int index1, int index2);
  // swap(index1,index2)		//Swaps node located at index1 with node
  // at index2
  void exchange(Node *index1, Node* index2);
  //swap the values of nodes but using the nodes
  void swap(int index1, int index2);
  // isEmpty()				//Returns true if this list contains no
  // elements.
  bool isEmpty();
  // remove(index)			//Removes the element at the specified
  // index from this list.
  void remove(int index);
  // set(index, value)		//Replaces the element at the specified index in
  // this list with a new value.
  void set(int index, Airport *a);
  // size()					//Returns the number of elements
  // in this list.
  int size();
};