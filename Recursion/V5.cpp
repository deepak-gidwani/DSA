#include<iostream>
using namespace std;
void fun(int n){
    if(n==1)
    cout<<"1\n";
    else{
    cout<<n<<endl;
    fun(n-1);
    }
}
int main(){
    int n;
    cout<<"enter any positive number\n";
    cin>>n;
    fun(n);
    return 0;
}