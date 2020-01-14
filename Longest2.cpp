#include <bits/stdc++.h>

using namespace std;


void dfs(vector<vector<int>> &Graph, vector<bool> &visited, vector<int>&dp, int node) {
    visited[node] = 1;
    for(int i : Graph[node]) {
        if(!visited[i]) {
            dfs(Graph, visited, dp, i);
        }
        dp[node] = max(dp[node], 1 + dp[i]);
    }
}

int path(vector<vector<int>> &Graph, int n) {
    vector<bool> visited(n+1, 0);
    vector<int> dp(n+1, 0);
    for(int i=1;i<=n;i++) {
        if(!visited[i]) {
            dfs(Graph, visited, dp, i);
        }
    }
    int ans = 0;
    for(auto i : dp) ans = max(ans, i);
    return ans;

}


int main() {

    int m, n;
    cin>>n>>m;
    vector<vector<int>> Graph(n + 1, vector<int>());
    int a, b;
    
    for(int i = 0; i<m;i++) {
        cin>>a>>b;
        Graph[a].push_back(b);
    }
    // for(auto V : Graph) {
    //     for(auto i: V) {
    //         cout<<i<<" ";
    //     }
    //     cout<<'\n';
    // }
    cout<<path(Graph, n)<<'\n';
    
    return 0;
}