//http://www.usaco.org/index.php?page=viewproblem2&cpid=593
//The a[0] is also needed to be considered in pre array sum some timeB
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
    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout);
    int i, j, n=0, ans=-1, time=0, x;
    bool t=false;
    char c;
    map<pii, int> m;
    pii now={0, 0};
    m[now]=0;
    cin >> n;
    while(n--){
        cin >> c >> x;
        if(c=='N'){
            for(i=0;i<x;i++){
                now.F++;
                time++;
                if(m.count(now)==0){
                    m[now]=time;
                }
                else{
                    if(!t){
                        t=true;
                        ans=time-m[now];
                        m[now]=time;
                    }
                    else{
                        ans=min(ans, time-m[now]);
                        m[now]=time;
                    }
                }
            }
        }
        if(c=='S'){
            for(i=0;i<x;i++){
                now.F--;
                time++;
                if(m.count(now)==0){
                    m[now]=time;
                }
                else{
                    if(!t){
                        t=true;
                        ans=time-m[now];
                        m[now]=time;
                    }
                    else{
                        ans=min(ans, time-m[now]);
                        m[now]=time;
                    }
                }
            }
        }
        if(c=='E'){
            for(i=0;i<x;i++){
                now.S++;
                time++;
                if(m.count(now)==0){
                    m[now]=time;
                }
                else{
                    if(!t){
                        t=true;
                        ans=time-m[now];
                        m[now]=time;
                    }
                    else{
                        ans=min(ans, time-m[now]);
                        m[now]=time;
                    }
                }
            }
        }
        if(c=='W'){
            for(i=0;i<x;i++){
                now.S--;
                time++;
                if(m.count(now)==0){
                    m[now]=time;
                }
                else{
                    if(!t){
                        t=true;
                        ans=time-m[now];
                        m[now]=time;
                    }
                    else{
                        ans=min(ans, time-m[now]);
                        m[now]=time;
                    }
                }
            }
        }
    }
    cout << ans <<'\n';
    return 0;
}
