#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0);
#define ll long long 

using namespace std; 

void rebalance(priority_queue <int> &maxHeap, priority_queue <int, vector <int>, greater <int> > &minHeap){
	if (maxHeap.size() > minHeap.size() + 1){
		minHeap.push(maxHeap.top());
		maxHeap.pop();
	}
	else if (minHeap.size() > maxHeap.size()){
		maxHeap.push(minHeap.top());
		minHeap.pop();
	}
}

void addNum(int num, priority_queue <int> &maxHeap, priority_queue <int, vector <int>, greater <int> > &minHeap){
	if (maxHeap.size() == 0 || maxHeap.top() > num){
		maxHeap.push(num);
	}
	else minHeap.push(num);
	rebalance(maxHeap, minHeap);
}

void getMedian(priority_queue <int> &maxHeap, priority_queue <int, vector <int>, greater <int> > &minHeap){
	if(maxHeap.size() == minHeap.size() || maxHeap.size() > minHeap.size()){
		cout << maxHeap.top() << endl;
		maxHeap.pop();
		rebalance(maxHeap, minHeap);
	}
}

int main(){
	fast_io
	int t; 
	cin >> t;
	while(t--){
		priority_queue <int> maxHeap;
		priority_queue <int, vector <int>, greater <int> > minHeap;

		while(1){
			int num;
			cin >> num; 
			if (num == 0){
				break;
			}
			else if (num == -1){
				getMedian(maxHeap, minHeap);
			}
			else {
				addNum(num, maxHeap, minHeap);
			}
		}
	}
	return 0; 
}