#include <iostream>
#define ll long long

using namespace std;

int main() {
	ll n, a, b, c;
	cin >> n >> a >> b >> c;
	ll l = 0, r = 1e18; //10 ^ 18
	while(r > l) {
		ll mid = (l + r) / 2;
		if (mid / a + mid / b + mid / c >= n) {
			r = mid;
		}
		else l = mid + 1;
	}
	cout << l;
}
