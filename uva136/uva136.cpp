//2017.9.28 afternoon
//written by robot
//by my own

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long
vector<ll> a;
int main()
{
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(5);
    for(int i=0;;i++){
           // cout<<a[i]<<endl;
        if(i==1499){
            cout<<"The 1500'th ugly number is "<<a[i]<<"."<<endl;
            break;}
      if(count(a.begin(),a.end(),a[i]*2)==0) a.push_back(a[i]*2);
      if(count(a.begin(),a.end(),a[i]*3)==0)  a.push_back(a[i]*3);
      if(count(a.begin(),a.end(),a[i]*5)==0) a.push_back(a[i]*5);
      sort(a.begin(),a.end());


    }
    return 0;
}
