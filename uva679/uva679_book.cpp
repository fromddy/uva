//2017.10.6 night
//¶þ²æÊ÷
//book
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
  //freopen("data.in","r",stdin);
   int D,I,num;
while(cin>>num&&num!=-1){
    while(num--){
        cin>>D>>I;
        int k=1;
        for(int i=0;i<D-1;i++)
        if(I%2) {k=k*2;I=(I+1)/2;}
        else {k=k*2+1;I/=2;}
      printf("%d\n",k);
        }
  }
  return 0;
}

