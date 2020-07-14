
#include <iostream>
#include <cmath>
#define MAXN 1000

using namespace std;

struct heap{
    private:
        int a[MAXN];
        int len;

    public:
        heap(){
            len = 0;
        }
        int getSize(){
        return len;
    }
        int get_min(){
            return a[0];
        }
        int cut_min(){
            int res = a[0];
            a[0] = a[--len];
            sift_down(0);
            return res;
        }

        void sift_down(int p){
            int l = 2 * p + 1;
            //int minp = (a[l] < a[l + 1]) ? l : l + 1;
            while(l < len){
                int minp = l;
                if(a[l] > a[l + 1]){
                    minp = l + 1;
                }
                if(a[p] > a[minp]){
                    swap(a[p], a[minp]);
                }else{
                    break;
                }
                p = minp;
                l = 2 * p + 1;
            }
        }

        void sift_up(int x){
            int p = (x - 1) / 2;
            while(x > 0 && a[p] > a[x]){
                swap(a[p], a[x]);
                x = p;
                p = (x - 1) / 2;
            }
        }
        void increaseKey(int val, int index){
            a[index] += val;
            sift_down(index);
        }
        void decreaseKey(int val, int index){
            a[index] -= val;
            sift_up(index);
        }
        void add(int val){
            int x = len;
            a[len++] = val;
            sift_up(x);
        }

        void print(){
            for(int i = 0; i < len; ++i){
                cout << a[i] << " ";
            }
            cout << endl;
        }
};

int main(){
    int arr[] = {22, 13 , 9 , 15 , 7};
    int n = sizeof(arr) / sizeof(int);

    heap h;

    for(int i = 0; i < n; ++i){
        h.add(arr[i]);
    }
    h.print();
    // h.increaseKey(3,3);
    // h.decreaseKey(3,2);
    
     long double sum;

     int i = 0;
     int size = h.getSize();
     while(size>1){
        
       sum +=  (static_cast<double>(h.cut_min()) + static_cast<double>(h.cut_min())*0.05);
        size--;
       i++;
       
       
    }
    cout << sum;
    h.print();
    return 0;
}