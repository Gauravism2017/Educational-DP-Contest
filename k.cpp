#include <bits/stdc++.h>

using namespace std;


int main() {
    int n, k;
    cin>>n>>k;
    vector<int> A(n);
    for(int i=0;i<n;i++) {
        cin>>A[i];
    }

    vector<int> dp(k + 1, 0);
    for(int i = 0;i<=k;i++) {
        for(auto a : A) {
            if(i >= a && !dp[i - a]) {
                dp[i] = 1;
            }
        }
    }
    //for(auto i : dp) cout<<i<<" ";
    cout<<(dp[k] ? "First":"Second")<<'\n'; 
    return 0;
}