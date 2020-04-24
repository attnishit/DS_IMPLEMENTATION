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
bool solve(Node* root1,Node* root2){
    if(root1 == NULL and root2 == NULL){
        return true;
    }
    if(root1 == NULL or root2 == NULL){
        return true;
    }
    return solve(root1->left,root2->right) and solve(root1->right,root2->left);
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->right->left = newNode(4); 
    root->left->right = newNode(5); 
	cout << (solve(root,root) ? "YES" : "NO");	     
    return 0;
}