#include <bits/stdc++.h>
using namespace std;
#define int long long
using ldb = long double;
using pa = pair < int, int >;
#define F  first
#define S  second
#define f(i,x,n) for(int i=x;i<n;i++) 
#define all(c) c.begin(),c.end()

struct Node 
{ 
    int data; 
    struct Node* left, * right; 
}; 
struct Node* newNode(int data) { 
    struct Node* node = new Node; 
    node->data = data; 
    node->left = node->right = NULL; 
    return(node); 
} 
bool solve(Node* root){
	if(root == NULL){
		return true;
	}
	if(root->left == NULL and root->right == NULL){
		return true;
	}
	if(!root->left){
		return (abs(root->data - root->right->data) == 1 and solve(root->right));
	}
	if(!root->right){
		return (abs(root->data - root->left->data) == 1 and solve(root->left));
	}
	return (abs(root->data - root->left->data) == 1 and solve(root->left) and (abs(root->data - root->right->data) == 1 and solve(root->right)));
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    struct Node *root = newNode(3); 
    root->left        = newNode(2); 
    root->right       = newNode(4); 
    root->left->left  = newNode(1); 
    root->left->right = newNode(3); 
    root->right->right = newNode(5); 
	cout << (solve(root) ? "YES" : "NO");	     
    return 0;
}