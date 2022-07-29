#include<bits/stdc++.h>
using namespace std;
class heap{
    public:
    int *arr;
    int size;
    int capacity;
    heap(int c){
        capacity=c;
        arr=new int[c];
        size=0;
    }
    int left(int i){return (2*i)+1;}
    int right(int i){return (2*i)+2;}
    int parent(int i){return (i-1)/2;}
    void insert(int x){  // tc=O(logn)
        if(size==capacity) return;
        size++;
        arr[size-1]=x;
        for(int i=size-1;i!=0 && arr[parent(i)]>arr[i];i=parent(i)){
            swap(arr[i],arr[parent(i)]);
        }
    }
    void heapify(int i){ // O(logn), use when subtrees are heap only root is disturbed
        while((arr[i]>arr[left(i)] && left(i)<size) || (arr[i]>arr[right(i)] && right(i)<size))
        {
            int index;
            if(arr[left(i)]<arr[right(i)]){index=left(i);}
            else{index=right(i);}
            swap(arr[i],arr[index]); 
            i=index;
        }
    }
    void maxheapify(int i){     // recursive sol for maxheapify
        int largest=i,left=2*i+1,right=2*i+2;
        if(arr[left]>arr[largest] && left<size) largest=left;
        if(arr[right]>arr[largest] && right<size) largest=right;
        if(largest!=i){
            swap(arr[i],arr[largest]);
            maxheapify(largest);
        }
    }
    void extractmin(){
        if(size==0) return;
        if(size==1){
            size--;
            return;
        }
        swap(arr[0],arr[size-1]);
        size--;
        heapify(0);
    }
    void decreasekey(int i,int x){
        if(size==0) return;
        if(size==1){
            arr[0]=x;
            return;
        }
        arr[i]=x;
        for(int j=i;arr[j]<arr[parent(j)] && j!=0;j=parent(j)){
            swap(arr[j],arr[parent(j)]);
        }
    }
    void delte(int i){
    // swap(harr[i],harr[heap_size-1]);   // ye glt h
    // heap_size--;
    // MinHeapify(i);
        if(size<=0||size<=i)
            return;
        decreasekey(i,INT_MIN);
        extractmin();
    }
    void buildheap(){   // vo array jo heap nahi h usse heap bnaega
                        // iski tc=O(n*logn) Lg rhi hogi lekin hai O(n) math kroge to dikhegi
        for(int i=(size-2)/2;i>=0;i--) //  hr chota chota subtree ko heap krte ja rhe h, smj ni aa rha to video dekho
                                       // i=parent of last node
        heapify(i);
    }
    void buildmaxheap(){
        for(int i=(size-2)/2;i>=0;i--)
        maxheapify(i);
    }
    void heapsort(){
        buildmaxheap();
        for(int i=size-1;i>=1;i--){
            swap(arr[0],arr[size-1]);
            size--;
            maxheapify(0);
        }
    }
};
int main(){
    heap m(10); 
    m.insert(40);
    m.insert(20);
    m.insert(30);
    m.insert(35);
    m.insert(25);
    m.insert(80);
    m.insert(32);
    m.insert(100);
    m.insert(70);
    m.insert(60);
    // m.arr[3]=120;

    for(int i=0;i<10;i++) cout<<m.arr[i]<<" ";
    cout<<endl;
    // m.heapify(2);
    // m.decreasekey(3,11);
    // m.delte(2);
    m.heapsort();
    for(int i=0;i<10;i++) cout<<m.arr[i]<<" ";
    return 0;
}