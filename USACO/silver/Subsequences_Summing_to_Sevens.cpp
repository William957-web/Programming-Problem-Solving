//http://www.usaco.org/index.php?page=viewproblem2&cpid=595
#include<bits/stdc++.h>
#pragma gcc optimize("Ofast")
using namespace std;
#define wh_ale ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ppb pop_back
#define phb push_back
#define int long long
#define F first
#define S second
#define pii pair<int, int>
signed main() {
    wh_ale;
    freopen("div7.in", "r", stdin);
    int i, j, n, a[60000]={}, x, ans=0, l, r, b[7]={0, -1, -1, -1, -1, -1, -1};
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> x;
        a[i]=a[i-1]+x;
        if(b[a[i]%7]==-1) b[a[i]%7]=i;
        ans=max(ans, i-b[a[i]%7]);
    }
    freopen("div7.out", "w", stdout);
    cout << ans <<'\n';
    return 0;
}
