#include<iostream>
using namespace std;
// AS AND TC is theta(d), d=no. of digits
int sum(int num){
    if(num==0)
    return 0;
    int r=num%10;
    num=num/10;
    return (r+sum(num));
}
int main(){
    int num;
    cin>>num;
    cout<<sum(num);
    return 0;
}