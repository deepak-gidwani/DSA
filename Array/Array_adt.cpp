#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Array{
    public:
    int *A;
    int size;
    int length;
    void display(){
        for(int i=0;i<length;i++){
            cout<<A[i]<<endl;
        }
    }
    void add(int ins,int pos){
        if(length==size || (pos<0 || pos>length)) {cout<<"Error in inserting\n";return;}
        for(int i=length;i>pos;i--){
            A[i]=A[i-1];
        }
        A[pos]=ins;
        length++; 
        return;
    }
    void del(int pos){ // worst tc = O(n)
        if(pos<0 || pos>length){cout<<"Error\n"; return ;}
        for(int i=pos;i<length-1;i++){
            A[i]=A[i+1];
        }
        length--;
    }

    /* // Method 1

    void InsSortEle(Array &a,int key){
        int l=0;int h= length-1,mid,inx;
        if(key> A[0] && key< A[ length-1]){
        while(1){
            mid=(l+h)/2;
            if(key> A[mid] && key< A[mid+1]){ inx=mid+1; break;}
            else if(key< A[mid] && key> A[mid-1]){inx=mid; break;}
            else if(key>mid){l=mid+1;}
            else h=mid-1;
        }
         add(a,key,inx);
        }
        else{cout<<"cant add this number\n"; return;}
    }

    */

    void InsSortEle(int key){
        if(length==size) return;
        int i=length-1;
        while(A[i]>key && i>=0){
            A[i+1]=A[i];
            i--;
        }
        A[i+1]=key;
        length++;
    }


    int Binser(int key){ // tc = O(logn), best case = O(1)  [log(n+1)]roof value --> total no of comparision
        int l=0,h= length-1;
        int mid;
        while(l<=h){
            mid=(l+h)/2;
            if(key< A[mid]) h=mid-1;
            else if(key> A[mid]) l=mid+1;
            else if( A[mid]==key) return mid;
        }
        return -1;
    }
    void oneside(){
        int i=0,j= length-1;
        while(i<j){
            while( A[i]<0) i++;
            while( A[j]>0) j--;
            if(i<j) swap( A[i], A[j]);
        }
    }
    Array * merg(Array &b){ //only for sorted array
        Array *c = new Array;  // heap m array bnaya or uska address bhej diya call by value se copy hota purra
        c->size=50;
        c->length=length+b.length;
        int i=0,j=0,k=0;
        // if(l1+l2>c.size) exit(0);
        while(i<length && j<b.length){
            if( A[i]<b.A[j]) c->A[k++]= A[i++];
            else c->A[k++]=b.A[j++];
        }
        for(;i<length;) c->A[k++]= A[i++];
        for(;j<b.length;) c->A[k++]=b.A[j++];
        
        return c;
    }
    void union_un(Array &b){
        Array c;
        c.length=length+b.length;
        int count=0;
        for(int i=0;i<length;i++){
            c.A[i]= A[i];
        }
        int k=length,l3=length;
        for(int i=0;i<b.length;i++){
            for(int j=0;j<length;j++){
                if(b.A[i]!=c.A[j]) count++;
            }
            if(count==length){
               c.A[k]=b.A[i];
               k++;
               l3++;
            //    count=0;
            }
            count=0;
        }
        c.length=l3;
        c.display();

    }
    void intersection(Array &b){
        Array c;
        int count=0,k=0,len=0;
        for(int i=0;i<length;i++){
            for(int j=0;j<b.length;j++){
                if( A[i]==b.A[j]) count++;
            }
            if(count>0){
                c.A[k++]= A[i];
                len++;
            }
            count=0;
        }
        c.length=len;
        c.display();

    }
};
int main(){
    // Array a={{1,2,3,4,5,6,17,8},50,8};
    // Array b={{9,10,11,22,13,14,15,16},50,8};
    Array *c=new Array;
    int ins,pos;
    // cout<<"Enter the size of array\n";
    // cin>> c->size;
    // cout<<"Enter the how much number u want to insert\n";
    // cin>> length;
    // if( length> size){cout<<"Length must be less than or equal to size";return 0;}

    //  A = new int[ size];
    // cout<<"Enter numbers\n";
    // for(int i=0;i< length;i++){
    //     cin>> A[i];
    // }
    // cout<<"Enter element and position to insert\n";
    // cin>>ins;
    //  InsSortEle(a,ins);
    //  add(a,ins,pos);
    //  del(a,0);
    //  oneside(a);
    // cout<< Binser(a,7);
    // Array *d = a.merg(b);
    // d->display(*d);
    //  intersection(a,8,b,8);
        // d->display();
    return 0;
}