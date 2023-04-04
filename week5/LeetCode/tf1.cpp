#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    int n;
    cin >> n;
    string str;
    getline(cin>>ws, str, '\n');
    string colors;
    getline(cin>>ws, colors, '\n');
    vector<string> check;
    string word = "";

    for (int i = 0; i< str.size(); i++){
        if (str[i] == ' '){
            check.push_back(word);
            word = "";
        }else{
            word = word + str[i];
        }
    }

    check.push_back(word);
    int result = 0;
    int k = 0;
    
    for(int i = 0; i< check.size(); i++){
        char prev = 'a';
        for(int j = 0; j < check[i].size(); j++){
            if(prev != colors[k+j]){
                prev = colors[k+j];
            }else{
                result++;
                break;
            }
        }
        k += check[i].size();
    }
    cout << result;
    return 0;
}