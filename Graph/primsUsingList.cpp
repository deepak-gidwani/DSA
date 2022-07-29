#include<bits/stdc++.h>
using namespace std;
#define inf 9999999
void prim(vector<pair<int,int>> arr[],int v){
    int parent[v];
    bool mSet[v];
    int key[v];
    fill(mSet,mSet+v,0);
    fill(key,key+v,inf);
    key[0]=0;
    parent[0]=-1;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,0});
    int res=0;
    while(pq.empty()==false){ // optimised approach, now its tc=O((E+V)(logV))
    // for(int count=0;count<v;count++){  // ye mt use krna heap wale m
        // int mn=inf;  // tc=O(v) iski jgh heap use krlenge O(logv) m ho jaega
        // int u;
        // for(int i=0;i<v;i++){
        //     if(mSet[i]==0 && key[i]<mn){
        //         u=i;
        //         mn=key[i];
        //     }
        // }
        int u=pq.top().second;
        if(mSet[u]==false){
        cout<<pq.top().first<<" "<<pq.top().second<<endl;
        res+=pq.top().first;
        pq.pop();
        // cout<<u<<endl;
        }
        else{
            // cout<<pq.top().first<<" "<<pq.top().second<<endl;
            pq.pop();
            continue;
        };
        mSet[u]=1;
        for(int i=0;i<arr[u].size();i++){
            int v=arr[u][i].first;
            int weight = arr[u][i].second;
            if(mSet[v]==false && weight<key[v]){
                parent[v]=u;
                key[v]=weight;
                pq.push({weight,v});
            }
        }
    }
    for(int i=0;i<v;i++){
        cout<<i<<" "<<parent[i]<<endl;
        // cout<<mSet[i];
    }
    cout<<res<<" min weight of spanning tree";
 
}
void addEdge(vector<pair<int,int>> arr[],int u,int v,int w){
    arr[u].push_back({v,w});
    arr[v].push_back({u,w});
}
int main(){
    int v=4;
    vector<pair<int,int>> arr[v];
    addEdge(arr,0,1,5);
    addEdge(arr,0,2,8);
    addEdge(arr,1,2,1);
    addEdge(arr,1,3,15);
    addEdge(arr,3,2,20);
    prim(arr,v);
    return 0;
}