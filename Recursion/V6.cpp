#include<iostream>
using namespace std;
void fun(int n){
    if(n==1)
    cout<<"1\n";
    else{
        fun(n-1);
        cout<<n<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    fun(n);
    return 0;
}