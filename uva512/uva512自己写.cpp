#include<cstdio>
#include<cstring>
const int maxd=100;
const int BIG=10000;
int r,c,n,d[maxd][maxd],d2[maxd][maxd],ans[maxd][maxd];
int hang[maxd],lie[maxd];
int rr1,cc1;
int kase=0;
int rsum,csum;
int main()
{
    while(scanf("%d%d%d",&r,&c,&n)==3&&r)
    {

        rr1=r;
        cc1=c;
        for(int i=1; i<=r; i++) hang[i]=i;
        for(int j=1; j<=c; j++) lie[j]=j;
        for(int i=1; i<=r; i++)
            for(int j=1; j<=c; j++)
                d[i][j]=i*BIG+j;

        memset(ans,0,sizeof(ans));
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
            }

            else
            {
                int num;
                scanf("%d",&num);



                char cunchu[500];
                for(int i=1; i<=num; i++)
                    scanf("%d",&cunchu[i]);

                if(cmd[0]=='D'&&cmd[1]=='R')
                {
                    for(int i=1; i<=num; i++)
                        for(int j=1; j<=r; j++)
                            if(cunchu[i]==j) hang[j]=-1;
                }

                if(cmd[0]=='D'&&cmd[1]=='C')
                {
                    for(int i=1; i<=num; i++)
                        for(int j=1; j<=c; j++)
                            if(cunchu[i]==j)
                            {
                                lie[j]=-1;
                            }



                    if(cmd[0]=='I'&&cmd[1]=='R'){

                        for(int i=1; i<=num; i++){
                            for(int j=rr1; j>=cunchu[i]; j--)
                                hang[j+1]=hang[j];
                            rr1++;
                            hang[cunchu[i]]=0;

                        }


                    }
                    if(cmd[0]=='I'&&cmd[1]=='C')
                    {
                        for(int i=1; i<=num; i++)
                        {
                            for(int j=cc1; j>=cunchu[i]; j--)
                                lie[j+1]=lie[j];
                            cc1++;
                            hang[cunchu[i]]=0;
                        }
                    }
                }
            }


        }
            rsum=0,csum=0;
            int hang1[maxd],lie1[maxd];
            for(int i=1; i<=rr1; i++)
            {
                if(hang[i]>=0)
                {
                    rsum++;
                    hang1[rsum]=hang[i];
                }
            }
            for(int j=1; j<=cc1; j++)
            {
                if(lie[j]>=0)
                {
                    csum++;
                    lie1[csum]=lie[j];
                }
            }

            printf("\t%d %d\n",rr1,cc1);
            for(int i=1; i<=rsum; i++)
            {
                for(int j=1; j<=csum; j++)

                    if(hang1[i]>0&&lie1[i]>0) ans[d[hang1[i]][lie1[j]]/BIG][d[hang1[i]][lie1[j]]%BIG]=i*BIG+j;
            }

            for(int i=1; i<=rsum; i++)
                printf("%d ",hang[i]);
            printf("\n");
            kase++;
            if(kase>0) printf("\n");
            printf("Spreadsheet #%d\n",kase);

            int cnt;
            scanf("%d",&cnt);
            while(cnt--)
            {
                int r0,c0;
                scanf("%d%d",&r0,&c0);
                printf("Cell data in (%d,%d) ",r0,c0);
                if(ans[r0][c0]==0) printf("GONE\n");
                else printf("moved to (%d,%d)\n",ans[r0][c0]/BIG,ans[r0][c0]%BIG);
            }

        }



    return 0;
}
