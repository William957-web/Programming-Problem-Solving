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
