
/*
2. Design an array based data structure for three stacks as done for two stacks in the tutorials.
The three stacks should share the same array in an efficient manner. If there are MaxSize
entries in the array then the IsFull/overflow function should only return true if all the
entries in the array are occupied.
*/


#include<bits/stdc++.h> 
using namespace std; 

class three_stacks { 
	int *arr; 
	int *top; 
	int *next; 
	int n, k; 
	int free; 
public: 
	three_stacks(int k1, int n1) { 
		k = k1, n = n1; 
		arr = new int[n]; 
		top = new int[k]; 
		next = new int[n]; 
		for (int i = 0; i < k; i++) 
			top[i] = -1; 
		free = 0; 
		for (int i=0; i<n-1; i++) 
			next[i] = i+1; 
		next[n-1] = -1; 
	} 
	bool isFull() { 
		return (free == -1); 
	} 
	void push(int item, int sn); 

	int pop(int sn); 
	bool isEmpty(int sn) { 
		return (top[sn] == -1); 
	} 
}; 
void three_stacks::push(int item, int sn) {  
	if (isFull()) { 
		cout << "\nStack Overflow\n"; 
		return; 
	} 

	int i = free;
	free = next[i]; 
	next[i] = top[sn]; 
	top[sn] = i; 
	arr[i] = item; 
} 
int three_stacks::pop(int sn) { 
	if (isEmpty(sn)) { 
		cout << "\nStack Underflow\n"; 
		return INT_MAX; 
	} 
	int i = top[sn]; 
	top[sn] = next[i]; 
	next[i] = free; 
	free = i; 
	return arr[i]; 
} 
int main() { 
	int n = 100; 
	three_stacks ks(3, n); 
	ks.push(100, 2); 
	ks.push(200, 2); 
	ks.push(50, 1); 
	ks.push(60, 1); 
	ks.push(60, 1); 
	ks.push(70, 0); 
	ks.push(80, 0); 
	ks.push(90, 0); 
	cout << "Popped element from stack 2 is " << ks.pop(2) << endl; 
	cout << "Popped element from stack 1 is " << ks.pop(1) << endl; 
	cout << "Popped element from stack 0 is " << ks.pop(0) << endl; 

	return 0; 
} 
