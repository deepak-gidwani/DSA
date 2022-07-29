#include<bits/stdc++.h>
using namespace std;
struct queue{
    int size,cap;
    int *arr;
    queue(int c){
        cap=c;
        arr=new int[cap];
        size=0;
    }
    void enque(int x){
        if(size==cap){cout<<"queue is full\n";return;}
        arr[size]=x;
        size++;
    }
    void deque(){                           // ye O(1) m kr sakte h circular array se(% use krke) video dekh lo
        if(size==0){cout<<"queue is empty";return;}
        for(int i=1;i<size;i++){
            arr[i-1]=arr[i];
        }
        size--;
    }
    int getfront(){
        if(size==0) return -1;
        else return arr[0];
    }
    int getrear(){
        if(size==0) return -1;
        else return arr[size-1];
    }
    bool isfull(){
        return (size==cap)?true:false;
    }
    bool isempty(){
        return (size==0)?true:false;
    }
    int siz(){
        return size-1;
    }
};
int main(){
    struct::queue x(5);
    x.enque(1);
    x.enque(2);
    x.enque(3);
    cout<<x.getfront()<<" "<<x.getrear()<<endl;
    x.deque();
    x.enque(4);
    // x.deque();
    cout<<x.getfront()<<" "<<x.getrear()<<endl;
    cout<<x.isempty()<<" "<<x.isfull();
    return 0;
}