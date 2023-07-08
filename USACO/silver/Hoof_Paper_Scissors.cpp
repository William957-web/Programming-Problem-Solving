//http://www.usaco.org/index.php?page=viewproblem2&cpid=691
#include<bits/stdc++.h>
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
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    int n, i, j, a[100005][3]={}, now=0, ans=0;
    char c;
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> c;
        if(c=='P'){
            a[i][0]=a[i-1][0]+1;
            a[i][1]=a[i-1][1];
            a[i][2]=a[i-1][2];
        }
        if(c=='H'){
            a[i][0]=a[i-1][0];
            a[i][1]=a[i-1][1]+1;
            a[i][2]=a[i-1][2];
        }
        if(c=='S'){
            a[i][0]=a[i-1][0];
            a[i][1]=a[i-1][1];
            a[i][2]=a[i-1][2]+1;
        }
    }
    for(i=1;i<=n;i++){
        ans=max(ans, max({a[i-1][0], a[i-1][1], a[i-1][2]})+max({(a[n][0]-a[i-1][0]), (a[n][1]-a[i-1][1]), (a[n][2]-a[i-1][2])}));
    }
    cout << ans <<'\n';
    return 0;
}
