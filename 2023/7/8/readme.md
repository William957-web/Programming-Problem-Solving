# 2023/7/8 Write up
今天總共解了四題(?)(有點小燒雞)  
下午有些時間拿來出之後會放在社內賽的龐大密碼學題目們  
晚上開了第一次三校會議  
此外，在今天以前我都沒有寫writeup，不過大概都可以在這個repo裡面各資料夾找到，就不一一補寫了  
### Problem1
連結： [Silver-Moocast](http://www.usaco.org/index.php?page=viewproblem2&cpid=668)  
想法：每次利用座標距離公式確認是否可以連通，建好圖對每個點重複使用dfs來算出連通到多少其他點  
```cpp
//http://www.usaco.org/index.php?page=viewproblem2&cpid=668
#include<bits/stdc++.h>
using namespace std;
#define wh_ale ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ppb pop_back
#define phb push_back
#define int long long
#define F first
#define S second
#define pii pair<int, int>
vector<int> v[300];
int n, b[300]={}, cnt[300]={}, ans=0;
struct node{
int x, y, d;
};
node a[300];
void dfs(int k, int e){
    b[k]=1;
    cnt[e]++;
    for(int i=0;i<v[k].size();i++){
        if(b[v[k][i]]==0){
            dfs(v[k][i], e);
        }
    }
}
signed main() {
    wh_ale;
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    int i, j;
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> a[i].x >> a[i].y >> a[i].d;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if((a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y)<=a[i].d*a[i].d and i!=j){
                v[i].phb(j);
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++) b[j]=0;
        dfs(i, i);
        ans=max(ans, cnt[i]);
    }
    cout << ans <<'\n';
    return 0;
}
```
### Problem2
連結： [Gold-Moocast](http://www.usaco.org/index.php?page=viewproblem2&cpid=669)  
想法：利用對答案二分搜，取範圍是```(l, r]```最後輸出r即可。```(對答案過程為二分搜)```
```cpp
//http://www.usaco.org/index.php?page=viewproblem2&cpid=669
#include<bits/stdc++.h>
using namespace std;
#define wh_ale ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ppb pop_back
#define phb push_back
#define int long long
#define F first
#define S second
#define pii pair<int, int>
pii a[1010];
int n, cnt, b[1010];
vector<int> v[1010];
void dfs(int k){
    cnt--;
    b[k]=1;
    for(int i=0;i<v[k].size();i++){
        if(b[v[k][i]]==0){
            dfs(v[k][i]);
        }
    }
}
bool chk(int r){
    cnt=n;
    int i, j;
    for(i=1;i<=n;i++){
        v[i].clear();
        b[i]=0;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(i!=j and (a[i].F-a[j].F)*(a[i].F-a[j].F)+(a[i].S-a[j].S)*(a[i].S-a[j].S)<=r){
                v[i].phb(j);
                v[j].phb(i);
            }
        }
    }
    dfs(1);
    if(cnt==0) return true;
    else return false;
}
signed main() {
    wh_ale;
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    int l, r, i, j, mid;
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> a[i].F >> a[i].S;
    }
    l=-1;
    r=25000*25000;
    while(l+1<r){
        mid=l+(r-l)/2;
        if(chk(mid)) r=mid;
        else l=mid;
    }
    cout <<r<<'\n';
    return 0;
}
```
### Problem3
連結： [Gold-Fruit Feast](http://www.usaco.org/index.php?page=viewproblem2&cpid=574)  
想法：用queu存取最後一次操作帶來的數字，用map存取狀態```(是否已經讀取過，有沒有除以二過)```
```cpp
//http://www.usaco.org/index.php?page=viewproblem2&cpid=574
#include<bits/stdc++.h>
using namespace std;
#define wh_ale ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ppb pop_back
#define phb push_back
#define int long long
#define F first
#define S second
#define pii pair<int, int>
//#define round (int)
signed main(){
    wh_ale;
    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);
    int t, a, b, i, j, x, ans=0;
    queue<int> q;
    map<int, pii> m;
    cin >> t >> a >> b;
    m[0]={1, 0};
    q.push(0);
    while(!q.empty()){
        x=q.front();
        q.pop();
        ans=max(ans, x);
        if(m.count(x+a)==0 and x+a<=t){
            m[x+a]={1, m[x].S};
            q.push(x+a);
        }
        else if(x+a<=t and m[x+a].S==1 and m[x].S==0){
            m[x+a]={1, 0};
        	q.push(x+a);
        }
        if(m.count(round((x+a)/2))==0 and x+a<=t and m[x].S==0){
            m[round((x+a)/2)]={1, 1};
            q.push(round((x+a)/2));
        }
        if(m.count(x+b)==0 and x+b<=t){
            m[x+b]={1, m[x].S};
            q.push(x+b);
        }
        else if(x+b<=t and m[x+b].S==1 and m[x].S==0){
            m[x+b]={1, 0};
        	q.push(x+b);
        }
        if(m.count(round((x+b)/2))==0 and x+b<=t and m[x].S==0){
            m[round((x+b)/2)]={1, 1};
            q.push(round((x+b)/2));
        }
    }
    cout << ans <<'\n';
    return 0;
}
```
### Problem4
連結： [CSES-Minimizing Coins](https://cses.fi/problemset/task/1634)  
想法：裸DP
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
    int n, x, a[200], dp[1000010]={}, i, j;
    cin >> n >> x;
    for(i=0;i<n;i++){
    	cin >> a[i];
    	dp[a[i]]=1;
    }
    for(j=0;j<n;j++)for(i=0;i<=x-a[j];i++){
    	if(dp[i]>0){
    		if(dp[i+a[j]]==0)dp[i+a[j]]=dp[i]+1;
    		else dp[i+a[j]]=min(dp[i+a[j]], dp[i]+1);
    	}
    }
    if(dp[x]==0) cout << -1 <<'\n';
    else cout << dp[x];
    return 0;
}

```

