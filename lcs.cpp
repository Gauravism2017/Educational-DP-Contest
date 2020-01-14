#include <bits/stdc++.h>

using namespace std;

int main() {
	string a, b;
	cin>>a>>b;
	int m = a.length(), n = b.length();
	
	vector<vector<int>> dp(m+1, vector<int>(n+1,0));
	
	for(int  i = 1;i<=m;i++) {
		for(int j = 1; j <=n; j++) {
			if(a[i-1]==b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
			else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
		}	
	}
	/*for(auto d : dp) {
		for(auto i : d) cout<<i<<" ";
		cout<<'\n';
	}
	*/
	//return 0;
	int i = m, j= n;
	string str = "";
	while( i > 0 && j > 0) {
		if(a[i-1] == b[j-1]) {
			str = a[i-1] + str;
			i--;
			j--;
		}
		else if(dp[i-1][j] > dp[i][j-1]) {
			i--;
		}
		else{
			j--;
		}
	}
	cout<<str<<'\n';
	//cout<<0;
	return 0;

}
