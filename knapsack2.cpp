#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
const ll INF = 1e13;

int main() {
	int n; int wt;
	cin>>n>>wt;
	vector<int> w(n+1), val(n+1);
	int v =0;
	for(int i=1;i<=n;i++) {
		cin>>w[i]>>val[i];
		v+=val[i];
	}
	vector<ll> dp(v + 1, INF);
	dp[0] = 0;
	for(int item = 1; item <= n; item++) {
		int temp_w = w[item], temp_val = val[item];
		for(int i = v; i>=temp_val;i--) {
			dp[i] = min(dp[i], dp[i-temp_val] + temp_w);
		}
	}
	//for(int i =0;i<dp.size();i++) cout<<dp[i]<<" ";
	for(int i = v;i>=0;i--) {
		if(dp[i]<=wt){
			cout<<i<<'\n';
			break;
		}
	}
	return 0;

}
