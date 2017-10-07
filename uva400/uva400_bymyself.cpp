//2017.10.4 night
//written by robot
//me
//编写一个行列阵的时候用一般的思路去写
//要不然会有很多问题的
//一般的思路 就是 for（r:0-->rows) for(c:0-->cols)
#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,m;
string file[110];
int main()
{
   while(cin>>n){
    for(int i=0;i<60;i++)
        cout<<"-";
    cout<<endl;
    m=0;
    for(int i=0;i<n;i++) {
        cin>>file[i];
        m=max(m,(int)file[i].length());
   }
   sort(file,file+n);
   int cols=(60-m)/(m+2)+1,rows=(n-1)/cols+1;
   for(int r=0;r<rows;r++){
      for(int c=0;c<cols;c++){
        int idx=rows*c+r;
        if(idx<n) {
            cout<<file[idx];
            for(int i=0;i<m-file[idx].length();i++)
                cout<<" ";
        }
        if(c!=cols-1) cout<<"  ";
      }
    cout<<endl;
   }
 }
   return 0;
}
