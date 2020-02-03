#include<bits/stdc++.h>
using namespace std;
template<class T>
class Node{
public:
        T data;
        Node* link;
};

template<class T>
class Stack{
    Node<T>* top;
    public:
        Stack(){
            top=NULL;
        }
        void push(T val){
            Node<T>* new_node=new Node<T>;
            new_node->data=val;
            new_node->link=top;
            top=new_node;
        }
        T pop(){
            Node<T>* tmp;
            if(top==NULL){
                cout<<"OVERFLOW\n";
                return 0;
            }
            tmp=top;
            top=top->link;
            tmp->link=NULL;
            T values=tmp->data;
            delete(tmp);
            return values;
        }
        void display(){
            Node<T>* tmp=top;
            cout<<"start ->";
            while(tmp!=NULL){
                cout<<tmp->data<<"->";
                tmp=tmp->link;
            }
            cout<<"end\n";
        }

};
int main(){
    Stack<int>obj;
    int n,x;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x;
        obj.push(x);
        obj.display();
    }
    cout<<obj.pop()<<endl;
    obj.display();
    obj.pop();
    obj.pop();
    obj.pop();
    obj.pop();
    obj.display();
    obj.pop();
    obj.display();
    return 0;
}
