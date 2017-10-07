//2017.9.28 afternoon
//written by robot
//by book
//自己编写好之后看看书上的解法
//体会一下优先队列
#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;
typedef long long ll;
const int coeff[3]={2,3,5};


int main()
{
    priority_queue<ll,vector<ll>,greater<ll> >pq;
    set<ll> s;
    pq.push(1);
    s.insert(1);

    for(int i=1;;i++){
        ll x=pq.top();
        pq.pop();
       // cout<<x<<endl;
        if(i==1500) {
            cout<<"The 1500'th ugly number is "<<x<<"."<<endl;
            break;
        }
        for(int j=0;j<3;j++){
            ll x2=x*coeff[j];
            if(!s.count(x2)) {
                s.insert(x2);
                pq.push(x2);
            }
        }
    }


    return 0;
}
