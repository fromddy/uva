//2017.9.7
//written by robot
//书上的程序
#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
using namespace std;

const int maxn=30;
int n;
vector<int> v[maxn];

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

void print()
{
    for(int i=0;i<n;i++){
        printf("%d:",i);
        for(int j=0;j<v[i].size();j++)
            printf(" %d",v[i][j]);
            printf("\n");
    }
}
int main()
{
    int a,b;
    cin>>n;
    string s1,s2;
    for(int i=0;i<n;i++)
        v[i].push_back(i);
    while(cin>>s1>>a>>s2>>b){
        int pa,pb,ha,hb;
        find_block(a,pa,ha);
        find_block(b,pb,hb);
        if(pa==pb) continue;
        if(s2=="onto") clear_above(pb,hb);
        if(s1=="move") clear_above(pa,ha);
        pile_onto(pa,ha,pb);
       // print();
    }

    print();
    return 0;
}
