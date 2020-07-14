#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
vector<int> prefix_func(string s) {
    int n = s.size();
    vector<int> p(n);
    p[0] = 0;
    for (int i = 1; i < n; i++) {
        int j = p[i - 1];
        while (j > 0 && s[j] != s[i]) 
            j = p[j - 1];
        if (s[j] == s[i]) j++;
        p[i] = j;
    }

    return p;
}
bool pairCompare(const pair<string,int>&firstElem , const pair<string,int>&secondElem)
{
  return firstElem.second<secondElem.second;
}

vector<int> KMP(string s,string t)
{
    string s1=t+"#"+s;
    vector<int> pi = prefix_func(s1);
    vector<int> p2 ;
    for(int i=0;i<s1.size();i++)
        if(pi[i]==t.size()){
            p2.push_back(i - t.size() - t.size());
        }
    return p2;  
}

int main()
{
    string s,t;
    while(true){
        int n;
        cin>>n;
        if(n==0)
        return 0;
            
        vector<string> v ;
        for(int i=0;i<n;i++){
            string a;
            cin>>a;
            v.push_back(a);
        }
                
        string t;
        cin>>t;
        vector<pair<string,int> > pair;
        for(int i=0;i<v.size();i++)
        {
            vector<int> pi = KMP(t,v[i]);
            pair.push_back(make_pair(v[i],pi.size()));
        }
        sort(pair.begin(),pair.end(),pairCompare);
        int max=pair[pair.size()-1].second;

        cout<<pair[pair.size()-1].second<<"\n"<<pair[pair.size()-1].first<<"\n";
        
        
        for(int i=0;i<pair.size();i++)
        {
            if(pair[pair.size()-i-2].second==max)
            cout<<pair[pair.size()-i-2].first<<"\n";
        }  
    
    }  
}