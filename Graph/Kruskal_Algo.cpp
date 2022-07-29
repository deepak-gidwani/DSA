#include<bits/stdc++.h>
using namespace std;
//tc=O(ElogE), E=no. of edges, SC=O(V)
struct node{
    int u,v;
    int weight;
    node(int u,int v,int weight){
        this->u=u;
        this->v=v;
        this->weight=weight;
    }
};
bool cmp(node &a,node &b){
    return a.weight<b.weight;
}
int find(int x,vector<int> &parent,vector<int> &rank){
    if(x==parent[x]) return x;
    parent[x]=find(parent[x],parent,rank);
    return parent[x];
}
void Union(int x,int y,vector<int> &parent,vector<int> &rank){
    int x_rep=find(x,parent,rank);
    int y_rep=find(y,parent,rank);
    if(y_rep==x_rep) return;
    if(rank[x_rep]>rank[y_rep]) parent[y_rep]=x_rep;
    else if(rank[x_rep]<rank[y_rep]) parent[x_rep]=y_rep;
    else{
        parent[y_rep]=x_rep;
        rank[x_rep]++;
    }
}
int main(){
    vector<node> edges;
    // edges.push_back(node(5,4,9));
    // edges.push_back(node(5,1,4));
    // edges.push_back(node(4,1,1));
    // edges.push_back(node(4,3,5));
    // edges.push_back(node(4,2,3));
    // edges.push_back(node(1,2,2));
    // edges.push_back(node(3,6,8));
    // edges.push_back(node(3,2,3));
    // edges.push_back(node(2,6,7));
    edges.push_back(node(0,1,2));
	edges.push_back(node(0,3,6));
	edges.push_back(node(1,0,2));
	edges.push_back(node(1,2,3));
	edges.push_back(node(1,3,8));
	edges.push_back(node(1,4,5));
	edges.push_back(node(2,1,3));
	edges.push_back(node(2,4,7));
	edges.push_back(node(3,0,6));
	edges.push_back(node(3,1,8));
	edges.push_back(node(4,1,5));
	edges.push_back(node(4,2,7));
    sort(edges.begin(),edges.end(),cmp);
    // for(auto x:edges){
    //     cout<<x.u<<" "<<x.v<<" "<<x.weight<<endl;
    // }
    vector<int> parent(5);
    vector<int> rank(5);
    for(int i=0;i<5;i++){
        parent[i]=i;
        rank[i]=0;
    }
    vector<pair<int,int>> mSet;
    int parent2[5]={-1,-1,-1,-1,-1};
    int res=0;
    // cout<<"a";
    for(int i=0;i<edges.size();i++){
        // cout<<i<<" ";
        int x=edges[i].u;
        int y=edges[i].v;
        // cout<<x<<" "<<y<<" ";
        if(find(x,parent,rank)!=find(y,parent,rank)){
            // cout<<"B";
            Union(x,y,parent,rank);
            mSet.push_back({x,y}); 
            parent2[y]=x;
            res+=edges[i].weight;
        }
        // cout<<i<<" ";
    }
    for(auto x:mSet){
        cout<<x.first<<" "<<x.second<<endl;
    }
    cout<<endl;
    for(int i=0;i<5;i++){
        cout<<i<<" "<<parent2[i]<<endl;
    }
    cout<<"\n"<<res;
    return 0;
}