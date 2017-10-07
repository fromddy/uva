//2017.9.7
//witten by robot
//自己实现的函数
 
#include<bits/stdc++.h>
using namespace std;

const int maxn=30;
vector<int> v[maxn];
int n,a,b;
int ap,ah,bp,bh;

void find_block(int a,int &p,int &h){
	for(p=0;p<n;p++)
	for(h=0;h<v[p].size();h++)
	 if(v[p][h]==a) return;
}

void moveonto(int a,int b){
	for(int i=ah+1;i<v[ap].size();i++){
		int zhi=v[ap][i];
		v[zhi].push_back(zhi);
	}
//	v[ap].resize(ah+1);
	
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
	cin>>n;
    char s[10],s2[10];
    
    for(int i=0;i<n;i++)
     v[i].push_back(i);
    
    while(scanf("%s",s)!=EOF&&s[0]!='q'){
    	scanf("%d %s %d",&a,s2,&b);
    	
    	find_block(a,ap,ah);
    	find_block(b,bp,bh);
    
	if(ap==bp) continue;
	else if(s[0]=='m'&&s2[1]=='n') moveonto(a,b);
     else if(s[0]=='m'&&s2[1]=='v') moveover(a,b);
     else if(s[0]=='p'&&s2[1]=='n') pileonto(a,b);
     else if(s[0]=='p'&&s2[1]=='v') pileover(a,b);
    	
	}
	print();
	return 0;
}
