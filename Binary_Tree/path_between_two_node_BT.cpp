#include <iostream> 
#include <queue> 
using namespace std; 
int anc[1000];
int k = 2; 
int node = 4; 
vector<int>v1,v2;
struct Node 
{ 
    int data; 
    struct Node *left, *right; 
    Node(int d){
    	data = d;
    	left= NULL;
    	right = NULL;
    }
}; 

bool path(vector<int>&v,Node* root,int val){
	if(root == NULL){
		return false;
	}
	v.push_back(root->data);
	if(root->data == val){
		return true;
	}
	if(path(v,root->left,val) or path(v,root->right,val)){
		return true;
	}
	v.pop_back();
	return false;
}
int main() 
{ 
    Node* root = new Node(0); 
    root->left = new Node(1); 
    root->left->left = new Node(3); 
    root->left->left->left = new Node(7); 
    root->left->right = new Node(4); 
    root->left->right->left = new Node(8); 
    root->left->right->right = new Node(9); 
    root->right = new Node(2); 
    root->right->left = new Node(5); 
    root->right->right = new Node(6); 
    int node1 = 7;
    int node2 = 4;
    path(v1,root,node1);
    path(v2,root,node2);
 	int i = 0,j = 0,intersection = -1;
  	while (i != v1.size() || j != v2.size()) { 
  
        if (i == j && v1[i] == v2[j]) { 
            i++; 
            j++; 
        } 
        else { 
            intersection = j - 1; 
            break; 
        } 
    } 
    for (int i = v1.size() - 1; i > intersection; i--) 
        cout << v1[i] << " "; 
  
    for (int i = intersection; i < v2.size(); i++) 
        cout << v2[i] << " "; 
    return 0; 
} 
  