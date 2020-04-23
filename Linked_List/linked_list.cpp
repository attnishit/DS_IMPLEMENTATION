#include<bits/stdc++.h>
using namespace std;
template<class T>
class Node{
	public:
		T data;
		Node* link;
};
template<class T>
class linked_list{
	private:
		Node<T>* start;
		int size;
	public:
		linked_list(){
			start=NULL;
			size=0;
		}
		void insert_at_beginning(T item){
			Node<T>* new_node=new Node<T>;
			new_node->data=item;
			new_node->link=start;
			start=new_node;
			size++;
		}
		void insert_at_last(T item){
			if(start==NULL){
				insert_at_beginning(item);
				return;
			}
			Node<T>* tmp=start;
			Node<T>* new_node=new Node<T>;
			new_node->data=item;
			new_node->link=NULL;
			while(tmp->link!=NULL){
				tmp=tmp->link;				
			} 
			tmp->link=new_node;
			size++;
		}
		void insert(T item,int position){
			if(position<=0){
				insert_at_beginning(item);
				return;
			}
			if(position>=size-1){
				insert_at_last(item);
				return;
			}
			Node<T>* new_node=new Node<T>;
			Node<T>* tmp=start;
			for(int i=1;i<position-1;i++){
				tmp=tmp->link;
			}
			new_node->link=tmp->link;
			new_node->data=item;
			tmp->link=new_node;
			size++;
		}
		void display_list(){
			Node<T>* tmp=start;
			cout<<"start->";
			while(tmp!=NULL){
				cout<<tmp->data<<"->";
				tmp=tmp->link;
			}
			cout<<"end\n";
		}
		void delete_front(){
			if(size<=0){
				cout<<"Underflow\n";
				return ;
			}
			Node<T>* tmp=start;
			start=start->link;
			delete tmp;
			size--;
		}
		void delete_last(){
			if(size<=0||start==NULL){
				cout<<"Underflow\n";
				return ;
			}
			if(start->link==NULL){
				delete_front();
				return;
			}

			Node<T>* tmp=start;
			Node<T>* second_last;
			while(tmp->link!=NULL){
				second_last=tmp;
				tmp=tmp->link;
			}
			second_last->link=NULL;
			delete tmp;
			size--;
		}
		void delete_any(int position){
			position--;
			if(size<=0){
				cout<<"Underflow\n";
				return;
			}
			if(position<=0){
				delete_front();
				return;
			}
			if(position>=size-1){
				delete_last();
				return;
			}
			Node<T>* tmp=start;
			int c=0;
			while(c<position-1){
				c++;
				tmp=tmp->link;
			}
			if(tmp==NULL||tmp->link==NULL){
				cout<<"Underflow\n";
				return;
			}
			Node<T>* point=tmp->link;
			tmp->link=point->link;
			delete point;
			size--;

		}
		void detect_cycle(){
			Node<T>* slow = start;
			Node<T>* fast = start;
			int f = 0;
			while(slow and fast and fast->link){
				slow = slow->link;
				fast = fast->link->link;
				if(slow == fast){
					f = 1;
					cout <<"cycle found\n";
					Node<T>* tmp = slow;
					int c = 0;
					while(tmp!=slow){
						c++;
						tmp = tmp->link;
					}
					cout << "length of cycle is = " << c << endl; 
					break;
				}
			}
			if(!f){
				cout << "cycle not found\n";
			}
			
		}
};
int main()
{	int n;
	linked_list<int>list;
	cout<<"enter the no of Nodes\n";
	cin >> n;
	int x;
	cout<<"enter the elements of linked_list\n";
	for(int i=0;i<n;i++){
		cin >> x;
		list.insert_at_last(x);
	}
	cout<<"current list is\n";
	list.display_list();
	int choice,val,position;
	cout<<"enter your choice\n";
	cout<<"1. For Insertion At Beginning\n";
	cout<<"2. For Insertion At End\n";
	cout<<"3. For Insertion At Any Position\n";
	cout<<"4. For Deletion From Beginning\n";
	cout<<"5. For Deletion From End\n";
	cout<<"6. For Deletion From Any Position\n";
	cout<<"7. Display current list\n";
	cout<<"8. Detect cycle and  its length\n";
	cout<<"0. For Quit\n";
	cin >> choice;
	while(choice){
		switch(choice){
			case 1:
					cin >> val;
					list.insert_at_beginning(val);
					list.display_list();
					break;
			case 2:				
					cin >> val;
					list.insert_at_last(val);
					list.display_list();
					break;
			case 3:
					cin >> val >> position;
					list.insert(val,position);
					list.display_list();
					break;
			case 4:
					list.delete_front();
					list.display_list();
					break;
			case 5:
					list.delete_last();
					list.display_list();
					break;
			case 6:
					cin >> position;
					list.delete_any(position);
					list.display_list();
					break;
			case 7:
					list.display_list();
					break;
			case 8:
					list.detect_cycle();
					break;
			default:
					cout<<"wrong choice,please input again\n";
		}
		cout<<"enter your choice again\n";
		cin >> choice;
		if(choice==0){
			cout<<"program terminated\n";
			return 0;
		}
	}
	return 0;
}