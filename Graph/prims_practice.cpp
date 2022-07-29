#include<bits/stdc++.h>
using namespace std;
#define inf 99999999
void prims(vector<pair<int,int>> arr[],int n){
    int mset[n],parent[n],key[n];
    for(int i=0;i<n;i++){
        key[i]=inf;
        parent[i]=-1;
        mset[i]=0;
    }
    key[0]=0;
    parent[0]=-1;
    int count=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,0});
    while(pq.empty()==false){
        int u=pq.top().second;
        mset[u]=1;
        pq.pop();
        for(auto it:arr[u]){
            int v=it.first;
            int wt=it.second;
            if(mset[v]==0 && key[v]>wt){
                key[v]=wt;
                parent[v]=u;
                count+=wt;
                pq.push({wt,v});
            }
        }
    }
    for(int i=1;i<n;i++){
        cout<<i<<" "<<parent[i]<<endl;
    }
    cout<<count<<endl;
}
void addedge(vector<pair<int,int>> arr[],int u,int v,int w){
    arr[u].push_back({v,w});
    arr[v].push_back({u,w});
}
int main(){
    int v=5;
    // cin>>v;
    vector<pair<int,int>> adj[v];
    adj[0].push_back({1,2});
	adj[0].push_back({3,6});
	adj[1].push_back({0,2});
	adj[1].push_back({2,3});
	adj[1].push_back({3,8});
	adj[1].push_back({4,5});
	adj[2].push_back({1,3});
	adj[2].push_back({4,7});
	adj[3].push_back({0,6});
	adj[3].push_back({1,8});
	adj[4].push_back({1,5});
	adj[4].push_back({2,7});
    prims(adj,5);
    // addedge();
    return 0;
}


// #include<bits/stdc++.h>
// using namespace std;

// int main(){
// 	int N=5,m=6;
// 	vector<pair<int,int> > adj[N]; 
// 	adj[0].push_back({1,2});
// 	adj[0].push_back({3,6});
// 	adj[1].push_back({0,2});
// 	adj[1].push_back({2,3});
// 	adj[1].push_back({3,8});
// 	adj[1].push_back({4,5});
// 	adj[2].push_back({1,3});
// 	adj[2].push_back({4,7});
// 	adj[3].push_back({0,6});
// 	adj[3].push_back({1,8});
// 	adj[4].push_back({1,5});
// 	adj[4].push_back({2,7});



	
	
//     int parent[N]; 
      
//     int key[N]; 
      
//     bool mstSet[N]; 
  
//     for (int i = 0; i < N; i++) 
//         key[i] = INT_MAX, mstSet[i] = false; 
    
//     priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;

//     key[0] = 0; 
//     parent[0] = -1; 
//     pq.push({0, 0});

//     while(!pq.empty())
//     { 
//         int u = pq.top().second; 
//         pq.pop(); 
        
//         mstSet[u] = true; 
        
//         for (auto it : adj[u]) {
//             int v = it.first;
//             int weight = it.second;
//             if (mstSet[v] == false && weight < key[v]) {
//                 parent[v] = u;
// 	    key[v] = weight; 
//                 pq.push({key[v], v});    
//             }
//         }
            
//     } 
    
//     for (int i = 1; i < N; i++) 
//         cout << parent[i] << " - " << i <<" \n"; 
// 	return 0;
// }

