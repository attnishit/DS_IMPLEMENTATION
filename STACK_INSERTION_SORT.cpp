#include <bits/stdc++.h>
using namespace std;

stack<int> inserion_sort(stack<int> current){
	stack<int> ans,aux;
	while(!current.empty()){
		int element = current.top(); current.pop();

		while(!ans.empty() && element > ans.top()){
			int greater = ans.top(); ans.pop();
			aux.push(greater);
		}

		ans.push(element);

		while(!aux.empty()){
			int aux_element = aux.top(); aux.pop();
			ans.push(aux_element);
		}
	}

	return ans;
}
int main(){
	stack <int> s;
	int n;
	n = 10;

	for (int i = 0; i < n; ++i){
		int x;
		cin >> x;
		s.push(x);
	}
	s = inserion_sort(s);
	for (int i = 0; i < n; ++i){
		cout << s.top() << " ";
		s.pop();
	}
}