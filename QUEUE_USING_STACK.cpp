/*
3. Implement a queue using two stacks. We are given a stack data structure with push and
pop operations, the task is to implement a queue using instances of stack data structure
and operations on them.
*/
#include <bits/stdc++.h> 
using namespace std; 
class Queue { 
public:
	stack<int> s1, s2; 
	void insert(int x) { 
		s1.push(x); 
	} 
	int remove() 
	{ 
		if (s1.empty() && s2.empty()) { 
			cout << "Q is empty"; 
			exit(0); 
		} 
		if (s2.empty()) { 
			while (!s1.empty()) { 
				s2.push(s1.top()); 
				s1.pop(); 
			} 
		} 
		int x = s2.top(); 
		s2.pop(); 
		return x; 
	} 
}; 
int main() 
{ 
	Queue q; 
	q.insert(1); 
	q.insert(2); 
	q.insert(3); 
	q.insert(6);
	q.insert(10);

	cout << q.remove() << '\n'; 
	cout << q.remove() << '\n'; 
	cout << q.remove() << '\n'; 

	return 0; 
} 
