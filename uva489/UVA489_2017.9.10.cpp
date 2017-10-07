//2017.9.10 night
//written by robot
//星期日晚上，编写一些本周写过的程序
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main()
{
    int n;
    string s,s2;
    while(cin>>n&&n!=-1){
        cin>>s>>s2;

        int cnt=0,flag=1,chance=7;
        int win=0,lose=0;
    for(int i=0;i<s2.length();i++){
        for(int j=0;j<s.length();j++){
            if(s2[i]==s[j]) {
                s[j]=' ';
                 cnt++;
                 flag=0;
           }//if
        }
        if(flag==0) flag=1;
         else chance--;
         if(chance==0) lose=1;
         if(cnt==s.length()) win=1;
         if(lose||win) break;
    }
    printf("Round %d\n",n);
    if(win) printf("You win.\n");
    else if(lose) printf("You lose.\n");
    else printf("You chickened out.\n");
  }//while
 return 0;
}
