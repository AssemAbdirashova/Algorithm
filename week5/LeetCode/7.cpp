#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, k;

int main() {
	cin >> n >> k;
    int nums1[n];
    int nums2[k];
    int first = 0;
    int second = 0;
    vector<int> result;

	for (int i = 0; i < n; i++) {
		cin >> nums1[i];
	}
    for (int i = 0; i < k; i++) {
		cin >> nums2[i];
	}
    int l = 0;

    while(first < n && second < k){
        if( nums1[first] < nums2[second]){
            result.push_back(nums1[first++]);
        }
        else{ 
            result.push_back(nums2[second++]);
        }
    }
    while (first < n)
        result.push_back(nums1[first++]);
    
    while (second < k)
        result.push_back(nums2[second++]);

    for (int i = 0; i < result.size(); i++) {
		cout << result[i];
	}
    return 0;
}