#include<bits/stdc++.h>
using namespace std;
struct node{
    int key;
    node *left;
    node *right;
    node(int k){
        key=k;
        left=0;
        right=0;
    }
};
void inorder(node *root){  // tc=O(n) and as=O(H) or exactly H+1, H is height of tree
    if(root!=NULL){
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}
void preorder(node *root){   // tc=O(n) and as=O(H) or exactly H+1, H is height of tree
    if(root!=0){
        cout<<root->key<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(node *root){   // tc=O(n) and as=O(H) or exactly H+1, H is height of tree
    if(root!=0){
        postorder(root->left);
        postorder(root->right);
        cout<<root->key<<" ";
    }
}
int height(node *root){   // tc=O(n) and as=O(H) or exactly H+1, H is height of tree
    if(root==0) return 0;
    else return max(height(root->left),height(root->right))+1;
}
void printk(node *root,int k){    // tc=O(n) and as=O(H) or exactly H+1, H is height of tree
    if(root==0) return;
    if(k==0){
        cout<<root->key<<" ";
        return;
    }
    else{
    printk(root->left,k-1);
    printk(root->right,k-1);
    }
}

void level_order_traversal(node *root){  
    // dusra tarika bhi h traverse krne ka phele height nikalo fir call printk k=0toheight
    //lekin vo bekr h uski tc=O(nh)   
    if(root==0) return;                                     
    queue<node *> q;        // tc=theta(n) AS=O(n) ya theta(w), w=width of tree
    q.push(root); 
    while(q.empty()==0){
        node *curr=q.front();
        q.pop();
        cout<<curr->key<<" ";
        if(curr->left!=0) q.push(curr->left);
        if(curr->right!=0) q.push(curr->right);
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
            cout<<curr->key<<" ";
            if(curr->left!=0) q.push(curr->left);
            if(curr->right!=0) q.push(curr->right);
        }
    }
}
void level_order_traversal_linebyline_method2(node * root){     // tc=theta(n) AS=O(n) ya theta(w), w=width of tree
    queue<node *> q;
    q.push(root);
    while(!q.empty()){
        int count=q.size();
        for(int i=0;i<count;i++){
            node *curr=q.front();
            q.pop();
            cout<<curr->key<<" ";
            if(curr->left!=0) q.push(curr->left);
            if(curr->right!=0) q.push(curr->right);
        }
        cout<<endl;
    }

}

int size_oftree(node *root){   // tc=theta(n) AS=O(n) ya theta(w), w=width of tree  urf bekr tarika
// its an iterative solution
    if(root==0) return 0;
    queue<node *> q;
    int count=0;
    q.push(root);
    while(!q.empty()){
        node *curr=q.front();
        q.pop();
        count++;
        if(curr->left!=0) q.push(curr->left);
        if(curr->right!=0) q.push(curr->right);
    }
    return count;
}
int size_oftree_m2(node *root){         // tc=O(n) , AS=O(h) and this sol is easy so use this
// its an recursive solution
    if(root==0) return 0;
    else{
        return size_oftree_m2(root->left)+size_oftree_m2(root->right)+1;
    }
}
int max_intree(node *root){
    // ye iterative method se queue bna k bhi kr sakte the
    // dono tarike apne m best jb tree squeezed ho to iterative use kro kyu ki usme as 0(1) aaega
    //or jb purre binary tree ho tb recursive usme as=0(h) aaega or iterative m O(n)
    if(root==0) return INT_MIN;
    else {
        int z=max(max_intree(root->left),max_intree(root->right));
        return max(z,root->key);
    }
}
int maxlevel=0;
void printleftview(node *root,int level){    // tc=O(n) , AS=O(h) and this sol is easy so use this
    // ye recursive solution h, inspired from preorder traversal
    if(root==0) return;
    if(maxlevel<level){
        cout<<root->key<<" ";
        maxlevel=level;
    }
    printleftview(root->left,level+1);
    printleftview(root->right,level+1);
}
void printleftview_m2(node *root){
    // ye iterative solution h inspired from left order traversal
    if(root==0) return;
    queue<node *> q;
    q.push(root);
    while(!q.empty()){
        int count=q.size();
        for(int i=0;i<count;i++){
            node *curr=q.front();
            q.pop();
            if(i==0) cout<<curr->key<<" ";
            if(curr->left!=0) q.push(curr->left);
            if(curr->right!=0) q.push(curr->right);
        }
    }
}
void tree_to_DL(node *root,node *prev){

    if(root->left!=0){
        tree_to_DL(root->left,root);
        // tree_to_DL(root->right,root);
    }
    else{
        root->right=prev;
        return;
    }
    if(root->right!=0){
        tree_to_DL(root->right,root);
    }
    else{
        root->left=prev;
        return;
    }
}
int main(){
    node *root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->right->left=new node(40);
    root->right->right=new node(50);
    // inorder(root);
    // cout<<endl;
    // preorder(root);
    // cout<<endl;
    // postorder(root);
    // printk(root,0);
    // level_order_traversal_linebyline_method2(root);
    // cout<<size_oftree_m2(root);
    // cout<<max_intree(root);
    printleftview_m2(root);
    return 0;
}