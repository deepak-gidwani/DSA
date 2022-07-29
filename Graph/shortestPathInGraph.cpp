#include<bits/stdc++.h>
using namespace std;    // we will use BFS


int * solve(vector<int> arr[],int s,int v){  //tc=O(V+E)
    queue<int> q;
    q.push(s);
    int *res = new int[v];
    for(int i=0;i<v;i++) res[i]=-1;   // extra line added becoz aab ye kisi bhi jgh se km krega no need of having 0 in graph
    res[s]=0;
    unordered_set<int> visited;
    visited.insert(s);
    while(q.empty()==false){
        s=q.front();
        q.pop();
        int j=0;
        while(j<arr[s].size()){
            if(visited.find(arr[s][j])==visited.end()){
                visited.insert(arr[s][j]);
                q.push(arr[s][j]);
                res[arr[s][j]]=res[s] + 1;  // arr[s]===parent, arr[s][x]===arr[s] k bache, so arr[s][x] ki
                                            // source se distance uske parent +1 k equal hogi
            } 
            j++;
        }
    }
    return res;
}
void addEdge(vector<int> *adj,int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);  // iske hta do directed bn jaega and this code work for both dir and undirected
}

int main(){  
    int v;
    v=6;   // isley kyu ki 0 wala matter khtm
    vector<int> adj[v];
    addEdge(adj,5,1);
    addEdge(adj,5,2);
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,2,4);
    // int *arr=solve(adj,0,v);
    int *arr=solve(adj,1,v);
    for(int i=0;i<v;i++) cout<<arr[i]<<" ";
    return 0;
}