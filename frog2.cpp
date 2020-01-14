#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k;
	cin>>n>>k;
	vector<int> A(n), dp(n, INT_MAX);
	for(int i =0;i<n;i++) cin>>A[i];
	dp[0] = 0;
	for(int i = 0;i<n;i++) {
		int temp = 1;
		while(temp <= k && i+temp < n) {
			dp[i+temp] = min(dp[i+temp], dp[i]+abs(A[i+temp]-A[i]));
			temp++;
		}
	} 
	//for(auto i : dp) cout<<i <<" ";
	cout<<dp[n-1]<<'\n';
	return 0;

}
