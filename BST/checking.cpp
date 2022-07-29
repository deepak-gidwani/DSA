#include<bits/stdc++.h>
using namespace std;
struct node{
    string data;
    node *left=0,*right=0;
    node(string x){
        data=x; 
        left=0;
        right=0;
    }
};
void solve(node *root){
    queue<node *> q;
    vector<string> ans;
    int j=0;
    map<int,stack<string>> m;
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
node *insert(node *root, string data)
{
    if (root == NULL)
    {
        root = new node(data);
        return root;
    }
    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp->left != NULL)
            q.push(temp->left);
        else
        {
            temp->left = new node(data);
            return root;
        }

        if (temp->right != NULL)
            q.push(temp->right);
        else
        {
            temp->right = new node(data);
            return root;
        }
    }
}
void level_order_traversal_linebyline(node *root){   // tc=theta(n) AS=O(n) ya theta(w), w=width of tree
if(root==0) return;
    queue<node *> q;
    q.push(root);
    q.push(0);
    while(q.size()>1){
        node *curr=q.front();
        q.pop();
        if(curr==0){
            cout<<"\n";
            q.push(0);
        }
        else{
            cout<<curr->data<<" ";
            if(curr->left!=0) q.push(curr->left);
            if(curr->right!=0) q.push(curr->right);
        }
    }
}
int main(){
    node*root=NULL;
    root=insert(root,"a");
    insert(root,"b");
    insert(root,"c");
    insert(root,"d");
    insert(root,"e");
    insert(root,"f");
    insert(root,"g");
    insert(root,"h");
    insert(root,"i");
    // solve(root);
    level_order_traversal_linebyline(root);
    return 0;
}