//2017.9.4
//written by robot
//结合书上的内容和我自己的想法写的

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
int code[8][1<<8];
int readchar()
{
    while(1){
        int ch=getchar();
        if(ch!='\n') return ch;
    }
}

int readint(int num)
{
    int v=0;
    while(num--){
        v=2*v+readchar()-'0';
    }
    return v;
}

int main()
{
    string line;
    while(getline(cin,line)){
            memset(code,0,sizeof(code));

    int num=0;

        for(int len=1;len<=8;len++){
            for(int i=0;i<(1<<len)-1;i++){
                    if(num>=line.size()) break;
                code[len][i]=line[num];
            //    printf("code[%d][%d]=%c\n",len,i,code[len][i]);
                num++;
            }
        }
        while(1){
            int len=readint(3);
            if(len==0) break;
            while(1){
                int v=readint(len);
                if(v==(1<<len)-1) break;
                putchar(code[len][v]);
            }
        }
        getchar();
        cout<<endl;
    }
    return 0;
}
