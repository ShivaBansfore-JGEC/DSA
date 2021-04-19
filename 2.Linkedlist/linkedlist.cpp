#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node *next;
    int data;
};


class LinkList{

    Node *head,*tail;
    int size=0;
    public:

        int getTail(){
            if(tail==NULL){
                cout<<"list is empty"<<endl;
                return -1;
            }else{
                return tail->data;
            }
        }

        int getHead(){
            if(head==NULL){
                cout<<"list is empty"<<endl;
                return -1;
            }else{
                return head->data;
            }
        }

        int get_size(){
            return size;
        }

        void addFirst(int val){
            //create a node
            Node *node =new Node();
            node->data=val;
            if(size==0){
                head=node;
                tail=node;
                size++;
                return;
            }

            node->next=head;
            head=node;
            size++;
        }
        void addLast(int val){
            Node *new_node=new Node();
            new_node->data=val;
            new_node->next=NULL;

            if(size==0){
                head=new_node;
                tail=new_node;
                size++;
            }else{
                tail->next=new_node;
                tail=new_node;
                size++;
            }
        }

        void addAt(int idx,int val){
            if(idx<0 || idx>=size){
                cout<<"Invalid index"<<endl;
                return;
            }

            Node *node =new Node();
            node->data=val;

            Node *temp=head;
            for(int i=0;i<idx-1;i++){
                temp=temp->next;
            }
            node->next=temp->next;
            temp->next=node;
            size++;
        }

        void removeFirst(){
            if(size==1){
                head=NULL;
                tail=NULL;
                size--;
            }else{
                Node *temp=head->next;
                head=temp;
                size--;
            }
        }

        int getVal(int idx){
            if(idx<0 || idx>=size){
                cout<<"Invalid Index"<<endl;
                return -1;
            }

            Node *temp=head;
            for(int i=0;i<idx;i++){
                temp=temp->next;
            }

            return temp->data;
        }

        int getKthNode(int idx){
            if(idx<0 || idx>=size){
                cout<<"Invalid Input"<<endl;
            }

            Node *s,*f;
            s=f=head;
            for(int i=0;i<idx;i++){
                f=f->next;
            }

            while(f!=tail){
                s=s->next;
                f=f->next;
            }
            return s->data;

        }

        void removeLast(){
            if(size==0){
                cout<<"List is empty"<<endl;
            }else if(size==1){
                head=tail=NULL;
                size=0;
            }else{
                Node *temp=head;
                while(temp->next!=tail){
                    temp=temp->next;
                }
                temp->next=NULL;
                tail=temp;
                size--;
            }
        }

        void removeAt(int idx){
            if(idx<0 || idx>=size){
                cout<<"Invalid index"<<endl;
                return;
            }

            if(size==0){
                cout<<"list is empty"<<endl;
            }else if(size==1){
                head=tail=NULL;
                size=0;
            }else if(idx==0){
                removeFirst();
            }else if(idx==size-1){
                removeLast();
            }else{
                Node *p1,*p2;
                p1=head,p2=head->next;

                for(int i=0;i<idx-1;i++){
                    p1=p1->next;
                    p2=p2->next;
                }

                p1->next=p2->next;
                size--;
            }
        }

        int midOfLinkedList(){
            Node *fast,*slow;
            fast=slow=head;

            while(fast!=NULL && fast->next!=NULL){
                fast=fast->next->next;
                slow=slow->next;
            }

            return slow->data;
        }


        // data iterative approach
        void reverse_LinkedList_Data(){
            
        }

        void display(){
            Node *temp=head;
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }

        
};

int main(){

    LinkList list;
    list.addLast(5);
    list.addLast(6);
    list.addLast(8);
    list.addLast(9);
    list.removeFirst();
    list.display();
    cout<<list.getVal(3)<<endl;
    list.addFirst(1);
    list.addFirst(3);

    list.display();
    list.addAt(2,5);
    list.display();
    int val=list.getKthNode(3);
    cout<<"kth node : "<<val<<endl;
    cout<<"mid of the linkedlist :"<<list.midOfLinkedList()<<endl;
    cout<<list.getTail()<<endl;
    list.removeLast();
    list.removeAt(2);
    list.display();
    cout<<list.get_size()<<endl;
    return 0;
}