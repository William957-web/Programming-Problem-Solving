#include <bits/stdc++.h>
using namespace std;
#define Shaenno ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
signed main() {
	Shaenno;
	int n, m, i, j, x, y, z, dd, c[200001]={}, cc[200001]={}, ans=0;
	int tt[200001]={};
	vector<int> g[200001];
	int h[200001]={};
	queue<int> q;
	cin >> n >> m;
	for(i=0;i<n-1;i++){
		cin >> x >> y;
		g[x].pb(y);
		g[y].pb(x);
	}
	for(i=0;i<m;i++){
		cin >> h[i];
		tt[h[i]]=1;
	}
	for(i=0;i<m;i++){
		q.push(h[i]);
		for(j=1;j<=n;j++){
			cc[j]=0;
		}
		while(!q.empty()){
			z=q.front();
			q.pop();
			for(j=0;j<g[z].size();j++){
				if(cc[g[z][j]]==0 and g[z][j] != h[i]){
					  cc[g[z][j]]=cc[z]+1;
					  q.push(g[z][j]);
				}
			}
		}
		for(j=1;j<=n;j++){
			if(c[j]==0 and tt[j] != 1) c[j]=cc[j];
			else c[j]=min(c[j], cc[j]);
		}
	}
	for(i=1;i<=n;i++){
		ans += c[i];
	}
	cout << ans <<'\n';
	return 0;
}
