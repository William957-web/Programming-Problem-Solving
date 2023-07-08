//http://www.usaco.org/index.php?page=viewproblem2&cpid=687
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
    freopen("notlast.in", "r", stdin);
    int i, n, m1=10000000, m2=10000000, x;
    string s, ans, now;
    bool tie=false;
    map<string, int> m={{"Bessie", 0}, {"Maggie", 0}, {"Elsie", 0}, {"Henrietta", 0}, {"Gertie", 0}, {"Daisy", 0}, {"Annabelle", 0}};
    cin >> n;
    while(n--){
        cin >> s >> x;
        m[s]+=x;
    }
    for(auto &it : m){
        if(it.S<m1){
            now=it.F;
            m1=it.S;
        }
    }
    for(auto &it : m){
        if(m1<it.S and it.S<m2){
            now=it.F;
            m2=it.S;
        }
    }
    for(auto &it : m){
        if(it.F != now and it.S==m2){
            tie=true;
        }
    }
    freopen("notlast.out", "w", stdout);
    if(tie or m2==10000000) cout << "Tie\n";
    else cout << now <<'\n';
    return 0;
}


