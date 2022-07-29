#include<bits/stdc++.h>
using namespace std;
#define inf 9999999
void shortestpath(vector<pair<int,int>> arr[],int v,int s){ //TC=O((V+E)logV)
    int dis[v+1];
    bool mSet[v+1];
    fill(mSet,mSet+v,0);
    fill(dis,dis+v,inf);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    dis[s]=0;
    pq.push({0,s});
    while(pq.empty()==false){
        int u = pq.top().second;
        // int weight = pq.top().first;
        mSet[u]=1;
        pq.pop();
        for(int i=0;i<arr[u].size();i++){
            // cout<<arr[u].size()<<endl;
            int v = arr[u][i].first;
            int weight = arr[u][i].second;
            if(mSet[v]==false && dis[v]>dis[u]+weight){
                dis[v]=dis[u]+weight;
                // cout<<v<<" "<<dis[v]<<" "<<u<<" "<<i<<" "<<endl;
                pq.push({weight,v});
            }
        }
    }
    for(auto x:dis) cout<<x<<" ";
    
}
int main(){
    int v=5;
    vector<pair<int,int>> arr[v+1];   // is baar indexing 1 se le rhe h
    arr[1].push_back(make_pair(2,2));
    arr[2].push_back(make_pair(1,2));
    arr[1].push_back({4,1});
    arr[4].push_back({1,1});
    arr[2].push_back({3,4});
    arr[3].push_back({2,4}); 
    arr[2].push_back({5,5});
    arr[5].push_back({2,5});
    arr[4].push_back({3,3});
    arr[3].push_back({4,3});
    arr[3].push_back({5,1});
    arr[5].push_back({3,1});
    // for(auto x:arr){
    //     for(auto y:x){
    //         cout<<y.first<<" ";
    //     }
    //     cout<<endl;
    // }
    shortestpath(arr,5,2);
    return 0;
}