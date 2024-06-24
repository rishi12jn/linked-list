#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int data){
        int data;
        this -> data=data;
        this -> next= NULL;
    }
     
};

void insertathead(node* &head,int d){
    //new node create
    node* temp=new node(d);
    temp->next=head;
    head=temp;
}

void print(node* &head){
    node* temp=head;

    while(temp!= NULL){
        cout<<temp ->data<<" ";
        temp=temp->next;
    }
    cout<<endl; 
}

void insertatpositon(node* &head,int pos, int d){

    node* temp=head;
    int cnt=1;

    while(cnt<pos-1){
        temp=temp->next;
        cnt++;
    }

    node* nodetoinsert=new node(d);
    nodetoinsert->next=temp->next;
    temp->next=nodetoinsert;


}

void deletenode(int position,node* &head){
    if(position==1){
        node* temp=head;
        head=head->next;
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
    }
}

int main(){
    node* node1=new node(10);
    cout<<node1->data<<endl;
    cout<<node1->next<<endl;

    node* head=node1;
    print(head);

    insertathead(head,12);
    
    print(head);
}