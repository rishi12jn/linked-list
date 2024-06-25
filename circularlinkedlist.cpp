#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int d){
        this -> data = d;
        this -> next = NULL;
    }
    ~node(){
        int value = this -> data;
        if(this-> next !=NULL){
            delete next;
            next = NULL;
        }
        cout<<"memory free"<<value<<endl;
    }
};

void insertnode(node* &tail,int element,int d){
    if(tail==NULL){
        node* newnode=new node(d);
        tail=newnode;
        newnode -> next=newnode;
    }
    else{
        node* curr= tail;
        while(curr -> data != element){
            curr=curr -> next;
        
        }
        node* temp= new node(d);
        temp -> next= curr -> next;
        curr -> next =temp;
    }
}

void print( node* tail){
    node* temp=tail;
    do{
        cout<<tail -> data<< " ";
        tail=tail -> next;
    }while(tail != temp);
}

void deletenode(node* &tail,int value){
    if(tail==NULL){
        cout<<"list is empty"<<endl;
        return;
    }
    else{
        node* prev= tail;
        node* curr =prev -> next;

        while(curr -> data != value){
            prev= curr;
            curr=curr -> next;
        }
        prev -> next =curr -> next;
        curr -> next = NULL;
        delete curr;
    }
}

int main(){
    node* tail= NULL;
    insertnode(tail,5,3);
    print(tail);
}