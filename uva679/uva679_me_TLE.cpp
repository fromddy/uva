//2017.10.10 afternoon
//written by robot
//一定要注意<<的优先级是啥，记得加括号！
//TLE版本
#include<bits/stdc++.h>
using namespace std;
int s[1<<21];
int main()
{
	freopen("data.in","r",stdin);
	int num,d,i;
	while(cin>>num){
		if(num==-1) break;
		while(num--){
			cin>>d>>i;
			memset(s,0,sizeof(s));
			int k,n=(1<<d)-1;
			for(int c=0;c<i;c++)
            {
                k=1;
                while(1){
                s[k]=!s[k];
                if(s[k]) k=2*k;
                else k=2*k+1;
                if(k>n) break;
			   }

            }//for
      cout<<k/2<<endl;
     }//while(num--)
  }
   return 0;
}
