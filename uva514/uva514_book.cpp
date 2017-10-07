//2017.10.4 night
//written by robot
//book&&me
//PE了很多次

#include<iostream>
#include<stack>
#include<cstdio>
using namespace std;
const int maxn=1000+10;
int n,target[maxn];
int main()
{
    while(cin>>n&&n){
        while(cin>>target[1]){
            if(target[1]==0) break;
        for(int i=2; i<=n; i++)
                cin>>target[i];
            stack<int> s;
            int a=1,b=1,ok=1;
            while(b<=n)
            {
                if(a==target[b])
                {
                    a++;
                    b++;
                }
                else if(!s.empty()&&s.top()==target[b])
                {
                    s.pop();
                    b++;
                }
                else if(a<=n) s.push(a++);
                else
                {
                    ok=0;
                    break;
                }
            }
            printf("%s\n",ok?"Yes":"No");
        }
        cout<<endl;
    }
    return 0;
}
