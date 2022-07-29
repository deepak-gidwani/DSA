#include<bits/stdc++.h>
using namespace std;
// tc=O(VE) and sc=O(V)
#define inf 99999999
struct node{
    int u,v,w;
    node(int u,int v,int weight){
        this->u=u;
        this->v=v;
        w=weight;
    }
};
int main(){
    int v,m;
    cin>>v>>m;
    vector<node> arr;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        node x(u,v,w);
        arr.push_back(x);
    }
    vector<int> dis(v,inf);
    dis[0]=0;
    for(int i=1;i<=v-1;i++){
        for(auto it:arr){
            int u=it.u;
            int v=it.v,w=it.w;
            if(dis[u]+w<dis[v]){
                dis[v]=dis[u]+w;
            }
        }
    }
    bool flag=1;
    for(auto it:arr){
        if(dis[it.u]+it.w<dis[it.v]){
            cout<<"Negative Cycle";
            flag=0;
            break;
        }
    }
    if(flag){
        for(int i=0;i<v;i++){
            cout<<i<<" "<<dis[i]<<endl;
        }
    }
    return 0;
}