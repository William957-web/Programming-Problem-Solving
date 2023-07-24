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
int dp[30][200010]={}, n, a[200010]={};
int minv(int x, int y){
	int l, r;
	l=x;
	r=y;
    int ans=1e10;
    while(l<=r){
        ans=min(dp[a[r-l+1]][l], ans);
    	if(l==r) break;
        l+=pow(2, a[r-l+1]);
    }
    return ans;
}
signed main(){
    wh_ale;
    //freopen("teamwork.in", "r", stdin);
    //freopen("teamwork.out", "w", stdout);
    int q, x, y, i, e=0;
    cin >> n >> q;
    for(i=1;i<=n;i++){
        cin >> dp[0][i];
    }
    int cur=1;
    for(i=1;i<=200000;i++){
    	if(cur<=i/2){
    		e++;
    		cur*=2;
    	}
    	a[i]=e;
    }
    e=1;
    cur=2;
    while(cur<=200000){
        for(i=1;i<=n-cur+1;i++){
            dp[e][i]=min(dp[e-1][i], dp[e-1][i+cur/2]);
        }
        cur=cur*2;
        e++;
    }
    while(q--){
        cin >> x >> y;
        cout << minv(x, y)<<'\n';
    }
    return 0;
}
//womp womp
