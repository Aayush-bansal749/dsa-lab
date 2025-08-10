#include <iostream>
using namespace std;


class Node{
    public: 
    int data;
    Node * next;
   
    Node(int x){
        data = x;
        next = NULL;
    }
};

class LinkedList{
    Node* head;
    Node* tail;
  public:
  LinkedList(){
    head=NULL;
    tail=NULL;
  }
   void  insertE(int x){
        Node* new1 = new Node(x);
        if(head==NULL){
            head = new1;
            tail = new1;
        }
        else{
            tail->next = new1;
            tail = new1;
        }
    }
    void print(){
        Node*temp = head;
        while(temp!= NULL){
            cout<<temp->data<<endl;
            temp=temp->next;
        }
    }
};