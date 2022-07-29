#include<bits/stdc++.h>
using namespace std;
int hpartition(int arr[],int l,int h){
    // swap(arr[l],arr[i]); agr koi or element k hisab se parition krna ho to
    int pivot=arr[l];
    int i=l-1,j=h+1;
    while(true){
        do{
            i++;
        }while(arr[i]<pivot);
        do{
            j--;
        }while(arr[j]>pivot);
        if(i>=j) return j;
        swap(arr[i],arr[j]);
    }
    return j;
}
void qsort(int arr[],int l,int h){
    if(l<h){
        int p=hpartition(arr,l,h);
        qsort(arr,l,p);
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