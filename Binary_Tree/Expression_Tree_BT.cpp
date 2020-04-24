#include <bits/stdc++.h>
using namespace std;
#define int long long
using ldb = long double;
using pa = pair < int, int >;
#define F  first
#define S  second
#define f(i,x,n) for(int i=x;i<n;i++) 
#define all(c) c.begin(),c.end()

string s;
struct Node 
{ 
    char data; 
    struct Node* left, * right; 
}; 
struct Node* newNode(char data) { 
    struct Node* node = new Node; 
    node->data = data; 
    node->left = node->right = NULL; 
    return(node); 
} 
bool isOperator(char c) { 
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') 
        return true; 
    return false; 
}
void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
Node* solve(){
    stack<Node*>st;
    Node *l ,*r,*mid;
    for(int i = 0;i < s.size();i++){
        if(!isOperator(s[i])){
            mid = newNode(s[i]);
            st.push(mid);
        }
        else{
            mid = newNode(s[i]);
            r = st.top();
            st.pop();
            l = st.top();
            st.pop();
            mid->left = l;
            mid->right = r;
            st.push(mid);
        }
    }
    mid = st.top();
    st.pop();
    assert(st.empty());
    return mid;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    s= "ab+ef*g*-";
    Node* root = solve();
    inorder(root);
    return 0;
}