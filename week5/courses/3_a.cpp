#include <iostream>
#include <cmath>
#include <sstream> 
#include <stack>
#include <vector>
using namespace std;

int main() {
    string str;
    stack<int> st;
    vector<char> out;
    
    getline(cin, str);
    char word;
    for (int i = 0; i< str.size(); i++){
        if (str[i] == ' '){
            out.push_back(word);
            word = ' ';
        }else{
            word = str[i];
        }
    }
    out.push_back(str[str.size()-1]);
    int last = 0;
	for(int i = 0; i < out.size(); i++) {
        if(out[i] != '+' && out[i] != '-' && out[i] != '*'){
            st.push(int(out[i]) - 48);
        }
        if(out[i] == '+'){
            if(!st.empty()){
                last = st.top();
                st.pop();
                last = last + st.top();
                st.pop();
                st.push(last);
            }
        }else if(out[i] == '-'){
            if(!st.empty()){
                last = st.top();
                st.pop();
                last = st.top() - last;
                st.pop();
                st.push(last);
            }
        }else if(out[i] == '*'){
            if(!st.empty()){
                last = st.top();
                st.pop();
                last = (st.top()) * last;
                st.pop();
                st.push(last);
        }
        }
    }
    cout << st.top();
    return 0;
}

