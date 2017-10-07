//2017.10.6 morning
//written by robot
//me
#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
const int maxn=1000+10;
int n,target[maxn];
int main()
{
    while(cin>>n&&n){
      while(cin>>target[1]&&target[1]){
        for(int i=2;i<=n;i++)
            cin>>target[i];
            int a=1,b=1,ok=1;
            stack<int> s;
            while(b<=n){
                if(a==target[b]) {a++;b++;}
                else if(!s.empty()&&s.top()==target[b]){
                    s.pop();
                    b++;
                }
                else if(a<=n) s.push(a++);
                else {ok=0;break;}
            }
       printf("%s\n",ok?"Yes":"No");
        }
        cout<<endl;
    }
    return 0;
}
