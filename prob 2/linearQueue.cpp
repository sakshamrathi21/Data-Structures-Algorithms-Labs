#include <stdlib.h>
#include "queue.h"

using namespace std;

template <typename T> bool DynamicQueue<T> :: isEmpty() {
  return head==tail; // dummy return
}

template <typename T> bool DynamicQueue<T> :: isFull() {
  return (tail-head) == N; // dummy return
}

template <typename T> void DynamicQueue<T> :: grow() {
  T* B = new T[nextSize()];
  for(int i = 0; i<N; i++){
    B[i] = A[i];
  }
  A = B;
  N = nextSize();
}

template <typename T> unsigned int DynamicQueue<T> :: size() {
  return N; // dummy return
}

template <typename T> void DynamicQueue<T> :: QInsert(T x) {
  if (isFull()) grow();
  A[tail] = x;
  tail = tail+1;
}

template <typename T> bool DynamicQueue<T> :: QDelete(T* x) {
  if (isEmpty()) return false;
  *x = A[head];
  //A[head] = NULL; 
  head = head+1;
  return true; // dummy return
}
