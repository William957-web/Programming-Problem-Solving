//http://www.usaco.org/index.php?page=viewproblem2&cpid=831&lang=en
#include<bits/stdc++.h>
using namespace std;
#define wh_ale ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ppb pop_back
#define phb push_back
#define int long long
#define f first
#define s second
#define pii pair<int, int>
signed main() {
    wh_ale;
    string s[3];
    int i, j, cnt=0, ans=0, mx=0, b[26]={};
    vector<int> v;
    freopen("tttt.in", "r", stdin);
    for(i=0;i<3;i++){
        cin >> s[i];
        for(j=0;j<3;j++){
            b[s[i][j]-'A']++;
        }
    }
    for(j=0;j<26;j++) if(b[j]!=0) v.phb(j);
    for(int q=0;q<v.size();q++)for(int ii=0;ii<v.size();ii++){
        cnt=0;
    for(i=0;i<3;i++){
        if(s[i][0]==char('A'+v[ii]) or s[i][0]==char('A'+v[q])){
            if(s[i][1]==char('A'+v[ii]) or s[i][1]==char('A'+v[q]))if(s[i][2]==char('A'+v[ii]) or s[i][2] ==char('A'+v[q]))cnt++;
        }
    }
    for(i=0;i<3;i++){
        if(s[0][i]==char('A'+v[ii]) or s[0][i]==char('A'+v[q])){
            if(s[1][i]==char('A'+v[ii]) or s[1][i]==char('A'+v[q]))if(s[2][i]==char('A'+v[ii]) or s[2][i] ==char('A'+v[q]))cnt++;
        }
    }
    if(s[0][0]==char('A'+v[ii]) or s[0][0]==char('A'+v[q])){
        if(s[1][1]==char('A'+v[ii]) or s[1][1]==char('A'+v[q]))if(s[2][2]==char('A'+v[ii]) or s[2][2]==char('A'+v[q]))cnt++;
    }
    if(s[0][2]==char('A'+v[ii]) or s[0][2]==char('A'+v[q])){
        if(s[1][1]==char('A'+v[ii]) or s[1][1]==char('A'+v[q]))if(s[2][0]==char('A'+v[ii]) or s[2][0]==char('A'+v[q]))cnt++;
    }
    if(q==ii  and cnt>0) ans++;
    else if(cnt>0){
        for(i=0;i<3;i++){
        if(s[i][0]==s[i][1] and  s[i][1]==s[i][2] ){
            if(s[i][0]==char('A'+v[q]) or s[i][0]==char('A'+v[ii]))cnt--;
        }
    }
        for(i=0;i<3;i++){
        if(s[0][i]==s[1][i] and  s[2][i]==s[1][i]){
            if(s[0][i]==char('A'+v[q]) or s[0][i]==char('A'+v[ii]))cnt--;
        }
    }
    if(s[1][1]==s[2][2] and  s[2][2]==s[0][0]){
            if(s[0][0]==char('A'+v[q]) or s[0][0]==char('A'+v[ii]))cnt--;
    }
    if(s[0][2]==s[1][1] and  s[1][1]==s[2][0]){
            if(s[1][1]==char('A'+v[q]) or s[1][1]==char('A'+v[ii]))cnt--;
    }
    if(cnt>0) mx++;
    }
    }
    freopen("tttt.out", "w", stdout);
    cout << ans <<'\n'<< mx/2 <<'\n';
    return 0;
}


