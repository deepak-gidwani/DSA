#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *left=0,*right=0;
    node(int x){
        data=x;
    }
};

int floor(node *root,int x){
    node *curr=root;
    int store=INT_MIN;
    // bool flag=true;
    while(curr!=0){
        // cout<<"b";
        if(curr->data==x) return root->data;
        else if(x>curr->data){  // element hamesha left m hi milega
            // if(flag){    es code ki need nahi
            //     store=curr->data;
            //     flag=false;
            // }
            // if(store<curr->data && curr->data<x) store=curr->data;
            store=curr->data;
            curr=curr->right;
        }
        else{
            // cout<<"c";
            curr=curr->left;
        }
    }
    return store;
}
node * celing(node *root,int x){
    node *curr=root;
    node *store=0;
    while(curr!=0){
        if(curr->data==x) return root;
        else if(curr->data>x){
            store=curr;
            curr=curr->left;
        }
        else{
            // cout<<curr->data<<" ";
            curr=curr->right;
        }
    }
    return store;

}
int main(){
    node *root=new node(50);
    root->left=new node(30);
    root->right=new node(70);
    root->left->left=new node(20);
    root->left->right=new node(40);
    root->right->left=new node(60);
    root->right->right=new node(80);
    root->right->left->left=new node(55);
    root->right->left->right=new node(65);
    node *temp=celing(root,37);
    cout<<temp->data;

    return 0;
}