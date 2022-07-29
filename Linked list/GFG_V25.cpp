#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *next;
    node(){}
    node(int x){
        data=x;
        next=0;
    }
};
node * insertbeg(node *head,int x){
    node *temp=new node(x);
    // if(head==0){  // O(n) tc h iski tail pointer use krke O(1) m bhi kr sakte h
    //     temp->next=temp;
    //     return temp;
    // }
    // else{
    //     temp->next=head;
    //     node *curr=head;
    //     while(curr->next!=head){
    //         curr=curr->next;
    //     }
    //     curr->next=temp;
    //     return temp;
    // }
    if(head==0){  // iski tc bhi O(1) hai
        temp->next=temp;
        return temp;
    }
    else{
        temp->next=head->next;
        head->next=temp;
        swap(head->data,temp->data);
        return head;
    }
}
node * insertend(node *head,int x){
    node *temp=new node(x);  // O(1) tc
    if(head==0){
        temp->next=temp;
        return temp;
    }
    else{
        temp->next=head->next;
        head->next=temp;
        swap(temp->data,head->data);
        return temp;
    }
}
node * delhead(node *head){
    if(head==0) return 0;
    if(head->next==head){
        delete head;
        return 0;
    }
    // node *curr=head; // theta(n) tc h iski
    // while(curr->next!=head){
    //     curr=curr->next;
    // }
    // curr->next=head->next;
    // delete head;
    // return curr->next;
    node *curr=head->next; // theta(1) tc iski
    head->next=curr->next;
    swap(head->data,curr->data);
    delete curr;
    return head;

}
node * deletek(node *head,int k){
    if(head==0) return 0;
    if(k==1){
        return delhead(head);
    }
    node *curr=head;
    for(int i=1;i<k-1;i++){
        curr=curr->next;
    }
    node *temp=curr->next;
    curr->next=curr->next->next;
    delete temp;
    return head;
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
    node *head=0;
    head=insertbeg(head,10);
    head=insertbeg(head,20);
    head=insertbeg(head,30);
    head=insertbeg(head,40);
    head=insertend(head,15);
    head=insertend(head,25);
    display(head);
    head=deletek(head,6);
    display(head);
    return 0;
}