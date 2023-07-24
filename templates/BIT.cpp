//plz just do your best, don't feel like you are falling yourself now
//Remember there's still many people care about you
//Enjoy coding
//WH_ALE
//oh this is your tiny secret: NTY1YjUwNjNjODgwM2MxM2M4ZDY0M2EzNTFmMDU5N2E=
//maybe it's multiset not set
#include<bits/stdc++.h>
using namespace std;
#define wh_ale ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define phb push_back
#define ppb pop_back
#pragma gcc optimize("O3, unroll-loop")
int n, a[200010], tree[200010]={};
void add(int k, int x){
    while(k<=n){
        tree[k]+= x;
        k += k&-1*k;
    }
}
int sum(int k){
    int ans=0;
    while(k>=1){
        ans += tree[k];
        k -= k&-1*k;
    }
    return ans;
}
signed main(){
    wh_ale;
    //freopen("teamwork.in", "r", stdin);
    //freopen("teamwork.out", "w", stdout);
    int cmd, x, y, i, q;
    cin >> n >> q;
    for(i=1;i<=n;i++){
        cin >> a[i];
        add(i, a[i]);
    }
    while(q--){
        cin >> cmd >> x >> y;
        if(cmd==1){
            add(x, y-a[x]);
            a[x]=y;
        }
        else {
            cout << sum(y)-sum(x-1) << '\n';
        }
    }
    return 0;
}
//womp womp
