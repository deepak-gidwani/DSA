#include<bits/stdc++.h>
using namespace std;
int lpartition(int arr[],int l,int h){
    // swap(arr[inx],arr[h]); agr koi or element k hisab se parition krna ho to
    int pivot=arr[h];
    int i=l-1;
    for(int j=l;j<=h-1;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[h]);
    return i+1; // return index of pivot
}
void qsort(int arr[],int l,int h){
    if(l<h){
        int p=lpartition(arr,l,h);
        qsort(arr,l,p-1);
        qsort(arr,p+1,h);
    }
}
int main(){
    int arr[]={8,4,7,9,3,10,5};
    qsort(arr,0,6);
    for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}