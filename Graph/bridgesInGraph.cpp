#include<bits/stdc++.h>
using namespace std;
//tc=O(V+E), AS=O(E)
void dfs(int node,int parent,vector<int> &vis,vector<int> &tin,vector<int> &low,int timer,vector<int> arr[]){
    vis[node]=1;
    tin[node] = low[node] = timer++;
    for(auto it:arr[node]){
        if(it==parent) continue;
        if(vis[it]==0){
            dfs(it,node,vis,tin,low,timer,arr);
            low[node]=min(low[node],low[it]);
            if(low[it]>tin[node]){
                cout<<node<<" "<<it<<endl;
            }
        }
        else{
            low[node]=min(low[node],tin[it]);
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> arr[n];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    int timer=0;
    vector<int> low(n,-1),tin(n,-1),vis(n,0);
    for(int i=0;i<n;i++){
        if(vis[i]==0){
            dfs(i,-1,vis,tin,low,timer,arr);
        }
    }

    return 0;
}