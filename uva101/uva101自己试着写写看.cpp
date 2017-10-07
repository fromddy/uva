//2017.9.7
//written by robot
//现在的情况是按照书上的代码写ac了
//但是自己写的样例过了但是rruntime error了
//所以准备自己再写写看(应该是会借鉴书上的代码吧)

#include<bits/stdc++.h>
using namespace std;

const int maxn=30;
vector<int> v[maxn];
int n;
int a,b;
int pa,pb,ha,hb;

void find_block(int a,int &p,int &h){
  for(p=0;p<n;p++)
    for(h=0;h<v[p].size();h++)
    if(v[p][h]==a) return;
}

void clear_above(int p,int h){
   for(int i=h+1;i<v[p].size();i++){
    int zhi=v[p][i];
    v[zhi].push_back(zhi);
   }
   v[p].resize(h+1);
}

void pile_onto(int p,int h,int p2){
  for(int i=h;i<v[p].size();i++)
    v[p2].push_back(v[p][i]);
   v[p].resize(h);
}

void show(){
 for(int i=0;i<n;i++){
    printf("%d:",i);
    for(int j=0;j<v[i].size();j++)
        printf(" %d",v[i][j]);
    printf("\n");
 }
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        v[i].push_back(i);
        string s,s2;
    while(cin>>s>>a>>s2>>b){
       find_block(a,pa,ha);
       find_block(b,pb,hb);
       if(pb==pa) continue;
       if(s=="move") clear_above(pa,ha);
       if(s2=="onto") clear_above(pb,hb);
       pile_onto(pa,ha,pb);
    // show();
    }
    show();
    return 0;
}
