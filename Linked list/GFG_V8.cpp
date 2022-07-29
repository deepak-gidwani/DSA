#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *next;
    node(){
    }
    node(int x){
        data=x;
        next=NULL;
    }
};
node * insert(node *head,int x){
   node *temp=new node(x);
//    temp->data=x;
   temp->next=head;
   return temp;
}
node * insertend(node * head,int x){
    node * temp=new node(x);
    if(head==NULL){
        return temp;
    }
    node *curr=head;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=temp;
    return head;
}
node * insertpos(node *head,int pos,int data){
    node *temp=new node(data);
    node *curr=head;
    if(pos==1){
        temp->next=head;
        return temp;
    }
    for(int i=1;i<pos-1 && curr!=0;i++){
        curr=curr->next;
    }
    if(curr==0) return head;
    temp->next=curr->next;
    curr->next=temp;
    return head;
}
node * deletehead(node *head){
    node *res;
    if(head->next==0 || head==0) return NULL;
    res=head->next;
    delete head;
    return res;
}
node * deletelast(node *head){
    if(head==0 ) return NULL;
    if(head->next==0){
        delete head;
        return NULL;
    }
    node *temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=0;
    return head;
}
int search(node *head,int x){
    node *curr=head;
    for(int i=1;curr!=0;i++){
        if(curr->data==x) return i;
        curr=curr->next;
    }
    return -1;
}
void display(struct node *head){
    while(head!=NULL){
        cout<<head->data<<endl;
        head=head->next;
    }
}

struct node* reverseList(struct node *head)
    {
        // code here
        node *prev=0;
        node *curr=head;
        node *next=0;
        while(curr!=0){
            next = curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
        // return head of reversed list
    }



int main(){
    node *head;
    head=NULL;
    head=insertend(head,1);
    head=insertend(head,2);
    head=insertend(head,3);
    display(head);
    head=reverseList(head);
    display(head);
    // head=insertpos(head,1,4);
    // cout<<search(head,4)<<endl;
    // head=deletehead(head);
    // head=deletelast(head);
    return 0;
}