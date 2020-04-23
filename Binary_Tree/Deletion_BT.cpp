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
void replacedeepest(Node* root,Node* deep){
	queue<Node*>q;
	q.push(root);
	Node* tmp;
	while(!q.empty()){
		tmp = q.front();
		q.pop();
		if(tmp == deep){
			tmp = NULL;
			delete deep;
			return;
		}
		if(tmp->right){
			if(tmp->right == deep){
				tmp->right = NULL;
				delete deep;
				return;
			}
			else{
				q.push(tmp->right);
			}
		}
		if(tmp->left){
			if(tmp->left == deep){
				tmp->left = NULL;
				delete deep;
				return;
			}
			else{
				q.push(tmp->left);
			}
		}
	}
}

Node* deletion(Node* root,int val){
	if(root == NULL){
		return NULL;
	}
	if(root->left == NULL and root->right == NULL){
		if(root->data == val){
			return NULL;
		}
		else{
			return root;
		}
	}
	queue<Node*>q;
	q.push(root);
	Node* tmp;
	Node* key = NULL;  
	while(!q.empty()){
		tmp = q.front();
		q.pop();
		if(tmp->data == val){
			key = tmp;
		}
		if(tmp->left){
			q.push(tmp->left);
		}	
		if(tmp->right){
			q.push(tmp->right);
		}
	}
	if(key != NULL){
		int x = tmp->data;
		replacedeepest(root,tmp);
		key->data = x;
	}
	return root;

}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node* node = new Node(5);
    node->left = new Node(7);
    node->right = new Node(6);
    node->right->left = new Node(15); 
    node->right->right = new Node(8); 
    inorder(node);
	cout << "\n";
    int val = 6;
    Node* root = deletion(node,val); 
    inorder(root);
    return 0;
}
 
