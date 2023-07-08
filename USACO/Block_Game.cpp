//http://www.usaco.org/index.php?page=viewproblem2&cpid=664
#include<bits/stdc++.h>
using namespace std;
#define wh_ale ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ppb pop_back
#define phb push_back
#define int long long
#define f first
#define s second
#define pii pair<int, int>
#define pss pair<string, string>
signed main() {
    wh_ale;
    int n, i, j, cnt[26]={}, b[26][2]={};
    string s1, s2;
    freopen("blocks.in", "r", stdin);
    cin >> n;
    for(i=0;i<n;i++){
        cin >> s1 >> s2;
        for(j=0;j<26;j++){
            b[j][0]=0;
            b[j][1]=0;
        }
        for(j=0;j<s1.size();j++){
            b[s1[j]-'a'][0]++;
        }
        for(j=0;j<s2.size();j++){
            b[s2[j]-'a'][1]++;
        }
        for(j=0;j<26;j++){
            cnt[j]+=max(b[j][0], b[j][1]);
        }
    }
    freopen("blocks.out", "w", stdout);
    for(i=0;i<26;i++){
        cout << cnt[i]<<'\n';
    }
    return 0;
}
