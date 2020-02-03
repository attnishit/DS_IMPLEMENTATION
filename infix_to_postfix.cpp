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
        T tops(){
            return top->data;
        }

};
int prec(char c) 
{ 
    if(c == '^') 
    return 3; 
    else if(c == '*' || c == '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else
    return -1; 
} 

int main(){
    Stack<char>stack;
    string s;
    cin >> s;
    string s1="";
    stack.push('X');
    for(int i=0;i<s.size();i++){
        if((s[i]>='a' and s[i]<='z')||(s[i]>='A' and s[i]<='Z')){
            s1+=s[i];
        }
        else if(s[i]=='('){
            stack.push('(');
        }
        else if(s[i]==')'){
            while(stack.tops()!='X' and stack.tops()!='('){
                char c=stack.tops();
                stack.pop();
                s1+=c;
            }
            if(stack.tops()=='('){
                stack.pop();
            }
        }
        else{
            while(stack.tops()!='X' and prec(s[i])<=prec(stack.tops())){
                char c=stack.tops();
                stack.pop();
                s1+=c;
            }
            stack.push(s[i]);
        }
    }
    cout<<s1;
    return 0;

}