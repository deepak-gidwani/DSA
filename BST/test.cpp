#include<bits/stdc++.h>
using namespace std;
int main(){
    // map<int,int> m;
    // m[0]=0;
    // m[1]=1;
    // m[2]=2;
    // auto it=m.end();
    // it--;
    // cout<<*(it).second();
    map<int, int> gquiz1;
 
    // insert elements in random order
    gquiz1.insert(pair<int, int>(1, 40));
    gquiz1.insert(pair<int, int>(2, 30));
    gquiz1.insert(pair<int, int>(3, 60));
    gquiz1.insert(pair<int, int>(4, 20));
    gquiz1.insert(pair<int, int>(5, 50));
    gquiz1.insert(pair<int, int>(6, 50));
    gquiz1.insert(pair<int, int>(7, 10));
 
    // printing map gquiz1
    map<int, int>::iterator itr;
    itr=gquiz1.begin(); 


          /* imp */
    // itr=itr+8;   // random access m kr sakte h isme nahi


    // cout << "\nThe map gquiz1 is : \n";
    // cout << "\tKEY\tELEMENT\n";
    // for (itr = gquiz1.begin(); itr != gquiz1.end(); ++itr) {
    //     cout << '\t' << (*itr).first << '\t' << itr->second
    //          << '\n';
    // }
    cout << endl;
    vector<int> arr={1,2,3};
    auto it=arr.end()-1;
    int i=0;
    for(;it!=arr.end();++it){
        cout<<i;
        i++;
    }
    return 0;
}