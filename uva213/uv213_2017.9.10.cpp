//2017.9.10
//wtitten by robot
//����debug��һ����
//uva213 ԭ����Ϊ���˳������������ǡ���
//freopen()һ��Ҫ�ǵñ�ע����������

#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
using namespace std;
int code[8][1<<8];

int readchar(){
  while(1){
    int ch=getchar();
    if(ch!='\n') return ch;
  }
}

int readint(int num){
 int v=0;
 while(num--){
    v=v*2+readchar()-'0';
 }
 return v;
}

int main()
{
    //freopen("data.in","r",stdin);
    string line;
   while(getline(cin,line)){

        int cnt=0;
        for(int len=1;len<=8;len++){
            for(int i=0;i<(1<<len)-1;i++){
                if(cnt>=line.size()) break;
                code[len][i]=line[cnt];
                cnt++;
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
