//2017.10.10 afternoon
//written by robot
//tree
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int D,I,n;
	while(cin>>n&&n!=-1){
      while(n--){
      	cin>>D>>I;
      	int k=1;
      	for(int i=0;i<D-1;i++)
      	{
      		if(I%2) {k=2*k;I=(I+1)/2;}
      		else {k=2*k+1;I=I/2;}
      	}
     cout<<k<<endl;
      }
	}
	return 0;
}