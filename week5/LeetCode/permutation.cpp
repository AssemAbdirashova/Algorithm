#include<iostream>
#include<vector>
#include<unordered_map>
#define FOR(i,a,b) for(int i = a; i < b; i++)

using namespace std;
bool matches(unordered_map<char, int> s1map, unordered_map<char, int> s2map){
    // unordered_map<char, int>::const_iterator itr1;
    // unordered_map<char, int>::const_iterator itr2;
    // for(itr1 = s1map.begin(); itr2 = s2map.begin(); itr1 != s1map.end(); itr1++; itr2++){
    //     if(*itr1 != *itr2){
    //         return false;
    //     }
    // }
    for (const auto& item : s1map) {
		auto curr = s2map.find(item.first);
		if (curr == s2map.end() || curr->second != s1map[item.first])
			return false;
	}
    return true;
}
int main(){
    string s1;
    string s2;
    cin>> s1;
    cin>> s2;
    unordered_map<char, int> s1map;
    unordered_map<char, int>::iterator itr;
    if(s1.size()> s2.size()){
        int y = 34;
    }

    FOR(i, 0, s1.size()){
        s1map[s1[i]]++;
    }

    for (itr = s1map.begin(); itr != s1map.end(); itr++){
        cout << itr->first << "  " << itr->second << endl;
    } 
    bool ok = false;
    for(int i = 0; i < s2.size() - s1.size(); i++){
        unordered_map<char, int> s2map;
        for(int j = 0; j < s1.size(); j++){
            s2map[s2[i+j]]++;
        }
        if(matches(s1map, s2map)){
            ok = true;
        }
    }
    cout<< ok;
    return 0;
}

