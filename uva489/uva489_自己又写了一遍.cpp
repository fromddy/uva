//2017.9.6 night
//written by robot
//�Լ���д��һ�飬������һ��С���⣬���Գ����������������
//һ��Ҫע�����Ӧ�ó��ֵĵط����������Ž�����ʹ��

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n;
char s[105],s2[105];
int main()
{
    while(cin>>n&&n!=-1){
        scanf(" %s%s",s,s2);
       int len=strlen(s);
       int len2=strlen(s2);
       int flag=1,lose=0,win=0;
       int chance=7;
       int cnt=0;
       for(int i=0;i<len2;i++){
            for(int j=0;j<len;j++){
                if(s2[i]==s[j]) {s[j]=' ';
                cnt++;
                flag=0;
                }
            }
            if(flag==0) flag=1;
            else chance--;
            if(chance==0) lose=1;
            if(cnt==len) win=1;
            if(lose||win) break;

         // printf("%c %d\n",s2[i],chance);
       }
       printf("Round %d\n",n);
       if(win) printf("You win.\n");
       else if(lose) printf("You lose.\n");
       else printf("You chickened out.\n");

    }
    return 0;
}
