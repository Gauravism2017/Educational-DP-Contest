#include <bits/stdc++.h>

#define ll long long int
using namespace std;

// recursion

ll func(ll wt, vector<ll> &val, vector<ll> &w, ll n) {
	if(n == 0 || wt == 0) return 0;
	if(w[n-1] > wt) return func(wt, val, w, n - 1);
	else return max(val[n-1] + func(wt-w[n-1], val, w, n - 1), func(wt, val, w, n - 1));
	
}

//dp
ll knapSack(ll wt, vector<int> &val, vector<ll> &w, int n) {
	if(n == 0 || wt == 0) return 0;
	vector<vector<ll>> dp(n+1, vector<ll>(wt+1,0));
	
	for(int i = 1;i <=n;i++) {
		for(ll j = 1; j <=wt; j++) {
			if(w[i-1] <= j) {
				dp[i][j] = max(val[i-1] + dp[i - 1][j - w[i - 1]], dp[i - 1][j]);
			}
			else {
				dp[i][j] = dp[i-1][j];
				}
		}
	}
	return dp[n][wt];
}


int main() {
	int n ;
	ll wt;
	cin>>n>>wt;
	vector<int> val(n);
	vector<ll> w(n);
	for(int i =0; i<n;i++) {
		cin>>w[i]>>val[i];
	}
	//cout<<func(wt, val, w, n)<<'\n';
	cout<<knapSack(wt, val, w, n)<<'\n';
	//cout<<knapSack(wt, w, val, n);
	return 0;

}
