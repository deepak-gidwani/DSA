#include<bits/stdc++.h>
using namespace std;
// int stock(int arr[],int n){
//     int i=0,j=1,profit=0;
//     while(j<n){
//         if(arr[j]>arr[i]){
//             profit+=arr[j]-arr[i];
//             i++;
//             j++;
//         }
//         else{
//             i=j;
//             j++;
//         }
//     }
//     return profit;
// }
vector<vector<int> > stockBuySell(vector<int> A, int n){
        // code here
        vector<vector<int>> arr;
        vector<int> temp;
        int i=0,j=1,k=0;
        while(j<n){
            if(A[j]>A[i]){
                // arr[i].push_back(i);
                // arr[k].push_back(j);
                temp.push_back(i);
                temp.push_back(j);
                i++;
                j++;
                arr.push_back(temp);
                // k++;
                temp.clear();
            }
            else{
                i=j;
                j++;
            }
        }
     return arr;   
    }
int main(){
    vector<int> arr{2,4,8,5,1};
    vector<vector<int>> z=stockBuySell(arr,5);
    return 0;
}