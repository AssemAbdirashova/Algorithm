#define _GLIBCXX_DEBUG
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
#define pb push_back
#define mp make_pair
#define f 1000
#define s second
#define in insert
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int INF = 1e9 + 5;

struct heap{
    private:
    int a[f];
    int len;
    public:
    heap(){
        len = 0;
    }
    int get_min(){
        return a[0];
    }
    int cut_min(){
        int res = a[0];
        a[0] = a[len];
        --len;
        sift_down(0);
        return res;
    }
    void sift_down(int p){
        int l = 2 * p + 1;
        int minp = l;
        while(l<len){
        if(a[l] > a[l+1]){
            minp = l+1;
        } 
        if(a[minp] < a[p] ){
            swap(a[p], a[minp]);
        }
        else{
            break;
        }
        p= minp;
        l= 2*p+1;
        }
    }

};
int main(){

return 0;

}