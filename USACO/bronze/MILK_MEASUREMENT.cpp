//http://www.usaco.org/index.php?page=viewproblem2&cpid=761
#include<bits/stdc++.h>
using namespace std;
#define wh_ale ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ppb pop_back
#define phb push_back
#define int long long
#define f first
#define s second
#define pii pair<int, int>
struct dat{
int x, y, z;
};
bool cmp(dat a, dat b){
    return a.x<b.x;
}
int con(string s){
    if(s=="Mildred") return 0;
    if(s=="Elsie") return 1;
    if(s=="Bessie") return 2;
}
signed main() {
    wh_ale;
    freopen("measurement.in", "r", stdin);
    int n, i, j, day=0, cnt=0, rk[3]={1, 1, 1}, dt[3]={}, dy[1000]={};
    string  s;
    dat a[500];
    cin >> n;
    for(i=0;i<n;i++){
        cin >> a[i].x >> s >> a[i].z;
        a[i].y=con(s);
    }
    sort(a, a+n, cmp);
    for(int i=0;i<n;i++){
        dt[a[i].y]+=a[i].z;
        if(day!=a[i].x){
            day=a[i].x;
            for(j=0;j<3;j++){
                if(rk[j]==0 and dt[j]==max({dt[0], dt[1], dt[2]})){
                    rk[j]=1;
                    dy[day]=1;
                }
                else if(rk[j]==1 and dt[j]!=max({dt[0], dt[1], dt[2]})){
                    rk[j]=0;
                    dy[day]=1;
                }
            }
        }
    }
    for(i=0;i<=a[n-1].x;i++){
        if(dy[i]==1) cnt++;
    }
    freopen("measurement.out", "w", stdout);
    cout << cnt <<'\n';
    return 0;
}


