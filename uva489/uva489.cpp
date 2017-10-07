//2017.9.5 forenoon
//witten by robot
//以前按照书上的意思写
//今天自己写还是不熟练得很哦

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int n;

	char s[100],s2[100];
	while(cin>>n&&n!=-1){
		printf("Round %d\n",n);
        scanf(" %s%s",s,s2);
        int len=strlen(s);
        int len2=strlen(s2);

        int win=0,lose=0,flag=1;

        int chance=7;

        int cnt=len;

        for(int i=0;i<len2;i++){

        	for(int j=0;j<len;j++)
        		if(s2[i]==s[j])
        			{s[j]=' ';
        			cnt--;
        			flag=0;}

        	if(flag==0) flag=1;
        	else chance--;

            if(cnt==0) win=1;
            if(chance==0) lose=1;
            if(win||lose) break;

        }

        if(win) printf("You win.\n");
        else if(lose) printf("You lose.\n");
        else printf("You chickened out.\n");
	}
	return 0;
}
