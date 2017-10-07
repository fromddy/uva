//2017.9.16 night
//written by robot
//map vector string的综合应用

#include<iostream>
#include<string>
#include<cctype>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

string repo(const string s){
  string ans=s;
  for(int i=0;i<ans.size();i++)
    ans[i]=tolower(ans[i]);
  sort(ans.begin(),ans.end());
  return ans;
}
vector<string> words;
map<string,int> cnt;
int main()
{
    string s;
    while(cin>>s){
        if(s=="#") break;
        words.push_back(s);
        string r=repo(s);
      if(!cnt.count(r)) cnt[r]=0;
      cnt[r]++;
    }
    vector<string> ans;
    for(int i=0;i<words.size();i++)
        if(cnt[repo(words[i])]==1) ans.push_back(words[i]);
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<endl;
    return 0;
}
