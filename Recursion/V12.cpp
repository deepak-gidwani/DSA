#include<iostream>
#include<algorithm>
using namespace std;

void fun(int rope,int a,int b,int c,int mn,int mx){
    if((rope%2==0 && (a%2!=0 && b%2!=0 && c%2!=0)) || (rope%2!=0 && (a%2==0 && b%2==0 && c%2==0)))
    cout<<"-1";
    else   
}
int main(){
    int rope,a,b,c;
    cin>>rope>>a>>b>>c;
    if(rope>=a || rope>=b || rope>=c)
    fun(rope,a,b,c);
    else cout<<"-1";
    return 0;
}