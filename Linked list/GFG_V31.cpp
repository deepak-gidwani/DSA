#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *next;
    node *prev;
    node(){}
    node(int x){
        data=x;
        next=NULL;
        prev=NULL;
    }
};
node * insertbeg(node *head,int x){
    node *temp=new node(x);
    temp->next=temp;
    temp->prev=temp;
    if(head==0) return temp;
    else{
        temp->next=head;
        temp->prev=head->prev;
        head->prev->next=temp;
        head->prev=temp;
        return temp; // temp ki jgh head bhej do to ye fxn insertend bn jaega
    }
}
node * insertend(node *head,int x){
    node *temp=new node(x);
    temp->next=temp;
    temp->prev=temp;
    if(head==0) return temp;
    else{
        temp->next=head;
        temp->prev=head->prev;
        head->prev->next=temp;
        head->prev=temp;
        return head; 
    }
}
void display(node *head){
    if(head==0) return;
    node *curr=head->next;
    cout<<head->data<<endl;
    while(curr!=head){
        cout<<curr->data<<endl;
        curr=curr->next;
    }
}
int main(){
    node *head=NULL;
    head=insertbeg(head,10);
    head=insertbeg(head,20);
    head=insertbeg(head,30);
    display(head);
    head=insertend(head,40);
    display(head);
    return 0;
}