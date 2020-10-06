#include<bits/stdc++.h>
using namespace std;

string shortestCommonSupersequence(string s1, string s2) {
	int m = s1.length();
	int n = s2.length();
	int dp[m+1][n+1];
	for(int j=0;j<=n;j++) {
		dp[0][j] = 0;
	}
	for(int i=0;i<=m;i++) {
		dp[i][0] = 0;
	}
	for(int i=1;i<=m;i++) {
		for(int j=1;j<=n;j++) {
			if(s1[i-1] == s2[j-1]) {
				dp[i][j] = 1 + dp[i-1][j-1];
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	string word = "";
	int i, j;
	i = m;
	j = n;
	while(i > 0 && j > 0) {
		if(s1[i-1] == s2[j-1]) {
			word += s1[i-1];
			i--;
			j--;
		} else {
			if(dp[i-1][j] > dp[i][j-1]) {
				word += s1[i-1];
				i--;
			} else {
				word += s2[j-1];
				j--;
			}
		}
	}
	while(i > 0) {
		word += s1[i-1];
		i--;
	}
	while(j > 0) {
		word += s2[j-1];
		j--;
	}
	reverse(word.begin(), word.end());
	return word;
}

int main() {
	string s1, s2;
	cout<<"Enter the string1: ";
	cin>>s1;
	cout<<"Enter the string2: ";
	cin>>s2;
	string ans = shortestCommonSupersequence(s1, s2);
	cout<<"Shortest Common Subsequence is: "<<ans;
	return 0;
}
