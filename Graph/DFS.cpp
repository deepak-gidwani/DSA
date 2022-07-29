#include<bits/stdc++.h>
using namespace std;
void DFSrec(vector<int> arr[],int s,unordered_set<int> &visited){  // recursive call ki jgh stack bhi use kr sakte h
    cout<<s<<" ";
    for(int i=0;i<arr[s].size();i++){
        if(visited.find(arr[s][i])==visited.end()){
            visited.insert(arr[s][i]);
            DFSrec(arr,arr[s][i],visited);
        }
    }
}
void DFS(vector<int> arr[],int v,int s){   // tc and SC = O(V+E)
    unordered_set<int> visited;
    for(int i=0;i<v;i++){
        if(visited.find(i)==visited.end()){
            visited.insert(i);
            DFSrec(arr,i,visited);
        }
    }
}
void addEdge(vector<int> arr[],int u,int v){
    arr[u].push_back(v);
    arr[v].push_back(u);
}
int main(){
    int v=6;
    vector<int> arr[v];
    addEdge(arr,0,1);
    addEdge(arr,0,2);
    addEdge(arr,1,3);
    addEdge(arr,1,4);
    addEdge(arr,2,3);
    addEdge(arr,4,5);
    DFS(arr,v,0);
    return 0;
}