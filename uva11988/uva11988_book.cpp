//2017.10.6 afternoon
//written by robot
//linked list
//book
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

const int maxn=100000+5;

int last,cur,nextp[maxn];
char s[maxn];

int main()
{
    while(scanf("%s",s+1)==1){
        int n=strlen(s+1);
        last=cur=0;
        nextp[0]=0;
        for(int i=1;i<=n;i++){
            char ch=s[i];
            if(ch=='[') cur=0;
            else if(ch==']') cur=last;
            else {
                nextp[i]=nextp[cur];
                nextp[cur]=i;
                if(cur==last) last=i;
                cur=i;
            }

        }
        for(int i=nextp[0];i!=0;i=nextp[i])
            printf("%c",s[i]);
            printf("\n");
    }
    return 0;
}
