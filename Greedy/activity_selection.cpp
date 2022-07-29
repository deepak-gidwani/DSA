#include<bits/stdc++.h>
using namespace std;
bool mycmp(const pair<int,int> &p1,const pair<int,int> &p2){
    return p1.second<p2.second;
}
int maxactivity(vector<pair<int,int>> arr,int n){
    sort(arr.begin(),arr.end(),mycmp);
    int res=1,prev=arr[0].second;
    for(int i=1;i<n;i++){
        // int curr=arr[i].second;
        if(arr[i].first>=prev){
            res++;
            prev=arr[i].second;
        }
    }
    return res;

}
int main(){
    vector<pair<int,int>> arr;
    arr.push_back({12,25});
    arr.push_back({10,20});
    arr.push_back({20,30});
    cout<<maxactivity(arr,3);
    return 0;
}