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
bool check(Node* root1,Node* root2){
    if(root1 == NULL and root2 == NULL){
        return true;
    }
    if((root1 == NULL and root2 != NULL) or (root1 != NULL and root2 == NULL)){
        return false;
    }
    if(root1->data != root2->data){
        return false;
    }
    return (check(root1->left,root2->right)==true && check(root1->right,root2->left) == true);

}
int32_t main(){
    Node *root = new Node(1); 
    root->left =  new Node(2); 
    root->right = new Node(2); 
    root->left->left = new Node(3); 
    root->left->right = new Node(4); 
    root->right->left = new Node(4); 
    root->right->right = new Node(3); 
    if(check(root,root)){
        cout << "Symmetric or Mirror Tree\n";
        return 0;
    }
    else
        cout << "Not mirror\n";

    return 0;
}