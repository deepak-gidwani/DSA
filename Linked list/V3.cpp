#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *next;
};
void create(struct node *head,int n){
    struct node *temp,*last;
    head->data=0;
    head->next=NULL;
    last=head->next;
    for(int i=1;i<n;i++){
        // head->data=i;
        last=new struct node;
        last->data=i;
        last->next=NULL;
        last=last->next;
    }
    
   
}
void display(struct node *head){
    while(head!=NULL){
        cout<<head->data<<endl;
        head=head->next;
    }
}
int main(){
    struct node *head;
    head=new struct node;
    create(head,10);
    display(head);
    return 0;
}