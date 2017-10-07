//2017.9.17 morning
//written by robot
//上午时候趁热自己编写了一下
//map vector string

#include<bits/stdc++.h>
using namespace std;
vector<string> words;
map<string,int> cnt;
string repo(const string s){
  string ans=s;
  for(int i=0;i<ans.size();i++)
    ans[i]=tolower(ans[i]);
  sort(ans.begin(),ans.end());
  return ans;
}

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
    if(cnt[repo(words[i])]==1)
        ans.push_back(words[i]);
    sort(ans.begin(),ans.end());
  for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<endl;
  return 0;
}
