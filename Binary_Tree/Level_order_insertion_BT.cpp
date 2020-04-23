#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define f(i,x,n) for(int i=x;i<n;i++) 
#define all(c) c.begin(),c.end()
const int MOD = 1e9 + 7, N = 5e5 + 10;
const int LINF = LLONG_MAX;

struct Node{
	int data;
	Node* left;
	Node* right;
	Node(int val){
		left = NULL;
		right = NULL;
		data = val;
	}
};
void inorder(Node* root){
	if(root == NULL){
		return;
	}
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}
void insert(Node* root,int val){
	queue<Node*>q;
	q.push(root);
	while(!q.empty()){
		Node* tmp = q.front();
		q.pop();
		if(tmp->left == NULL){
			tmp->left = new Node(val);
			break;
		}
		else{
			q.push(tmp->left);
		}
		if(tmp->right == NULL){
			tmp->right = new Node(val);
			break;
		}
		else{
			q.push(tmp->right);
		}
	}
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node* node = new Node(5);
    node->left = new Node(7);
    node->right = new Node(6);
    node->right->left = new Node(15); 
    node->right->right = new Node(8); 
    int val = 13;
    insert(node,val);
    inorder(node);
    return 0;
}
 