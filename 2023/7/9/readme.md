# 2023/7/9 Write up
### Problem1
題目：[CSES-Subarray Divisibility](https://cses.fi/problemset/task/1662)  
注意：% operator 可能有負的
```cpp
//https://cses.fi/problemset/task/1634
#include<bits/stdc++.h>
using namespace std;
#define wh_ale ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ppb pop_back
#define phb push_back
#define int long long
#define F first
#define S second
#define pii pair<int, int>
signed main(){
    wh_ale;
    //freopen("feast.in", "r", stdin);
    //freopen("feast.out", "w", stdout);
    int n, a[250000]={}, dp[250000]={}, cnt=0;
    int mp[250000]={};
    mp[0]=1;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++){
        dp[i]=a[i]+dp[i-1];
        if(dp[i]%n>=0)mp[dp[i]%n]++;
        else mp[n+dp[i]%n]++;
    }
    for(int ii=0;ii<n;ii++){
        cnt += (mp[ii]-1)*mp[ii]/2;
    }
    cout << cnt <<'\n';
    return 0;
}

```
