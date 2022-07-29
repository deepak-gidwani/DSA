#include<iostream>
using namespace std;
void TOH(int n,char A,char B,char C){
    if(n==1){
    cout<<"Move "<<n<<" disc from "<<A<<" to "<<C<<endl;
    return;
    }
    TOH(n-1,A,C,B);
    cout<<"Move "<<n<<" disc from "<<A<<" to "<<C<<endl;
    TOH(n-1,B,A,C);
}
int main(){
    int n;
    TOH(3,'A','B','C');
    return 0;
}