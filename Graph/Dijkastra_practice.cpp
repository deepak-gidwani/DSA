#include<bits/stdc++.h>
using namespace std;
#define  inf 9999999
void dijkastra(vector<pair<int,int>> arr[],int v,int s){
    int dis[v];
    for(int i=0;i<v;i++){
        dis[i]=inf;
    }
    dis[s]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,s});
    while(pq.empty()==0){
        int u=pq.top().second;
        pq.pop();
        for(auto it:arr[u]){
            int v=it.first;
            int wt=it.second;
            if( dis[v]>dis[u]+wt){
                dis[v]=dis[u]+wt;
                pq.push({dis[v],v});
            }
        }
    }
    for(int i=1;i<v;i++){
        cout<<i<<" - "<<dis[i]<<endl;
    }
}
int main(){
    int n=5,m=6,source=1;
	vector<pair<int,int> > g[n+1]; 	// assuming 1 based indexing of graph
	// Constructing the graph
	g[1].push_back({2,2});
	g[1].push_back({4,1});
	g[2].push_back({1,2});
	g[2].push_back({5,5});
	g[2].push_back({3,4});
	g[3].push_back({2,4});
	g[3].push_back({4,3});
	g[3].push_back({5,1});
	g[4].push_back({1,1});
	g[4].push_back({3,3});
	g[5].push_back({2,5});
	g[5].push_back({3,1});
    dijkastra(g,n+1,source);
    return 0;
}