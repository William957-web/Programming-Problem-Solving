#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("O3,unroll-loops")
#define ll long long
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main(){_
    string s;
    cin>>s;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string t;
        cin>>t;
        string tmps="";
        string tmpt="";
        int ans=-1;
        for(int i=0;i<min(s.length(),t.length());i++){
            tmps=s[s.length()-i-1]+tmps;
            tmpt+=t[i];
            if(tmps==tmpt){
                ans=max(ans,min(i+1,(int)t.length()-i-1));
            }
        }
        cout<<ans<<'\n';
    }
}
