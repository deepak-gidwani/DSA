#include<iostream>
using namespace std;
int sum(int n){
    if(n==0) return 0;
    else return n+sum(n-1);
}
/* tail recursive method
int sum(int n,int k){
    if(n==0) return k;
    else
    k+=n;
    return sum(n-1,k);
}
*/
int main(){
    int n;
    cin>>n;
    cout<<sum(n);
    // cout<<sum(n,0);
    return 0;
}