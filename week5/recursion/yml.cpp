#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;

vector<vector<int> > par(int n) {
    vector<vector<int> > res;
    vector<int> lst;
    if (n < 5) {
        return res;
    }
    int s = n * (n + 1) / 2;
    if (s % 3 != 0) {
        return res;
    }
    s /= 3;
    for (int i = 1; i <= n; i++) {
        lst.push_back(i);
    }
    for (int i = 0; i < 2; i++) {
        vector<int> sub_set;
        int s_cur = s;
        while (s_cur > 0) {
            int idx_max = upper_bound(lst.begin(), lst.end(), s_cur) - lst.begin() - 1;
            sub_set.push_back(lst[idx_max]);
            s_cur -= lst[idx_max];
            lst.erase(lst.begin() + idx_max);
    }
    res.push_back(sub_set);
}
    res.push_back(lst);
    return res;
}

int main() {
    int n;
    cin >> n;
    auto answer = par(n);
    if (answer.empty()) {
        cout << -1 << endl;
    } else {
        for (const auto &row : answer) {
        cout << row.size() << endl;
        for (const auto &val : row) {
        cout << val << " ";
    }
      cout << endl;
    }
}
  return 0;
}
