//https://cses.fi/problemset/task/1662
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
    //freopen("hps.in", "r", stdin);
    //freopen("hps.out", "w", stdout);
    int n, i, a[300000]={}, x, t, cnt=0;
    map<int, int> m{{0, 1}};
    cin >> n>>t;
    for(i=1;i<=n;i++){
        cin >> x;
        a[i]=a[i-1]+x;
        if(m.count(a[i])==0) m[a[i]]=1;
        else m[a[i]]++;
        if(m.count(a[i]-t)>0) cnt += m[a[i]-t];
        if(x==0 and t==0) cnt--;
    }
    cout << cnt <<'\n';
    return 0;
}
