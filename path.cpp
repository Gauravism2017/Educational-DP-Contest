#include <bits/stdc++.h>

const int MOD = 1e9+7;

using namespace std;

int main() {
    int H, W;
    cin>>H>>W;
    vector<string> Grid(H);
    for(int i = 0; i<H;i++) {
        cin>>Grid[i];
    }
    vector<vector<int>> dp(H + 1, vector<int>(W + 1, 0));
    //dp[1][1] = 1;
    for(int i = 1; i <= H; i++) {
        for(int j = 1; j <= W; j++) {
            //cout<<'a'<<'\n';
            if(i == 1 && j == 1) {
                dp[i][j]=1;
                //cout<<"done"<<'\n';
            }
            else if(Grid[i - 1][j - 1] == '.') {
                //cout<<Grid[i - 1][j - 1]<<' ';
                dp[i][j] = (dp[i-1][j] % MOD + dp[i][j - 1] %MOD) %MOD;
            }
            else  {
                dp[i][j] = 0;
            }
        }
        //cout<<'\n';
    }
    // for(auto vec : dp) {
    //     for(auto i : vec) {
    //         cout<<i<<" ";
    //     }
    //     cout<<'\n';
    // }
    cout<<dp[H][W]<<'\n';
    return 0;
}