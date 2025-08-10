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
    int sum;
  public:
  LinkedList(){
    head=NULL;
    tail=NULL;
    sum=0;
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
            tail->next = head;
        }
        sum+=x;
    }
    void print(){
        Node* temp = head;
         cout<<endl<<temp->data;
            temp=temp->next;
       while(temp != head) {
            cout<<"->"<<temp->data;
            temp=temp->next;
        } 
    }
    void modify(){
        Node* temp = head;
         do{
            temp->data=sum-temp->data; 
            temp=temp->next;
    }while(temp != head);}
};


int main(){
    LinkedList here;
    here.insertE(6);
    here.insertE(7);
    here.insertE(6);
    here.insertE(7);
    here.insertE(8);
    here.insertE(6);
    here.print();
    here.modify();
    here.print();
}
