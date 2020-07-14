#include <iostream>
#include <deque>

using namespace std;

int main() {
	deque<int> d;
	bool reverse = 0;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s == "reverse") {
			reverse = !reverse;
		}
		else if (s == "front") {
			if (reverse) {
				if (d.empty()) {
					cout << ";(\n";
				}
				else {
					cout << d.back();
					d.pop_back();
				}
            }
			else {
				if (d.empty()) {
					cout << ";(\n";
				}
				else {
					cout << d.front();
					d.pop_front();
				}
			}
			}
		} 
	}

