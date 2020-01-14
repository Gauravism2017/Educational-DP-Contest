#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin>>n;
	vector<vector<int>> A(n, vector<int>(3));
	for(int i =0;i<n;i++) for(int j=0;j<3;j++) cin>>A[i][j];
	for(int i = 1;i<n;i++) {
		A[i][0] += max(A[i-1][1], A[i-1][2]);
		A[i][1] += max(A[i-1][0], A[i-1][2]);
		A[i][2] += max(A[i-1][1], A[i-1][0]);
	}
	cout<<*max_element(A[n-1].begin(), A[n-1].end())<<'\n';
	return 0;
}
