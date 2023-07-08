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
