#include <bits/stdc++.h>

using namespace std;

template <typename T>
void print(T vec) { for(auto i : vec) cout<<i<<" ";}
template <typename T>
void print2D(T matrix) {for(auto vec:matrix) {print(vec);cout<<'\n';}}


int main() {
    int n;
    cin>>n;
    vector<double> prob(n + 1, 0);
    for(int i = 1;i <=n;i++) {
        cin>>prob[i];
    }
    vector<vector<double>> dp(n+1,vector<double>(n+1, 0));
    dp[0][0] = 1.0;
    for(int i = 1; i<=n;i++) {
        for(int j = 0;j <= i; j++) {
            if(j == 0) {
                dp[i][j] = dp[i - 1][j] * ((double)1 - prob[i]);
            }
            else dp[i][j] = dp[i - 1][j - 1] * prob[i] +  dp[i - 1][j] * ((double)1 - prob[i]);

        }
    }
    double ans = 0.0;
    for(int i = (n+1)/2;i<=n;i++) {
        ans+=dp[n][i];
    }
    cout<<setprecision (numeric_limits<double>::digits10 + 1)<<ans<<'\n';
    //print2D(dp);

    return 0;
}