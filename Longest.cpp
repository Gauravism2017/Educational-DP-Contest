
#include <bits/stdc++.h>

using namespace std;


int root(int i, vector<int>&A) {
    while(i != A[i]) {
        i = A[A[i]];
    }
    return i;
}

void wunion(int a, int b, vector<int> &A, vector<int> &size, int &maxLen) {
    int root_a = root(a, A);
    int root_b = root(b, A);
    if(root_a == root_b) return;
    if(size[root_a] < size[root_b]) {
        A[root_a] = A[root_b];
        size[root_b] +=size[root_a];
        if(size[root_b] > maxLen) {
            maxLen = size[root_b];
        }
        //cout<<maxLen<<'n';
    }
    else{
        A[root_b] = A[root_a];
        size[root_a] += size[root_b];
        if(size[root_a] > maxLen) {
            maxLen = size[root_a];
            //cout<<maxLen<<'\n';
        }
    }
}

int main() {
    int n, m;
    cin>>n>>m;
    vector<int> A(n+1);
    for(int i = 1;i<=n;i++) {
        A[i]=i;
    }
    vector<int> size(n+1, 1);
    size[0]=0;
    int maxLen = 0;
    int a, b;
    while(m--) {
        cin>>a>>b;
        wunion(a, b, A, size, maxLen);
        for(int i = 0; i<=n;i++) cout<<size[i]<<" ";
        cout<<'\n';
    }
    for(int i = 0; i<=A.size();i++) cout<<A[i]<<" ";
    cout<<'\n';
    for(int i = 0; i<=A.size();i++) cout<<size[i]<<" ";
    cout<<'\n';
    cout<<maxLen<<"\n";
    return 0;
}