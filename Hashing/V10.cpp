#include<bits/stdc++.h>
using namespace std;
// hashing with linear probing 
struct myhash{
    int *arr;
    int cap,size;
    myhash(int c){
        cap=c;
        arr=new int[c];
        size=0;
        for(int i=0;i<c;i++){
            arr[i]=-1;
        }
    }
    int hash(int key){
        return key%cap;
    }
    bool search(int key){
        int h=hash(key);
        int i=h;
        while(arr[i]!=-1){
            if(arr[i]==key) return true;
            i=(i+1)%cap;
            if(i==h) return false;
        }
    }
    bool insert(int key){
        if(size==cap) return false;
        int h=hash(key);
        int i=h;
        while(arr[i]!=-1 && arr[i]!=-2 && arr[i]!=key){
            i=(i+1)%cap;
        }
        if(arr[i]==key) return false;
        else{
            arr[i]=key;
            size++;
            return true;
        }
    }
    bool delet(int key){
        int h=hash(key);
        int i=h;
        while(arr[i]!=-1){
            if(arr[i]==key){
                arr[i]=-2;
                size--;
                return true;
            }
            i=(i+1)%cap;
            if(i==h) return false;
        }
        return false;
    }
};
int main(){
    
    return 0;
}