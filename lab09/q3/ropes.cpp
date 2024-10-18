#include <bits/stdc++.h>

using namespace std;

int left(int i) {
	return (2*i+1);
}

int right(int i) {
	return (2*i+2);
}

int parent(int i) {
	return ((i-1)/2);
}

int index_with_smallest_key(int* len, int i, int j, int k) {
	if (len[i] < len[j]) {
		if (len[k] < len[i]) return k;
		else return i;
	}
	else {
		if (len[k] < len[j]) return k;
		else return j;
	}
}

void swap(int* len, int i, int j) {
	int temp = len[i];
	len[i] = len[j];
	len[j] = temp;
}

void heapify(int* len, int n, int i) {
	int c;
	//cout<<"HELLO"<<endl;
	// cout<<i<<endl;
	if (i > n-1) return;
	//cout<<i<<endl;
	if (left(i) > n-1) {
		return;
	}
	else if (left(i) == n-1) {
		//cout<<i<<endl;
		if (len[left(i)] < len[i]) c = left(i);
		else {
			c = i;
		}
	}
	else {
		c = index_with_smallest_key(len, i, left(i), right(i));
	}
	if (c == i) return;
	swap(len, c, i);
	heapify(len, n, c);
}

int deletemin(int* len, int &n) {
	swap(len, 0, n-1);
	n--;
	heapify(len, n, 0);
	return len[n];
}

void insertHeap(int* len, int &n, int k) {
	int i = n;
	len[n] = k;
	while (i > 0 && len[parent(i)] > len[i]) {
		swap(len, parent(i), i);
		i = parent(i);
	}
	n++;
	return;
}

void buildHeap(int* len, int n) {
	for (int i = n-1; i >= 0; i--) {
		heapify(len, n, i);
	}
}

// The main function that returns
// the minimum cost to connect n
// ropes of lengths stored in len[0..n-1]
int minCost(int len[], int n)
{	
	
	int cost = 0; // Initialize result
	buildHeap(len, n);
	//
	while(n>1) {
	int min1 = deletemin(len, n);

	int min2 = deletemin(len, n);
	//cout<<min1<<" "<<min2<<" "<<cost<<endl;
	cost = cost + min1 + min2;
	insertHeap(len, n, min1+min2);
	}
        // Write your code here
	return cost;
}


