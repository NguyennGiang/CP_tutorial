#include <bits/stdc++.h>
using namespace std;
#define KAMEHAMEHA ios_base::sync_with_stdio(0); cin.tie(0);
#define ll long long;
#define N 100010

char str[2 * N], s[3][N];
int p[2 * N];

int kmp(char *s1, char *s2){
	int n = strlen(s1);
	int m = strlen(s2);
	int j = -1;
	p[0] = -1;
	for (int k = 1; k < m; k++){
		while (j >= 0 && s2[k] != s2[j + 1]) j = p[j];
		if (s2[k] == s2[j + 1]) j++;
		p[k] = j;
	}

	j = -1;
	for (int k = 0; k < n; k++){
		if (j == m - 1) return 0;
		while (j >= 0 && s1[k] != s2[j + 1]) j = p[j];
		if (s1[k] == s2[j + 1]) j++;
	}
	return m - 1 - j;
}

int solve(char *s1, char *s2, char *s3){
	int len = kmp(s1, s2);
	str[0] = '\0';
	strcat(str, s1);
	strcat(str, s2 + strlen(s2) - len);
	len = kmp(str, s3);
	return strlen(str) + len;
}

int main(){
	KAMEHAMEHA

	cin >> s[0] >> s[1] >> s[2];
	int res = solve(s[0], s[1], s[2]);
	int l;
	l = solve(s[0], s[2], s[1]);
	if (l < res) res = l;

	l = solve(s[1], s[2], s[0]);
	if (l < res) res = l;

	l = solve(s[1], s[0], s[2]);
	if (l < res) res = l;

	l = solve(s[2], s[1], s[0]);
	if (l < res) res = l;

	l = solve(s[2], s[0], s[1]);
	if (l < res) res = l;

	cout << res << endl;
	return 0;
}
