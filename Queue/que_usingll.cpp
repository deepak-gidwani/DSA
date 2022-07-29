#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *next;
    node(int x){
        data=x;
        next=0;
    }
};
struct que{
    node *front=0,*rear=0;
    int size=0;
    void enque(int y){
        if(front==0){
            front=new node(y);
            rear=front;
            size=1;
            return;
        }
        node *temp=new node(y);
        rear->next=temp;
        rear=temp;
        size++;
    }
    void deque(){
        if(front==0) return;
        node *temp=front;
        front=front->next;
        if(front==0) rear=0;    // agr ye na kre to memory leak hogi as rear point kr rha hoga jidhar udhar wala node del ho chuka hoga
        delete temp;
        // cout<<temp->data<<endl;
        size--;
    }
    int getfront(){
        if(front==0) return -1;
        return front->data;
    }
    int getrear(){
        if(rear==0) return -1;
        // cout<<rear->data;
        return rear->data;
    }
    int sze(){
        return size;
    }

};

int main(){
    que x;
    // cout<<x.sze()<<endl;
    x.enque(1);
    // cout<<x.sze()<<endl;
    x.enque(2);
    x.enque(3);
    cout<<x.getfront()<<" "<<x.getrear()<<endl;
    x.deque();
    x.enque(4);
    // x.deque();
    x.deque();
    x.deque();
    x.deque();
    cout<<x.getfront()<<" "<<x.getrear()<<endl;
    cout<<x.sze();
    return 0;
}