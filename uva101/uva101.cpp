//2017.9.7
//written by robot
//本来是可以我自己独立ac的，
//过程出了问题，自己找不到，还是技能不够
//最近几天都挺累的
//这道题最近再复习一次
//runtime error的原因是bp和bh某处写错了...

#include<bits/stdc++.h>
using namespace std;
const int maxd=30;

vector<int> v[maxd];
int n,a,b;
int ap,ah,bp,bh;

void find_block(int a,int &p,int &h){
    for(int i=0;i<n;i++)
        for(int j=0;j<v[i].size();j++)
    if(v[i][j]==a){
        p=i;
        h=j;
       return;
    }
}

void moveonto(int a,int b){
    for(int i=ah+1;i<v[ap].size();i++){
    int zhi=v[ap][i];
    v[zhi].push_back(zhi);
   }
 //  v[ap].resize(ah+1);

   for(int i=bh+1;i<v[bp].size();i++){
        int zhi=v[bp][i];
        v[zhi].push_back(zhi);
    }
    v[bp].resize(bh+1);

    v[bp].push_back(a);
    v[ap].resize(ah);
}

void moveover(int a,int b){
    for(int i=ah+1;i<v[ap].size();i++){
    int zhi=v[ap][i];
    v[zhi].push_back(zhi);
   }
  // v[ap].resize(ah+1);

   v[bp].push_back(a);
    v[ap].resize(ah);

}

void pileonto(int a,int b){
    for(int i=bh+1;i<v[bp].size();i++){
        int zhi=v[bp][i];
        v[zhi].push_back(zhi);
    }
    v[bp].resize(bh+1);

   for(int i=ah;i<v[ap].size();i++)
    v[bp].push_back(v[ap][i]);
    v[ap].resize(ah);
}

void pileover(int a,int b){
   for(int i=ah;i<v[ap].size();i++)
    v[bp].push_back(v[ap][i]);

    v[ap].resize(ah);
}

void show()
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
    cin>>n;
    for(int i=0;i<n;i++)
     v[i].push_back(i);

    char s[10],s2[10];
    while(scanf("%s",s)==1&&s[0]!='q'){
        scanf("%d %s %d",&a,s2,&b);
     //   printf("%s %d %s %d\n",s,a,s2,b);
   find_block(a,ap,ah);
   find_block(b,bp,bh);

   if(ap==bp) continue;
    else if(s[0]=='m'&&s2[1]=='n') moveonto(a,b);
     else if(s[0]=='m'&&s2[1]=='v') moveover(a,b);
     else if(s[0]=='p'&&s2[1]=='n') pileonto(a,b);
     else if(s[0]=='p'&&s2[1]=='v') pileover(a,b);
   // show();
    }
    show();
    return 0;
}
