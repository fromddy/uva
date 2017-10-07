//2017.9.11 night
//wirtten by robot
//wa了一晚上，找不到错误的原因
//是 dr和dc没有分辨清楚
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

const int maxn=105;

char pic[maxn][maxn];
int m,n,vis[maxn][maxn];
void dfs(int r,int c,int id)
{
	if(r<0||r>=m||c<0||c>=n) return;
	if(vis[r][c]>0||pic[r][c]!='@') return;
	vis[r][c]=id;
	for(int dr=-1;dr<=1;dr++)
		for(int dc=-1;dc<=1;dc++)
			if(dr!=0||dc!=0) dfs(r+dr,c+dc,id);
}
/*
void dfs(int r,int c,int id){
 if(r<0||r>=m||c<0||c>=n) return;
 if(vis[r][c]>0||pic[r][c]!='@') return;
 vis[r][c]=id;
 for(int dr=-1;dr<=1;dr++)
    for(int dc=-1;dc<=1;dc++)
    if(dc!=0||dc!=0) dfs(r+dr,c+dc,id);
}
*/
int main()
{
    while(cin>>m>>n&&m&&n){

    memset(vis,0,sizeof(vis));
        for(int i=0;i<m;i++)
            scanf(" %s",pic[i]);
        int cnt=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            if(vis[i][j]==0&&pic[i][j]=='@')
             dfs(i,j,++cnt);

        cout<<cnt<<endl;
    }
    return 0;
}
