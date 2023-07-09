# ATCODER REGULAR CONTEST WRITEUP
## 小標題
[arc164](#arc164)  
### ARC164
今天這場是我跟YTP隊友們 [lifeadventurer](https://atcoder.jp/users/lifeadventurer), [Shihhungyu](https://atcoder.jp/users/Shihhungyu) 的團練，我主要就是提供一些小想法後刻我的pB(賽後才AC...有點小失落，差點上綠)   
但整體來說今天表現算是不錯!!!  
#### pA
分析出N轉成三進位，之後每項和如果與所求差偶數且所求小於N，所求就是正確答案
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
signed main() {
    wh_ale;
  int t;
  cin >> t;
  while(t--){
    long long n, k;
    cin >> n >> k;
    long long cnt = 0, p = n;
    while(n){
      cnt += n % 3;
      n /= 3;
    }
    cout << (cnt <= k && k <= p && (k - cnt) % 2 == 0 ? "Yes\n" : "No\n");
  }
}
```
#### pC
貪心法...(賽中沒有仔細聽，但大概就是貪心那樣)  
```cpp
#include<bits/stdc++.h>
using namespace std;
#define wh_ale ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define int long long
signed main() {
  wh_ale;
  int n;
  cin >> n;
  vector<pair<long long, long long>> v(n);
  long long ans = 0, p = 0, mn = 1e18;
  for(int i = 0; i < n; i++){
    int a, b;
    cin >> a >> b;
    mn = min(mn, abs(a - b));
    p += (a > b);
    ans += max(a, b);
  }
  if(p%2)
    cout << ans - mn << endl;
  else
    cout << ans << endl;
 
  return 0;
}
```
#### pB補
賽中我就整理後發現必須是當中有剛好相鄰一組同色點的奇環才可以，就dfs加上找環，但因為我每次都要重新標記是否到達過(因為可能是上一筆到達的所以都要重整陣列)，所以經過一堆爆炸壓常優化後依然吃上一組TLE...   
**被卡的code**  
```cpp
#include<bits/stdc++.h>
using namespace std;
#define wh_ale ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
int n, m, c[200010], a[200010]={};
vector<int> v[200010];
bool t=false;
void dfs(int x, int y){
	if(!t){
    int i, j;
    a[x]=1;
    if(y==0)for(j=1;j<=n;j++){
        a[j]=0;
    }
    a[x]=1;
    for(i=0;i<v[x].size();i++){
        if(c[v[x][i]]!=c[x] and a[v[x][i]]==0){
            dfs(v[x][i], x);
        }
        if(a[v[x][i]]==1 and c[v[x][i]]==c[x]){
            t=true;
            break;
        }
    }}
}
signed main(){
    wh_ale;
    //freopen("diamond.in", "r", stdin);
    //freopen("diamond.out", "w", stdout);
    int i, j, x, y;
    cin >> n >> m;
    for(i=0;i<m;i++){
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(i=1;i<=n;i++){
        cin >> c[i];
    }
    for(i=1;i<=n;i++){
        if(a[i]==0)dfs(i, 0);
    }
    if(t) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
```
邏輯正確，但是搜尋方法其實可以多紀錄美的點的父親是誰(跟mst寫法一樣，太久沒寫撞到坑)  
**AC CODE**  
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
