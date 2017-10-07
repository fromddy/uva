//2017.10.4
//written by robot
//book&&me
#include<bits/stdc++.h>
using namespace std;

typedef set<int> Set;
map<Set,int> IDcache;
vector<Set> setall;

#define all(x) x.begin(),x.end()
#define ins(x) inserter(x,x.begin())

int ID(Set x)
{
	if(IDcache.count(x)) return IDcache[x];
	setall.push_back(x);
	return IDcache[x]=setall.size()-1;
}

int  num,n;

int main()
{
    cin>>num;
    while(num--){
   cin>>n;
   string op;
   stack<int> s;
   for(int i=0;i<n;i++){
         cin>>op;
   if(op=="PUSH") s.push(ID(Set()));
   else if(op=="DUP") s.push(s.top());
   else {
   	Set x1=setall[s.top()];
   	s.pop();
   	Set x2=setall[s.top()];
   	s.pop();
   	Set x;
   	if(op=="UNION")
   	set_union(all(x1),all(x2),ins(x));
   		//set_union(x1.begin(),x2.end(),x2.begin(),x2.end(),inserter(x,x.begin()));
   	if(op=="INTERSECT")
     set_intersection(all(x1),all(x2),ins(x));
    if(op=="ADD") {x=x2;x.insert(ID(x1));}
    s.push(ID(x));
   }
  cout<<setall[s.top()].size()<<endl;
   }
  cout<<"***"<<endl;
 }
	return 0;
}
