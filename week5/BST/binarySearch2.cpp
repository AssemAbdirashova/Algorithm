#include <iostream>

using namespace std;

int binary_search(int *a, int n, int k) {
    int left = 0;
    int right = n - 1;
    while (left < right) {
        int m = (left + right) / 2;
        if (a[m] < k)
            left = m + 1;
        else 
            right = m - 1;
    }

    if (a[right] == k)
        return right;
    else return -1;
}

int main() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << binary_search(a, n, k);
    return 0;
}