#include <bits/stdc++.h>
using namespace std;
vector<int> sub(int arr[], int n, long long s)
{
  long long sum = 0;
  vector<int> res;
  for (int i = 0, j = 0; i < n;)
  {
    if (sum < s)
    {
      sum += arr[i];
      i++;
    }
    else
    {
      while (sum > s)
      {
        sum -= arr[j];
        j++;
      }
      if (sum == s)
      {
        res.push_back(j + 1);
        res.push_back(i);
        return res;
      }
    }
  }
  res.push_back(-1);
  return res;
}
int main()
{
  int arr[]={135, 101, 170 ,125 ,79, 159 ,163 ,65 ,106, 146, 82 ,28 ,162, 92, 196, 143 ,28 ,37 ,192, 5, 103, 154 ,93 ,183 ,22, 117, 119, 96 ,48, 127, 172, 139, 70 ,113, 68 ,100 ,36, 95 ,104, 12 ,123 ,134};
  vector<int> z=sub(arr,42,468);
  for(auto x:z) cout<<x<<" ";
  return 0;
}