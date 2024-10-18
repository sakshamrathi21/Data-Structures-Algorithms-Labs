#include <vector>
using std::vector;

int lefti(int i) {
	return (2*i+1);
}

int righti(int i) {
	return (2*i+2);
}

int parenti(int i) {
	return ((i-1)/2);
}

int index_with_largest_key(vector<int> len, int i, int j, int k) {
	if (len[i] > len[j]) {
		if (len[k] > len[i]) return k;
		else return i;
	}
	else {
		if (len[j] < len[k]) return k;
		else return j;
	}
}

void swap(vector<int>& len, int i, int j) {
	int temp = len[i];
	len[i] = len[j];
	len[j] = temp;
}

void heapify(vector<int>& len, int left, int i, int right) {
    if (i < left || i > right) return;
    int c;
    if (lefti(i) > right) {
        return;
    }
    else if (lefti(i) == right) {
        if (len[lefti(i)] > len[i]) c = lefti(i);
		else {
			c = i;
		}
    }
    else {
        c = index_with_largest_key(len, i, lefti(i), righti(i));
    }
    if (c == i) return;
    swap(len, c, i);
    heapify(len, left, c, right);
}

void deletemax(vector<int>& len, int left, int right) {
	swap(len, left, right);
	heapify(len, left, left, right-1);
}

void buildHeap(vector<int>& len, int left, int right) {
	for (int i = right; i >= left; i--) {
		heapify(len, left, i, right);
    //     for ( int i = left; i <= right; i ++) {
    //     cout<<"CH "<<len[i]<<endl;
    // }
	}
}

// implement heapsort - perhaps using a heap class
void hsort(vector<int>& v, int left, int right) {
    buildHeap(v, left, right);
    // for ( int i = left; i <= right; i ++) {
    //     cout<<"CH "<<v[i]<<endl;
    // }
    for (int i = left; i <= right; i++) {
        deletemax(v, left, right-i+left);
        //cout<<v[right]<<"HELLO"<<endl;
    }
}