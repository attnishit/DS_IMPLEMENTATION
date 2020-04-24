#include <bits/stdc++.h>
using namespace std;
#define int long long
using ldb = long double;
using pa = pair < int, int >;
#define F  first
#define S  second
#define f(i,x,n) for(int i=x;i<n;i++) 
#define all(c) c.begin(),c.end()

struct Node { 
    string data; 
    Node* left, * right; 
    Node(string data1){
        left = NULL;
        right = NULL;
        data = data1;
    }
}; 
int to_int(string s){
    int ans = 0;
    if(s[0] != '-'){
        for(int i= 0;i < s.size();i++){
            ans = ans*10 + (s[i]- '0');
        }
    }
    else{
        for(int i= 1;i < s.size();i++){
            ans = ans*10 + (s[i]- '0');
        } 
        ans = ans*-1;    
    }
    return ans;
}
void inorder(Node* root){
    if(root == NULL){
        return ;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int solve(Node* root){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL and root->right == NULL){
        return to_int(root->data);
    }
    int left_sub = solve(root->left);
    int right_sub = solve(root->right);
    if(root->data == "+"){
        return left_sub + right_sub;
    }
    if(root->data == "-"){
        return left_sub - right_sub;
    }
    if(root->data == "*"){
        return left_sub * right_sub;
    }
    return left_sub/right_sub;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node* root = new Node("+");  
    root->left = new Node("*");  
    root->left->left = new Node("5");  
    root->left->right = new Node("4");  
    root->right = new Node("-");  
    root->right->left = new Node("100");  
    root->right->right = new Node("/");  
    root->right->right->left = new Node("20");  
    root->right->right->right = new Node("2");  
    inorder(root);
    cout << "\n" <<  solve(root);
    return 0;
}