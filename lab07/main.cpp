#include <iostream>
#include "heap.h"

#ifndef RANDOM
#define RANDOM false
#else
#undef RANDOM
#define RANDOM true
#endif

void load_input( Heap& h, string path) {
  std::fstream myfile( path , std::ios_base::in);
  int a;
  while (myfile >> a) {
    h.append(a);
    //h.printStore(h.size());
  }
  // h.printStore(h.size());
}

void random_gen( Heap& h, unsigned size) {
  for( unsigned i = 0; i < size; i++ ) {
    int v = rand() % 10000;
    h.append( v );
  }
}

void drive_heap( Heap& heap ) {
  unsigned size = heap.size();
  cout << "Input container:";
  heap.printStore(size);
  cout << "Input as a tree:\n";
  heap.print();
  heap.buildHeap();
  //heap.printStore(size);
  cout << "After transcformation to heap:\n";
  heap.print();
  cout << "Swaps for build heap: " << heap.swap_count << "\n";
  heap.swap_count = 0;
  heap.heapSort();
  cout << "Swaps for deleteMax: " << heap.swap_count << "\n";
  cout << "Sorted container:";
  heap.printStore(size);
}

int main() {
  unsigned test_count = 1;
  // make it true to enable random
  if( RANDOM ) {
    int sz = 5;
    Heap heap;
    random_gen(heap, (1<<sz)-1 );
    drive_heap(heap);
  }else{
    for( unsigned n=0; n < test_count; n++ ) {
      Heap heap;
      load_input( heap, "./tests/input"+ to_string(n) +".txt"  );
      //heap.printStore(heap.size());
      drive_heap(heap);
    }
  }

  return 0;
}
