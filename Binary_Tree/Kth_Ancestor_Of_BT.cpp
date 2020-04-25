#include <iostream> 
#include <queue> 
using namespace std; 
int anc[1000];
int k = 2; 
int node = 4; 
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
int solve(Node* root){
	anc[root->data] = -1;
	queue<Node*>q;
	q.push(root);
	while(!q.empty()){
		Node* tmp = q.front();
		q.pop();
		if(tmp->left){
			anc[tmp->left->data] = tmp->data;
			q.push(tmp->left);
		}
		if(tmp->right){
			anc[tmp->right->data] = tmp->data;
			q.push(tmp->right);
		}
	}
	while(node != -1){
		node = anc[node];
		k--;
		if(k == 0){
			return node;
		}
	}
	return -1;

}
int main() 
{ 
    Node *root = new Node(1); 
    root->left =  new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
  	 cout <<  solve(root);
    return 0; 
} 
  \