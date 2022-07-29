#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int> *adj,int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void printGraph(vector<int> arr[],int s){
    for(int i=0;i<s;i++){
        for(auto x:arr[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}
void BFS(vector<int> arr[],int v,int s){  // v = total vertex
                                        // call when source is given and graph is not disconnected
                                        // its tc = theta(2*E)
    queue<int> q;
    unordered_set<int> chk;  // bool visited array bhi use kr sakte the 
    chk.insert(s);
    q.push(s);
    // cout<<q.size();
    while(q.empty()!=true){
        cout<<q.front()<<" ";
        s=q.front();
        q.pop();
        int j=0;
        // cout<<"a";
        // cout<<arr[s].size();
        while(j<arr[s].size()){
            if(chk.find(arr[s][j])==chk.end()){
            q.push(arr[s][j]);
            chk.insert(arr[s][j]);  
            }
            j++;
        }
        // cout<<q.size();
    }
}
void BFS2(vector<int> arr[],int v,int s,unordered_set<int> &chk){  // v = total vertex
                                        // call when source is not given and graph is disconnected
                                        // its tc = O(E+V)
    queue<int> q;
    // chk.insert(s);
    q.push(s);
    // cout<<q.size();
    while(q.empty()!=true){
        cout<<q.front()<<" ";
        s=q.front();
        q.pop();
        int j=0;
        // cout<<"a";
        // cout<<arr[s].size();
        while(j<arr[s].size()){
            if(chk.find(arr[s][j])==chk.end()){
            q.push(arr[s][j]);
            chk.insert(arr[s][j]);
            }
            j++;
        }
        // cout<<q.size();
    }
}
void BFSdis(vector<int> arr[],int v){
    unordered_set<int> chk;
    for(int i=0;i<v;i++){
        if(chk.find(i)==chk.end()){
            chk.insert(i);  // 0 hona chaiye
            BFS2(arr,v,i,chk);
        }
    }
}
int main(){
    int v;
    v=8;
    vector<int> adj[v];
    addEdge(adj,7,1);
    addEdge(adj,7,2);
    addEdge(adj,1,3);
    addEdge(adj,2,3);
    // addEdge(adj,4,5);
    // addEdge(adj,4,6);
    // addEdge(adj,5,6);
    // cout<<adj[0][0];
    // BFSdis(adj,v);
    // BFS(adj,v,7); // hum kisi bhi number se kr sakte h jaruri ni h 0 hona chaiye lekin iske liye 
    // adj vector bda bnega max value of vertex tk bnega
    // printGraph(adj,v);
    return 0;
}