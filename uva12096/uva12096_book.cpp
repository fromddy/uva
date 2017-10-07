//2017.10.1 afternoon
//written by robot
//本题极为重要

#include<iostream>
#include<cstdio>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
int T,n;
typedef set<int> Set;
map<Set,int> IDcache;
vector<Set> Setcache;


#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())



int ID(Set x){
    if(IDcache.count(x)) return IDcache[x];
    Setcache.push_back(x);
    return IDcache[x]=Setcache.size()-1;
}


int main()
{
    cin>>T;
    while(T--){
       stack<int> s;
       int n;
       cin>>n;
       while(n--){
        string op;
        cin>>op;
        if(op[0]=='P') s.push(ID(Set()));
        else if(op[0]=='D') s.push(s.top());
       else {
         Set x1=Setcache[s.top()] ;
         s.pop();
         Set x2=Setcache[s.top()];
         s.pop();
         Set x;
         if(op[0]=='U') set_union(ALL(x1),ALL(x2),INS(x));
         if(op[0]=='I') set_intersection(ALL(x1),ALL(x2),INS(x));
         if(op[0]=='A') {x=x2;x.insert(ID(x1));}
         s.push(ID(x));
        }
       cout<<Setcache[s.top()].size()<<endl;

       }
      cout<<"***"<<endl;


    }
    return 0;
}
