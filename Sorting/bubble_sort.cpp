#include <bits/stdc++.h>
using namespace std;
void bubble_sort(int arr[], int n)   // tc=O(n*n)
{
    for (int i = 0; i < n - 1; i++)
    {
    bool swapped=false;  // optimisation
        for (int j = 1; j < n - i; j++)
        {
            if (arr[j] < arr[j - 1])
            {
                swap(arr[j] , arr[j - 1]);
                swapped=true;
            }
        }
        if(swapped==false) break;
    }
}
int main()
{
    int arr[] = {4, 7, 2, 9, 1, 0};
    bubble_sort(arr, 6);
    for (auto x : arr)
        cout << x << " ";
    return 0;
}