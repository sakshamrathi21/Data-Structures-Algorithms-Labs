#include <cmath>
#include "partition.cpp"
#include "hsort.cpp"
#include "isort.cpp"
#include <vector>
using std::vector;

int depth = 0;

// Implement introsort. It is like quicksort but clever enough to avoid worst case.
void introsort(vector<int>& v, int l, int r, int thresold) {
  if ( r <= l) return;
  if (r-l < 15) return isort(v, l, r);
  int p = 0;
  partition(v, l, r, p);
  introsort(v, l, p, thresold-1);
  depth ++;
  introsort(v, p + 1, r, thresold-1);
  depth ++;
  if (thresold < 0) {
    return hsort(v, l, r);
  }
}

void introsort(vector<int>& v) {
  int thresold = 3; // Choose a thresold such the performance is best
  introsort(v, 0, v.size() - 1, thresold*std::log2(v.size())); // depth is logarithmic meaning worst case is nlogn
}
