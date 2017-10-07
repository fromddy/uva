//2017.10.6 night
//written by robot
//book
//³¬Ê±°æ±¾

#include<cstdio>
#include<cstring>
const int maxd=20;
int s[1<<maxd];
int main()
{
   //freopen("data.in","r",stdin);
	int D,I,n;

	while(~scanf("%d",&n)){
        if(n==-1) break;

	    while(n--){
	        scanf("%d %d",&D,&I);

      memset(s,0,sizeof(s));
      int k,n=(1<<D)-1;
      for(int i=0;i<I;i++){
      	k=1;
      	while(1){
      		s[k]=!s[k];
      		k=s[k]?k*2:k*2+1;
      		if(k>n) break;
      	}
      }
 printf("%d\n",k/2);
	}
	}
	return 0;
}
