#include <bits/stdc++.h>

using namespace std;
#define ld long double
vector <ld> v;
string s;
vector <char> result;
ld res;
ld esp = 1e-5;

ld returnValue(vector <char> &curCal){
	stack <ld> st;
	st.push(v[0]);
	for (int j = 0; j < v.size() - 1; j++){
		
		if (curCal[j] == 'X'){
			ld val = st.top();
			st.pop();
			val = val * v[j+1];
			st.push(val);
		}
		else if (curCal[j] == '-'){
			ld val = -v[j+1];
			st.push(val);
		}
		else {
			st.push(v[j+1]);
		}
	}
	ld val = 0;
	while(!st.empty()){
		val = val + st.top();
		st.pop();
	}

	return val;
}

bool solve(int i, vector <char> &curCal){
	
	if (i == v.size()){
		
		ld val = returnValue(curCal);
		if (abs(val - res) <= esp){
			result = curCal;
			return 1;
		}
		return 0;
	}
	
	curCal.push_back('+');
	if(solve(i + 1, curCal) == 1){
		return 1;
	}
	curCal.pop_back();

	curCal.push_back('-');
	if (solve(i + 1, curCal) == 1){
		return 1;
	}
	curCal.pop_back();

	curCal.push_back('x');
	if (solve(i + 1, curCal) == 1){
		return 1;
	}
	curCal.pop_back();

	return 0;
}
int main(){
	int n;
	cin >> n;
	while(cin >> s){
			
		string num = "";
		int id;
		for (int i = 0; i < s.length() && s[i] != '/'; i++){
			num += s[i];
			id = i;
		}
		string denom = "";
		for (int i = id + 2; i < s.length(); i++){
			denom += s[i];
		}
		v.push_back(((ld)stoi(num) / (ld)stoi(denom)));
	}
	res = v.back();
	v.pop_back();
	vector <char> curComp;
	solve(1, curComp);

	for (auto o : result) cout << o;
	return 0;
}