#include <iostream>
using namespace std;

class Node{
    public: 
    int data;
    Node * next;
    Node * prev;
    Node(int x){
        data = x;
        next = NULL;
        prev = NULL;
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
            new1->prev = tail;
            tail = new1;

            
        }
        
    }
    void print(){
        Node* temp = head;
         cout<<endl<<temp->data;
            temp=temp->next;
       while(temp != NULL) {
            cout<<"<->"<<temp->data;
            temp=temp->next;
        } 
    }
    void deleteNode(Node* temp){
         if (temp == head) {
            head = temp->next;
            if (head) head->prev = NULL;
            else tail = NULL; // List became empty
        }
        // If temp is tail
        else if (temp == tail) {
            tail = temp->prev;
            if (tail) tail->next = NULL;
            else head = NULL; // List became empty
        }
        // Middle node
        else {
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
        }
        delete temp;
    }

    int digitSum(int num) {
        num = abs(num);
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum%2;
    }

    void modify(){
        Node* temp = head;
        Node * check;
          while(temp != NULL) {
            check = temp;
            temp=temp->next;
            if(!digitSum(check->data)){
                deleteNode(check);
            }
        }
        } 
};


int main(){
    LinkedList here;
    here.insertE(9);
    here.insertE(11);
    here.insertE(34);
    here.insertE(6);
    here.insertE(13);
    here.insertE(21);
    here.print();
    here.modify();
    here.print();
}
