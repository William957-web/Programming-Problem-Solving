#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("O3,unroll-loops")
#define ll unsigned long long
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const ll mxn=1e6+5;
ll num[mxn]={}, i, ans=0;

int main(){_
    ll n;
    cin>>n;
    for(i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        num[a]++;
        num[b]--;
    }
    for(i=1;i<mxn;i++){
        num[i]+=num[i-1];
        ans += (num[i]*(num[i]-1))/2;
    }
    cout<<ans;
}
