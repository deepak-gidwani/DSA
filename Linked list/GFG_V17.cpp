#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *next;
    node *prev;
    node(){
    }
    node(int x){
        data=x;
        next=0;
        prev=0;
    }
};
node * insertbeg(node *head,int x){
    node *temp=new node(x);
    if(head==0) return temp;
    temp->next=head;
    head->prev=temp;
    return temp;
}
node * insertend(node *head,int x){
    node *temp=new node(x);
    if(head==0) return temp;
    node *curr=head;
    while(curr->next!=0){
        curr=curr->next;
    }
    curr->next=temp;
    temp->prev=curr;
    return head;
}
node * reverse(node *head){
    if(head==0) return 0;
    node *curr=head;
    while(curr->next!=0){
        swap(curr->prev,curr->next);
        curr=curr->prev;
    }
    swap(curr->next,curr->prev);
    return curr;
}
node * delhead(node *head){
    if(head==0) return 0;
    else if(head->next==0){
        delete head;
        return 0;
    }
    else{
        node *curr=head->next;
        curr->prev=0;
        delete head;
        return curr;
    }
}
node * dellast(node *head){
    if(head==0) return 0;
    if(head->next==0){
        delete head;
        return 0;
    }
    node *curr=head;
    while(curr->next->next!=0){
        curr=curr->next;
    }
    delete curr->next;
    curr->next=0;
    return head;
}
void display(node *head){
    while(head!=0){
        cout<<head->data<<endl;;
        head=head->next;
    }
}
int main(){
    
    node *head=0;
    head=insertbeg(head,1);
    head=insertbeg(head,2);
    head=insertbeg(head,3);
    head=insertend(head,4);
    display(head);
    head=dellast(head);
    display(head);
    return 0;
}