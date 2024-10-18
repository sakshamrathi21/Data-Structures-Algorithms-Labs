#include <iostream>

/*
In this exercise, we will implement heap as discussed in the class.
We need to implement the following functions.


ONLY THIS FILE MUST BE MODIFIED FOR SUBMISSION

You may edit main.cpp for writing more test cases.
But your code must continue to work with the original main.cpp


THERE IS ONLY ONE TEST CASE ONLY FOR YOUR UNDERSTANDING.

-- You may need to generate more random tests to get your tests right
-- Print will not work until you have a good printing function
*/


#include "heap.h"


int Heap::parent(int i) {
  if (i<0) return 0;
  return ((i-1)/2); // dummy return
}

int Heap::left(int i) {
  return (2*i+1); // dummy return
}

int Heap::right(int i) {
  return (2*i+2); //dummy
}

int Heap::max() {
  return store[0]; //dummy
}

void Heap::swap(int i, int j) {
  //cout<<i<<" "<<j<<endl;
  //printStore(sz);
  int temp = store[i];
  store[i] = store[j];
  store[j] = temp;
  swap_count++;
  //printStore(sz);
}

void Heap::insert(int v) {
  append(v);
  int i = size()-1;
  while (i > 0 && store[parent(i)] < store[i]) {
    swap(parent(i), i);
    i = parent(i);
  }
  //printStore(size());
}

void Heap::heapify(int i) {
  int l=i, r=i, c = i;
  if (left(i) < size()) {
    l = left(i);
  }
  if (right(i) < size()) {
    r = right(i);
  }
  if (store[l] > store[i]){
    if (store[r] > store[l]) {
      c = r;
    }
    else {
      c = l;
    }
  }
  else {
    if (store[r] > store[i]) {
      c = r;
    }
  }
  if (c==i) return;
  swap(c, i);
  heapify(c);
}


void Heap::deleteMax() {
  swap(0, size()-1);
  removeLast();
  heapify(0);
}

void Heap::buildHeap() {
  for (int i = size()-1; i>=0; i--) {
    //printStore(sz);
    heapify(i);
  }
  //printStore(sz);
}

void Heap::heapSort() {
  int sizeold = sz;
  buildHeap();
  //std::cout<<"Hello"; printStore(sz);
  int i = sz;
  while (i > 0) {
    deleteMax();
    //removeLast();
    i--;
  }
  sz = sizeold;
}