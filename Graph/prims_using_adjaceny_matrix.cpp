#include<bits/stdc++.h>
using namespace std;
#define inf 99999999
int primeMst(vector<int> graph[],int v){
    bool mSet[v]={false};
    int res=0;
    int key[v];
    fill(key,key+v,inf);
    key[0]=0;
    // for(auto x:mSet) cout<<x;
    for(int count=0;count<v;count++){
        int u=-1;
        for(int i=0;i<v;i++){
            int mn=inf;
            if(mSet[i]==false && (u==-1 || key[i]<mn)){
                mn=key[i];
                u=i;
            }
        }
        mSet[u]=1;
        res=res+key[u];
        for(int i=0;i<v;i++){
            if(graph[u][i]!=0 && mSet[i]==false){
                key[i]=min(key[i],graph[u][i]);
            }
        }
    }
    return res;
}
int main(){
    vector<int> graph[4]={
        {0,5,8,0},
        {5,0,10,15},
        {8,10,0,20},
        {0,15,20,0}
    };
    cout<<primeMst(graph,4);

    return 0;
}