#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *left=0,*right=0;
    node(int x){
        data=x; 
        left=0;
        right=0;
    }
};
void solve(node *root){
    queue<node *> q;
    vector<int> ans;
    int j=0;
    map<int,stack<int>> m;
    bool flag=true;
    q.push(root);
    while(!q.empty()){
        j++;
        int count=q.size();
        for(int i=0;i<count;i++){
            node *curr=q.front();
            q.pop();
            if(flag) cout<<curr->data<<" ";
            else{
                m[j].push(curr->data);
            };
            if(curr->left!=0) q.push(curr->left);
            if(curr->right!=0) q.push(curr->right);
        }
        flag=!flag;
        if(j%2!=0) cout<<endl;
    }
    for(auto x:m){
        while(!x.second.empty()){
            cout<<x.second.top()<<" ";
            x.second.pop();
        }
        cout<<endl;
    }
}
int main(){
    node *root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->left->left=new node(40);
    root->left->right=new node(50);
    root->right->left=new node(60);
    root->right->right=new node(70);
    root->right->left->left=new node(80);
    root->right->left->right=new node(90);
    solve(root);
    return 0;
}