//https://cses.fi/problemset/task/1713/
#include<bits/stdc++.h>
using namespace std;
#define wh_ale ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ppb pop_back
#define phb push_back
#define int long long
#define F first
#define S second
#define pii pair<int, int>
vector<int> v;

void gen(){
    v.phb(2);
    bool t;
    for(int i=3;i<1000;i++){
        t=true;
        for(int j=0;j<v.size();j++){
            if(i%v[j]==0) t=false; 
        }
        if(t) v.phb(i);
    }
}
void run(int n){
	int cnt=1, i, j, cur, now;
	for(i=0;i<v.size();i++){
		if(n%v[i]==0){
			cur=v[i];
			now=1;
			while(n%cur==0){
				now++;
				cur*=v[i];
			}
			cnt *= now;
			n/=pow(v[i], now-1);
		}
	}
	if(n!=1) cnt*=2;
	cout << cnt << '\n';
}
signed main() {
    wh_ale;
    //freopen("mowing.in", "r", stdin);
    //freopen("mowing.out", "w", stdout);
    int n, x;
	gen();
	cin >> n;
	while(n--){
		cin >> x;
		run(x);
	}
    return 0;
}
