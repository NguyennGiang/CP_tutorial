#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <functional>
#define RASENGAN ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

int main() {
	RASENGAN
	string s;
	int input;
	int middle;

	priority_queue<int> small;
	priority_queue<int, vector<int>, greater<int> > big;

	cin >> input;
	middle = input;

	while(cin >> s) {
		if(s != "#") {
			input = stoi(s);
			// Add cookie to queue
			if(middle == -1) {
				middle = input;
			} else if(input > middle) { 		// bigger
				big.push(input);
			} else if(input < middle) { // smaller
				small.push(input);
			} else { 					// equal
				if(big.size() == small.size()) {
					small.push(input);
				} else {
					big.push(input);
				}
			}

			// See if we need to make new middle
			if(small.size() > big.size() + 1) { // Two more in small than in big
				big.push(middle);
				middle = small.top();
				small.pop();
			} else if(small.size() < big.size()) {
				small.push(middle);
				middle = big.top();
				big.pop();
			}
		} else {
			cout << middle << endl;
			if(big.empty() && small.empty()) {
				middle = -1;
			}
			else if(big.size() == small.size()) {
				middle = big.top();
				big.pop();
			} else {
				middle = small.top();
				small.pop();
			}
		}
		
	}

	return 0;
}