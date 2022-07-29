#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *next;
    node(int x){
        data=x;
        next=0;
    }
};
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
bool detectLoop(node* head)
    {
        // your code here
        if(head==0) return 0;
        node *curr=head->next;
        while(curr->next!=0){
            node *temp=head;
            while(temp!=curr){
                if(curr->next==temp) return true;
                else{
                    temp=temp->next;
                }
                if(temp==curr && curr->next==curr) return true;
            }
            curr=curr->next;
        }
        return false;
    }
int main(){
    node *one=0;
    one=insertend(one,1);
    one=insertend(one,2);
    one=insertend(one,3);
    one->next->next->next=one->next->next;
    cout<<(int)detectLoop(one);
    return 0;
}