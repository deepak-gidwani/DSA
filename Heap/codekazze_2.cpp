#include<bits/stdc++.h>
using namespace std;
int maximumCoins(int n, int m, vector<vector<int>> &a) {
    // Write your code here.
    int p1=0;
    
    for(int i=0;i<=n-2;i++){
        p1+=a[0][i];
    }
    for(int i=2;i<=m-1;i++){
        p1+=a[i][n-2];
    }
    for(int i=n-1;i>=1;i--){
        p1+=a[i][0];
    }
    for(int i=1;i<=n-1;i++){
        p1+=a[1][i];
    }
    p1+=a[0][n-1];
    p1+=a[n-1][m-1];
    return p1;
}


int main(){
    vector<vector<int>> v;
    vector<int> p1={7,2,3};
    vector<int> p2={5,2,7};
    vector<int> p3={2,4,4};
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    cout<<maximumCoins(3,3,v);
    return 0;
}