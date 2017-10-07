//uva 512  2017.9.3 morning
//written by robot

//自己编写的，记录所有操作

//以后有机会再写一写吧

#include<cstdio>
#include<cstring>
int r,c,n;
int kase=0;
struct Command
{ char c[5];
    int r1,c1,r2,c2;
    int a;
    int x[50];

}cmd[100];

int simulate(int &r0,int &c0)
{
    for(int i=0;i<n;i++){
        if(cmd[i].c[0]=='E') {
            if(cmd[i].r1==r0&&cmd[i].c1==c0){
                r0=cmd[i].r2;c0=cmd[i].c2;
            }
            else if(cmd[i].r2==r0&&cmd[i].c2==c0){
                r0=cmd[i].r1;c0=cmd[i].c1;
            }
        }
        else {
            int dr=0,dc=0;
            for(int j=0;j<cmd[i].a;j++){
                int x=cmd[i].x[j];

            if(cmd[i].c[0]=='D') {
                if(cmd[i].c[1]=='R'&&x<r0) dr--;
                if(cmd[i].c[1]=='R'&&x==r0) return 0;
                if(cmd[i].c[1]=='C'&&x<c0) dc--;
                if(cmd[i].c[1]=='C'&&x==c0) return 0;
            }
            else {
                if(cmd[i].c[1]=='R'&&x<=r0) dr++;
                if(cmd[i].c[1]=='C'&&x<=c0) dc++;
            }
            }
            r0+=dr;c0+=dc;
        }

    }
    return 1;


}




int main()
{
    while(scanf("%d%d%d",&r,&c,&n)==3&&r){
        for(int i=0;i<n;i++){
            scanf("%s",cmd[i].c);
            if(cmd[i].c[0]=='E'){
                scanf("%d%d%d%d",&cmd[i].r1,&cmd[i].c1,&cmd[i].r2,&cmd[i].c2);

            }
            else {
                scanf("%d",&cmd[i].a);
                for(int j=0;j<cmd[i].a;j++)
                    scanf("%d",&cmd[i].x[j]);
            }
        }//input cmd

        if(kase>0) printf("\n");
        printf("Spreadsheet #%d\n",++kase);
        int q;
        scanf("%d",&q);
        while(q--){
                int r0,c0;
        scanf("%d%d",&r0,&c0);

        printf("Cell data in (%d,%d) ",r0,c0);
        if(!simulate(r0,c0)) printf("GONE\n");
        else printf("moved to (%d,%d)\n",r0,c0);
        }
    }
    return 0;
}
