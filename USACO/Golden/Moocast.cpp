http://www.usaco.org/index.php?page=viewproblem2&cpid=669
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
