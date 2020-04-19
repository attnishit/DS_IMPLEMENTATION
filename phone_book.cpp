#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        char number[50];
        char gmail[40];
        char name[30];
        Node *previous,*next;
        Node(char n[],char r[],char g[]){
            strcpy(name,n);
            strcpy(number,r);
            strcpy(gmail,g);
            next=NULL;
            previous=NULL;
        }
    friend class dlist;
};
class dlist {
    Node *head,*temp,*ptr;
public:
    Node *previousn;        
    void insert();
    void sort();
    void deletecontact(char n[20]);
    void searchbyname(char p[20]);
    void searchbynumber(char no[30]);
    void searchbygmail(char g[20]);
    void accept();
    void display();
    void update(char ch[10]);
    dlist(){
        head = NULL;
        temp = NULL;
        ptr = NULL;
    }
};
void dlist::accept(){
    char number[60];
    char gmail[60];
    char name[60];
    char ans;
    do{
        cout << "ENTER NAME : ";
        cin>>name;
        cout << "ENTER  PHONE NUMBER : ";
        cin >> number;
        cout << "ENTER G-MAIL : ";
        cin >> gmail;
        temp = new Node(name,number,gmail);
        if(head == NULL){
            head = temp;
        }
        else{
            ptr = head;
            while(ptr->next != NULL){
                ptr = ptr->next;
            }
            ptr->next = temp;
            temp->previous = ptr;
        }
        cout<<"DO YOU WANT TO CONTINUE? PRESS 'y' FOR YES : ";
            cin >> ans;
    }while(ans == 'y');

}
void dlist::display(){
    ptr = head;
    while(ptr != NULL){
            cout << "\n\nNAME  ::\t" << ptr->name;
            cout << "\nNUMBER::\t+91-" << ptr->number;
            cout << "\nG-MAIL::\t" << ptr->gmail;
            ptr = ptr->next;
    }
}

void dlist::insert(){
    accept();
}
void dlist::sort(){
    Node *i,*j;
    int temp;
    char n[10];
    // selection sort
    for(i=head;i->next!=NULL;i=i->next){
        for(j=i->next;j!=NULL;j=j->next){
            temp=strcmp(i->name,j->name);
            if(temp>0){
               strcpy(n,i->name);
               strcpy(i->name,j->name);
               strcpy(j->name,n);
            }
        }
    }
}
void dlist::deletecontact(char s[20]){
    int c=0;
    ptr=head;
    while(ptr!=NULL){
        if(strcmp(s,ptr->name)==0){
            c=1;
            break;
        }
        else{
            c=2;
        }
        ptr=ptr->next;
    }
    if(c == 1 and ptr != head and ptr->next != NULL){
        ptr->previous->next = ptr->next;
       ptr->next->previous = ptr->previous;
       delete(ptr);
    }
    if(ptr == head){
        head = head->next;
        head->previous = NULL;
        delete(ptr);
    }
    if(ptr->next == NULL){
        ptr->previous->next = NULL;
        ptr->previous = NULL;
        delete(ptr);
    }
    if(c == 2){
        cout<<"ENTERED NAME IS NOT IN THE  PHONE LIST\n";
    }
    else{
        cout<<"YOUR CONTACT IS SUCCESSFULLY DELETED\n\n";
    }

}
void dlist::searchbyname(char na[10]){
    ptr = head;
    int c = 0;
    while(ptr != NULL){
        if(strcmp(na,ptr->name) == 0){
            cout << "NAME FOUND" << endl;
            cout << "CONTACT DETAILS ARE BELOW:\n" << endl;
            cout << "\n\nNAME  ::\t" << ptr->name;
            cout << "\nNUMBER::\t+91-" << ptr->number;
            cout << "\nG-MAIL::\t" << ptr->gmail;
            c = 1;
            break;   
        }
        ptr=ptr->next;
    }
    if(!c){
        cout << "NAME NOT FOUND \n";
    }
}
void dlist::searchbynumber(char num[20]){
    ptr = head;
    int c = 0;
    while(ptr != NULL){
        if(strcmp(num,ptr->number) == 0){
            cout << "NUMBER FOUND\n" << endl;
            cout << "CONTACT DETAILS ARE BELOW:\n" << endl;
            cout << "\n\nNAME  ::\t" << ptr->name;
            cout << "\nNUMBER::\t+91-" << ptr->number;
            cout << "\nG-MAIL::\t" << ptr->gmail;
            c = 1;
            break;
        }
        ptr = ptr->next;
    } 
    if(!c){
        cout << "PHONE NUMBER IS NOT PRESENT \n";
    }  
}
void dlist::searchbygmail(char gm[20]){
    ptr=head;
    int c = 0;
    while(ptr != NULL){
        if(strcmp(gm,ptr->gmail) == 0){
            cout << "G-MAIL FOUND\n" << endl;
            cout << "CONTACT DETAILS ARE BELOW:\n" << endl;
            cout << "\n\nNAME  ::\t" << ptr->name;
            cout << "\nNUMBER::\t+91-" << ptr->number;
            cout << "\nG-MAIL::\t" << ptr->gmail;
            c = 1;
            break;
        }
        ptr = ptr->next;
    }
    if(!c){
        cout << "EMAIL ADDRESS IS NOT PRESENT \n";
    }
}
void dlist::update(char n[20]){
    char ans;
    int c;
    ptr = head;
    while(ptr != NULL){
        if(strcmp(n,ptr->name) == 0){
            do{
                cout << "\nWHAT DO YOU WANT TO UPDATE?\n1.NAME\n2.PHONE NUMBER\n3.G-MAIL\n";
                cin >> c;
                switch(c){
                    case 1:
                            cout << "ENTER NEW-NAME=";
                            cin >> ptr->name;
                            break;
                    case 2:
                            cout << "ENTER NEW PHONE-NUMBER?";
                            cin >> ptr->number;
                            break;
                    case 3:
                            cout << "ENTER NEW G-MAIL";
                            cin>>ptr->gmail;
                            break;
                }
                cout << "DO YOU WANT TO CONTINUE UPDATING?";
                cin >> ans;
            }while(ans == 'y');
        }
        ptr = ptr->next;
    }
}
int main(){
    char n[20];
    char nam[20];
    char name[10];
    char number[10];
    char gmail[20];
    dlist d1;
    char ans;
    int ch,a;
    cout << "************************************************\n";
    cout << "************************************************\n";
    cout << "************************************************\n";
    cout << "****************PHONE BOOK**********************\n";
    cout << "************************************************\n";
    cout << "************************************************\n";
    cout << "************************************************\n";
    cout << "\nENTER THE DETAILS OF A PERSON YOU WANT TO ADD TO YOUR PHONEBOOK \n";
    d1.accept();
    d1.sort();
    do{
        cout << "\n\n\n\n1) DISPLAY YOUR PHONE BOOK\n2) INSERT NEW CONTACT\n3) UPDATE DETAILS ON EXISTING CONTACT\n4) DELETE CONTACT\n5) SEARCH\n";
        cin >> ch;
        switch(ch){
        
            case 1:
                d1.display();
                break;
            case 2:
                d1.insert();
                d1.sort();
                break;
            case 3:
                cout << "\n\nENTER THE NAME OF PERSON WHOSE DETAILS YOU WANT TO UPDATE...\n";
                cin >> n;
                d1.update(n);
                d1.sort();
                break;
            case 4:
                cout << "\nENTER THE NAME YOU WANT TO DELETE FROM PHONEBOOK\n";
                cin >> name;
                d1.deletecontact(name);
                break;
            case 5:
                    cout << "1.SEARCH BY NAME\n2.SEARCH BY NUMBER\n3.SEARCH BY GMAIL";
                    cin >> a;
                    switch(a){
                        case 1:
                                cout << "ENTER THE NAME TO BE SEARCHED\n";
                                cin >> name;
                                d1.searchbyname(name);
                                break;
                        case 2:
                                cout << "ENTER THE NUMBER TO BE SEARCHED\n";
                                cin >> number;
                                d1.searchbynumber(number);
                                break;
                        case 3:
                                cout << "ENTER THE EMAIL ADDRESS TO BE SEARCHED\n";
                                cin >> gmail;
                                d1.searchbygmail(gmail);
                                break;
                        default:
                                cout << "\nINVALID CHOICE\n";
                    }
                    break;

            default:
                    cout<<"\nINVALID CHOICE\n";
        }
        cout << "\n\nDO YOU WANT TO CONTINUE OPERATIONS?????????";
        cin >> ans;
    }while(ans=='y');
    return 0;
}