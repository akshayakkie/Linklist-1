#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node(int val):val(val),next(NULL){}
};
class LL{
    public:
    Node* head;
    Node* tail;
    int size;
    LL(){
      head=tail=NULL;
      size=0;
    }
    void insertattail(int val){
        Node* temp=new Node(val);
        if(size==0) head=tail=temp;
        else{
            tail->next=temp;
            tail=temp;
        }
        size++;
    }
    void insertathead(int val){
        Node* temp=new Node(val);
        if(size==0) head=tail=temp;
        else{
        temp->next=head;
        head=temp;
        }
        size++;
    }
   void insertatidx(int idx,int val){
    Node* t=new Node(val);
    Node* temp=head;
    if(size<0 && size>idx) head=tail=t;
    if(size==0)  insertathead(val);
    if(size==idx) insertattail(val);
    else{
        for(int i=0;i<idx-1;i++){
            temp=temp->next;
        }
        t->next=temp->next;
        temp->next=t;
    }
    size++;
   }
   void deleteathead(){
    Node* temp=head;
    head=head->next;
    delete(temp);
    size--;
   }
   void deleteattail(){
    Node* temp=head;
    if(size==1) deleteathead();
    else{
        while(temp->next!=tail){
            temp=temp->next;
        }
        delete(tail);
        temp->next=NULL;
        tail=temp;
        size--;
    }
   }
   void deleteatidx(int idx){
    Node* temp=head;
    if(size<0 && size>idx) cout<<"invalid ll";
    if(size==1) deleteathead();
    else{
        for(int i=0;i<idx-1;i++){
            temp=temp->next;
        }
        Node* t=temp->next;
        temp->next=t->next;
        delete(t);
    }
    size--;
   }
   int getAtIdx(int idx){
    if(idx<0 || idx>=size){
     cout<<"invalid list";
     return -1;
    }
    if(idx==0) return head->val;
    if(idx==size-1) return tail->val;
    else{
        Node* temp=head;
       for(int i=0;i<idx;i++){
        temp=temp->next;
       }
       return temp->val;
    }
   }
   void display(){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
   }
};
int main(){
    LL list;
    list.insertathead(4);
    list.display();
    list.insertathead(4);
    list.insertattail(2);
    list.display();
    list.insertatidx(1,5);
    list.display();
   list.deleteathead();
    list.display();
    list.deleteattail();
    list.display();
    list.deleteatidx(1);
    list.display();
   cout<<list.getAtIdx(1)<<endl;
    
}
