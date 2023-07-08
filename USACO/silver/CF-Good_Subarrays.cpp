//https://codeforces.com/contest/1398/problem/C
//The a[0] is also needed to be considered in pre array sum
#include<bits/stdc++.h>
using namespace std;
#define wh_ale ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ppb pop_back
#define phb push_back
#define int long long
#define F first
#define S second
#define pii pair<int, int>
void run(){
    int n , i, j, a[200000]={}, cnt=0;
    string s;
    map<int, int> m;
    cin >> n >> s;
    for(i=1;i<=n;i++){
        a[i]+=(s[i-1]-'0')+a[i-1];
    }
    for(i=0;i<=n;i++){
        m[a[i]-i]++;
    }
    for(auto &it : m){
        cnt += (it.S-1)*it.S/2;
        cout << it.S<<'\n';
    }
    cout << cnt <<'\n';
}
signed main() {
    wh_ale;
    //freopen("hps.in", "r", stdin);
    //freopen("hps.out", "w", stdout);
    int n;
    cin >> n;
    while(n--){
        run();
    }
    return 0;
}
