#include <bits/stdc++.h>
//include<iostream>

using namespace std;

int main() {
	int n;
	cin>>n;
	vector<int> A(n);
	for(int i = 0; i<n;i++) cin>>A[i]; 
	vector<int> dp(n,INT_MAX);
	dp[0] = 0;
	dp[1] = abs(A[1] - A[0]);
	for(int i = 2; i <n;i++) {
		dp[i] = min(dp[i - 1] + abs(A[i] - A[i-1]), dp[i-2] + abs(A[i] - A[i-2]));
	}
	//for(auto i : dp) cout<<i<<'\n';
	cout<<dp[n-1]<<'\n';
	return 0;
}
