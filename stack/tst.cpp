#include<bits/stdc++.h>
using namespace std;
vector<int> prevsmaller(long long arr[],int n);
vector<int> nextsmaller(long long arr[],int n);
long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        vector<int> ps,nx;
        ps=prevsmaller(arr,n);
        nx=nextsmaller(arr,n);
        for(int i=0;i<n;i++){
            cout<<ps[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<n;i++){
            cout<<nx[i]<<" ";
        }
        return (long)187897943;
    }
    vector<int> prevsmaller(long long arr[],int n){
        stack<int> prev;
        vector<int> ps;
        ps.push_back(-1);
        prev.push(0);
        for(int i=1;i<n;i++){
            while(prev.empty()!=true/*khali ni h to pop kre*/ && arr[prev.top()]>=arr[i]){
                // cout<<i;
                prev.pop();
            }
            if(prev.empty()==true){
                ps.push_back(-1);
                prev.push(i);
                // cout<<i;
            }
            else{
                ps.push_back(prev.top());
                prev.push(i);
                // cout<<i;
            }
        }
        cout<<"end";
        return ps;
    }
    vector<int> nextsmaller(long long arr[],int n){
        stack<int> next;
        vector<int> nx;
        nx.push_back(n);
        next.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(next.empty()!=true && arr[next.top()]>=arr[i]){
                next.pop();
            }
            if(next.empty()){
                nx.push_back(n);
                next.push(i);
            }
            else{
                nx.push_back(next.top());
                next.push(i);
            }
        }
        reverse(nx.begin(),nx.end());
        return nx;
    }

int main(){
    long long arr[]={1,2,3,4,5};
    int n=5;
    getMaxArea(arr,n);
    return 0;
}