#include<iostream>
using namespace std;
int jor(int n,int k){
    if(n==1) return 0;
    else
    return (jor(n-1,k)+k)%n;
}
int main(){
    int n,k;
    cin>>n>>k;
    cout<<jor(n,k);
    return 0;
}