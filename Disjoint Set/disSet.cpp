#include<bits/stdc++.h>
using namespace std;
int parent[5];
int rnk[5];
// amortised O(m(alfa(n))) tc h dono fnction ki, alfa(n)<=4 so O(1) for each m operation
void initialise(){
    for(int i=0;i<5;i++){
        parent[i]=i;
        rnk[i]=0;
    }
}
int find(int a){    // find with path compression
    if(a==parent[a]) return a;
    parent[a]=find(parent[a]);
    return parent[a];
}
void Union(int x,int y){   // union by rank , w/o path compresssion tc=O(mlogn) for m operation
    int x_rep = find(x);
    int y_rep = find(y);
    if(x_rep==y_rep) return;
    if(rnk[x_rep]<rnk[y_rep]) parent[y_rep]=x_rep;
    else if(rnk[x_rep]>rnk[y_rep]) parent[x_rep]=y_rep;
    else{
        parent[y_rep]=x_rep;
        rnk[x_rep]++;
    }
}

int main(){
    return 0;
}