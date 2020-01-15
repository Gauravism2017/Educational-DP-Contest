#include <bits/stdc++.h>
typedef long long int ll;

using namespace std;

template <typename T>
void print(T vec) { for(auto i : vec) cout<<i<<" ";}
template <typename T>
void print2D(T matrix) {for(auto vec:matrix) {print(vec);cout<<'\n';}}


int main() {
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i =0;i<n;i++) cin>>A[i];
    vector<vector<ll>> dp(n+1, vector<ll>(n+1));
    auto sum = [&](int L, int R) {
        ll s= 0;
        for(int i= L; i<=R;i++) {
            s+=A[i];
        }
        return s;
    };
    
    for(int L = n-1;L>=0;L--) {
        for(int R = L; R<n;R++) {
            if(R == L) {
                dp[L][R] = 0;
            }
            else{
                dp[L][R] = 1e18+5;
                ll s = sum(L, R);
                for(int i=L;i<=R;i++) {
                    dp[L][R] = min(dp[L][R], dp[L][i] + dp[i+1][R]+ s);
                }
            }
        }
    }
    //print2D(dp);
    cout<<dp[0][n-1]<<'\n';
    return 0;

}