#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,k;
    cin>>n>>k;
    vector<int> A(n);
    for(int i = 0; i < n;i++) cin>>A[i];
    vector<int> dp(n+1, 0);
    for(int i = 0; i<n;i++) {
        int upto = A[i];
        for(int used = k; used>=0;k--) {
            int temp = dp[used];
            int l = used + 1;
            int r = min(k - used, upto);
            if(l<=r) {
                
            }
        }
    }
}