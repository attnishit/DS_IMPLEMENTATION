#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define MAX 10000

template<class T>
class Stack{
      int top;
      T a[MAX];
public:
        Stack(){
            top=-1;
        }
        void pop(){
            if(top<0){
                cout<<"UNDERFLOW\n";
                return ;
            }
            T x=a[top--];
            cout<<x<<" ";
            return ;


        }
        void push(T val){
            if(top>=MAX-1){
                cout<<"OVERFLOW\n";
                return ;
            }
            a[++top]=val;
        }

};

int main(){
    int n;
    cin >> n;
    string x;
    Stack<string>obj;
    for(int i=0;i<n;i++){
        cin >> x;
        obj.push(x);
    }
    f(i,0,n+1){
        obj.pop();
    }
    return 0;



}