//uva512 2017.9.2  
//written by robot
//不进行函数调用 模拟所有的操作

//细节很多 也没有什么好的办法

//之前一直wa的原因是cols数组开小了

#include<cstdio>
#include<cstring>
const int maxd=100;
const int BIG=10000;
int r,c,n,d[maxd][maxd],d2[maxd][maxd],ans[maxd][maxd];
int cols[maxd];
int kase=0;

int main()
{
	memset(d,0,sizeof(d));
    while(scanf("%d%d%d",&r,&c,&n)==3&&r)
    {
        for(int i=1; i<=r; i++)
            for(int j=1; j<=c; j++)
                d[i][j]=i*BIG+j;

        char cmd[10];
        while(n--)
        {
            scanf("%s",cmd);
            if(cmd[0]=='E')
            {
                int r1,c1,r2,c2;
                scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
                int t=d[r1][c1];
                d[r1][c1]=d[r2][c2];
                d[r2][c2]=t;
            }//E
            else
            {
                int a,x;
                scanf("%d",&a);
                memset(cols,0,sizeof(cols));
                for(int i=0; i<a; i++)
                {
                    scanf("%d",&x);
                    cols[x]=1;
                }

                if(cmd[0]=='D'&&cmd[1]=='R')
                {
                    memcpy(d2,d,sizeof(d));
                    int cnt2=0;
                    for(int i=1; i<=r; i++)
                    {
                        if(!cols[i])
                        {
                            cnt2++;
                            for(int j=1; j<=c; j++)
                                d[cnt2][j]=d2[i][j];
                        }
                    }
                    r=cnt2;
                }//DR

                else if(cmd[0]=='D'&&cmd[1]=='C')
                {
                    memcpy(d2,d,sizeof(d));
                    int cnt2=0;
                    for(int i=1; i<=c; i++)
                    {
                        if(!cols[i])
                        {
                            cnt2++;
                            for(int j=1; j<=r; j++)
                                d[j][cnt2]=d2[j][i];
                        }

                    }
                    c=cnt2;
                }//DC

                else if(cmd[0]=='I'&&cmd[1]=='R')
                {
                    memcpy(d2,d,sizeof(d));
                    int cnt2=0;
                    for(int i=1; i<=r; i++)
                    {
                        if(cols[i])
                        {
                            cnt2++;
                            for(int j=1; j<=c; j++)
                                d[cnt2][j]=0;
                        }
                        cnt2++;
                        for(int j=1; j<=c; j++)
                            d[cnt2][j]=d2[i][j];
                    }

                    r=cnt2;
                }//IR

                else if(cmd[0]=='I'&&cmd[1]=='C')
                {
                    memcpy(d2,d,sizeof(d));
                    int cnt2=0;
                    for(int i=1; i<=c; i++)
                    {
                        if(cols[i])
                        {
                            cnt2++;
                            for(int j=1; j<=r; j++)
                                d[j][cnt2]=0;
                        }
                        cnt2++;
                        for(int j=1; j<=r; j++)
                            d[j][cnt2]=d2[j][i];
                    }
                    c=cnt2;
                }//IC

            }//else

        }//while(n--)

        memset(ans,0,sizeof(ans));
        for(int i=1; i<=r; i++)
            for(int j=1; j<=c; j++)
            {
                ans[d[i][j]/BIG][d[i][j]%BIG]=i*BIG+j;
            }

        if(kase>0) printf("\n");
        printf("Spreadsheet #%d\n",++kase);
        int q ;
        scanf("%d",&q);
        while(q--)
        {
            int r1,c1;
            scanf("%d%d",&r1,&c1);
            printf("Cell data in (%d,%d) ",r1,c1);
            if(ans[r1][c1]==0) printf("GONE\n");
            else printf("moved to (%d,%d)\n",ans[r1][c1]/BIG,ans[r1][c1]%BIG);
        }
    }
  return 0;
}
