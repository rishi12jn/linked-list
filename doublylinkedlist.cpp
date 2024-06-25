#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* prev;
    node* next;

    node (int d){
        this -> data=d;
        this -> prev = NULL;
        this -> next = NULL;
    }
    ~node(){
        int val= this -> data;
        if(next != NULL){
            delete next;
            next= NULL;
        }
        cout<<"mmenory free"<<val;
    }

};

void print(node* head){
    node* temp= head;
    while(temp != NULL){
        cout<<temp -> data;
        temp= temp -> next;
    }
    cout<<endl;
}

int getlength(node* head){
    int len=0;
    node* temp= head;
    while(temp != NULL){
        len++;
        temp= temp -> next;
    }
    return len;
} 

void insertathead(node* &head,int d){
    node* temp = new node(d);
    temp -> next = head;
    temp -> prev = temp;
    head=temp;
}

void insertattail(node* &tail,int d){
    node* temp=new node(d);
    tail -> next = temp;
    temp -> prev =tail;
    tail=temp;
}

void deletenode(int position,node* &head){
    if(position==1){
        node* temp=head;
        temp -> next -> prev = NULL;
        head= temp -> next;
        temp -> next =NULL;
        delete temp;
    }
    else{
        node* curr=head;
        node* prev=NULL;

        int cnt=1;
        while(cnt<=position){
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        prev->next=curr->next;
        delete curr;

        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;

    }
}

int main(){
    node* node1=new node(10); 
    node* head =node1;

    print(head);
    cout<<getlength(head)<<endl;

    insertathead(head,11);
    print(head);

}