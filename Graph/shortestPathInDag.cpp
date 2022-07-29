#include<bits/stdc++.h>
using namespace std;



struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
 
        if (hash1 != hash2) {
            return hash1 ^ hash2;             
        }
         
        // If hash1 == hash2, their XOR is zero.
          return hash1;
    }
};
void topSorting(vector<int> arr[],int v,vector<int> &ans){
    vector<int> indegree(v,0);
    queue<int> q;
    for(int i=0;i<v;i++){
        for(auto x:arr[i]){
            indegree[x]++;
        }
    }
    for(int i=0;i<v;i++){
        if(indegree[i]==0) q.push(i);
    }
    // cout<<q.size();
    while(q.empty()==false){
    // cout<<"d";
        int temp=q.front();
        ans.push_back(temp);
        q.pop();
        for(int i=0;i<arr[temp].size();i++){
            indegree[arr[temp][i]]--;
            if(indegree[arr[temp][i]]==0) q.push(arr[temp][i]);
        }
    }
    // for(auto x:ans) cout<<x<<" ";
}
void shortestPath(vector<int> arr[],int v,int s,unordered_map<pair<int,int>,int,hash_pair> &weight){
    int minDis[v];
    for(int i=0;i<v;i++){
        minDis[i]=INT_MAX/2;  // kyu ki s agr 0 ni h tb bhi km kre becoz INT_MAX + weight give -ve in below
    }
    minDis[s]=0;
    vector<int> toposort;
    topSorting(arr,v,toposort);
    // for(auto x:minDis) cout<<x<<" ";
    // cout<<endl;
    for(int i=0;i<v;i++){
    // cout<<"d";
        int p=toposort[i];
        // cout<<p;
        for(int j=0;j<arr[p].size();j++){
            int v=arr[p][j];
            if(minDis[v] > minDis[p] + weight[{p,v}] ){
                // cout<<i<<" "<<minDis[v]<<" "<<minDis[p]<<" "<<weight[{p,v}]<<" "<<endl;
                minDis[v] = minDis[p] + weight[{p,v}];
            }
        }
    }
    for(auto x:minDis){
        cout<<x<<" ";
    }
}
void addEdge(vector<int> arr[],int u,int v){
    arr[u].push_back(v);
    // arr[v].push_back(u);
}
int main(){
    vector<int> arr[6];
    unordered_map<pair<int,int>,int,hash_pair> weight;
    weight.insert({{0,1},2});
    weight.insert({{0,4},1});
    weight.insert({{1,2},3});
    weight.insert({{4,2},2});
    weight.insert({{4,5},4});
    weight.insert({{2,3},6});
    weight.insert({{5,3},1});
    addEdge(arr,0,1);
    addEdge(arr,0,4);
    addEdge(arr,1,2);
    addEdge(arr,4,2);
    addEdge(arr,4,5);
    addEdge(arr,2,3);
    addEdge(arr,5,3);
    shortestPath(arr,6,1,weight);
    return 0;
}