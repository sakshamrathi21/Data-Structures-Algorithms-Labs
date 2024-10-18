#include <stdlib.h>
#include "queue.h"

using namespace std;

template <typename T> bool DynamicQueue<T> :: isEmpty() {
  return head==tail; // dummy return
}

template <typename T> bool DynamicQueue<T> :: isFull() {
  return head-tail == 1; // dummy return
}

template <typename T> void DynamicQueue<T> :: grow() {
  T* B = new T[nextSize()];
  if(head<=tail) {
    for (int i = head; i<tail; i++) {
      B[i] = A[i];
    }
  }
  else {
    for(int i = head; i<N; i++) {
      B[i] = A[i];
    }
    for(int j = 0; j<tail; j++) {
      B[j] = A[j];
    }
  }
  delete [] A;
  A = B;
  N = nextSize();
}

template <typename T> unsigned int DynamicQueue<T> :: size() {
  return (N+tail-head)%N; // dummy return
}

template <typename T> void DynamicQueue<T> :: QInsert(T x) {
  if(isFull()) grow();
  if(tail==N) tail = 0;
  A[tail] = x;
  tail = tail+1;
}

template <typename T> bool DynamicQueue<T> :: QDelete(T* x) {
  if (isEmpty()) return false;
  *x = A[head];
  //delete A[head];
  //A[head] = NULL;
  head = head+1;
  return true; // dummy return
}
