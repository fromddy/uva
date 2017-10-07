//2017.9.16 night
//左手手腕有些不舒服
//不能停下来 必须维持基本的代码量
//而且要赶超别人必须比别人有更快的速度
//看书 熟悉sstrem string set

#include<iostream>
#include<set>
#include<string>
#include<sstream>
using namespace std;
set<string> dict;
int main()
{
    string s,buf;
    while(cin>>s){
        for(int i=0;i<s.length();i++)
            if(isalpha(s[i])) s[i]=tolower(s[i]);
        else s[i]=' ';
        stringstream ss(s);
        while(ss>>buf) dict.insert(buf);
    }
    set<string>::iterator it;
    for(it=dict.begin();it!=dict.end();it++)
        cout<<*it<<endl;
    return 0;
}
