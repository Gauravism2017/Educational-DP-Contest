#include <bits/stdc++.h>

const int mod = 1e9+7;

using namespace std;

template <typename T>
void print(T vec) { for(auto i : vec) cout<<i<<" ";}
template <typename T>
void print2D(T matrix) {for(auto vec:matrix) {print(vec);cout<<'\n';}}

int main() {
    int n,k;
    cin>>n>>k;
    vector<int> A(n + 1);
    for(int i = 1; i < n + 1;i++) cin>>A[i];
    vector<vector<int>> dp(n + 1, vector<int>(k+1, 0));
    for(int i = 1; i<=k; i++) {
        dp[0][k] = 0;
    }
    dp[0][0] = 1;
    for(int i = 1; i<=n;i++) {
        vector<int> sums(k+1);
        sums[0] = dp[i -1][0];
        for(int j = 1; j<=k;j++) {
            sums[j] = (sums[j-1] + dp[i - 1][j]) % mod;
        }
        for(int j = 0; j<=k;j++) {
            int tr = sums[j];
            int unreachable = j - A[i] - 1;
            if(unreachable >= 0) {
                tr = (tr - sums[unreachable] + mod) % mod;
            }
            dp[i][j] = tr;
        }
    }
    //print2D(dp);
    cout<<dp[n][k]<<'\n';
    return 0;

}