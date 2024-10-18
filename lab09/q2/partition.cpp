#include <vector>

// implement the partition function. The argument pivot is initially the index of the pivot element, it must be updated to the index of the pivot element after partitioning.
void partition(std::vector<int> &v, int left, int right, int &pivot) {
    pivot = v[left];
    int i = left -1;
    int j = right + 1;
    while (true) {
        do {i++;} while(pivot > v[i]);
        do {j--;} while (pivot < v[j]);
        if (i >= j) {pivot = j; return;}
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
    }
}


// void swap(vector<int>& len, int i, int j) {
// 	int temp = len[i];
// 	len[i] = len[j];
// 	len[j] = temp;
// }
