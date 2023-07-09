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
### Problem2
題目：[https://cses.fi/problemset/task/1662](https://atcoder.jp/contests/arc164/tasks/arc164_b)  
注意：找環技巧，dfs
```cpp

#include<bits/stdc++.h>
using namespace std;
#define wh_ale ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
int n, m, c[200010], a[200010]={}, p[200010];
vector<int> v[200010];
bool t=false;
void dfs(int x, int y){
	if(!t){
    int i, j;
    a[x]=1;
    for(i=0;i<v[x].size();++i){
        if(c[v[x][i]]!=c[x] and a[v[x][i]]==0){
        	p[v[x][i]]=y;
            dfs(v[x][i], y);
        }
    }}
}
signed main(){
    wh_ale;
    //freopen("diamond.in", "r", stdin);
    //freopen("diamond.out", "w", stdout);
    int i, j, x, y;
    cin >> n >> m;
    for(i=0;i<m;++i){
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(i=1;i<=n;++i){
        cin >> c[i];
        p[i]=i;
    }
    for(i=1;i<=n;++i){
        if(a[i]==0)dfs(i, i);
    }
    for(i=1;i<=n;++i){
        if(!t)for(j=0;j<v[i].size();j++){
        	if(c[i]==c[v[i][j]] and p[i]==p[v[i][j]]){
        		t=true;
        		break;
        	}
        }
    }
    if(t) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
```
### Problem3
題目：[https://atcoder.jp/contests/abc309/submissions/43404094](https://atcoder.jp/contests/abc309/tasks/abc309_d)  
作法：分兩邊取最長距離相加  
```cpp
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
    //freopen("diamond.in", "r", stdin);
    //freopen("diamond.out", "w", stdout);
    int n1, n2, m, i, j, x, y, mx1=0, mx2=0, g[300050]={};
    queue<int> q1, q2;
    vector<int> v[300050];
    cin >> n1 >> n2 >> m;
    for(i=0;i<m;i++){
        cin >> x >> y;
        v[x].phb(y);
        v[y].phb(x);
    }
    q1.push(1);
    g[1]=1;
    while(!q1.empty()){
        x=q1.front();
        q1.pop();
        mx1=max(mx1, g[x]-1);
        for(i=0;i<v[x].size();i++){
            if(g[v[x][i]]==0){
                q1.push(v[x][i]);
                g[v[x][i]]=g[x]+1;
            }
        }
    }
    q2.push(n1+n2);
    g[n1+n2]=1;
    while(!q2.empty()){
        x=q2.front();
        q2.pop();
        mx2=max(mx2, g[x]-1);
        for(i=0;i<v[x].size();i++){
            if(g[v[x][i]]==0){
                q2.push(v[x][i]);
                g[v[x][i]]=g[x]+1;
            }
        }
    }
    cout << mx1+mx2+1<<'\n';
    return 0;
}
```
### Problem4
題目：[https://atcoder.jp/contests/abc309/submissions/43404094](https://atcoder.jp/contests/abc309/tasks/abc309_c)
作法：greedy+前綴和  
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
    //freopen("diamond.in", "r", stdin);
    //freopen("diamond.out", "w", stdout);
    int n, k, i, dp[300050]={};
    pii a[300050];
    a[0]={0, 0};
    cin >> n >> k;
    for(i=1;i<=n;i++){
        cin >> a[i].F >> a[i].S;
    }
    sort(a+1, a+n+1);
    for(i=n;i>=1;i--){
        dp[i]=dp[i+1]+a[i].S;
    }
    for(i=1;i<=n;i++){
    	if(dp[i]<=k){
    		cout << a[i-1].F+1 <<'\n';
    		break;
    	}
    }
    if(dp[n]>k) cout << a[n].F+1<<'\n';
    return 0;
}
```
待補
