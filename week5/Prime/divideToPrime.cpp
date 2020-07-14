#include <iostream>
#include <vector>

using namespace std;

int n;
bool was[1005];

int main() {

    cin >> n;
    vector< pair<int, int> > fact;
    vector< pair<int, int> > factSec;
    int sum;
    

    int x = n;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            // this number must be prime
            int cnt = 0;
            while (x % i == 0)
                x /= i, cnt++;
            fact.push_back( make_pair(i, cnt) );
        }
    }
    if (x > 1) {
        fact.push_back( make_pair(x, 1) );
    }
    for (int i = 0; i < (int)fact.size(); i++) {
         sum+=fact[i].first*fact[i].second;
    }
    int x1=sum;
    
     for (int i = 2; i * i <= x1; i++) {
        if (x1 % i == 0) {
            // this number must be prime
            int cnt = 0;
            while (x1 % i == 0)
                x1 /= i, cnt++;
            factSec.push_back( make_pair(i, cnt) );
        }
    }
    if (x1 > 1) {
        factSec.push_back( make_pair(x1, 1) );
    }
    for (int i = 0; i < (int)factSec.size(); i++) {
        int pow=factSec[i].second;
        for(int t=0;t<pow;t++){
            cout<<factSec[i].first<<" ";
        }
    }

    return 0;
}