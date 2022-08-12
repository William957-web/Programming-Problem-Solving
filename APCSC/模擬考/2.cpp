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
	int n, m, q, k, x, y, r, cnt=0, i, j;
	int dx[8]={-1, -1, -1, 0, 0, 1, 1, 1};
	int dy[8]={-1, 0, 1, -1, 1, -1, 0, 1};
	vector<pii> d[51];
	int g[51][51];
	cin >> n >> m >> q;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			cin >> g[i][j];
		}
	}
	for(i=1;i<=q;i++){
		cin >> k;
		if(k != 0){
		for(j=0;j<k;j++){
			cin >> x >> y;
			d[i].pb({x, y});
		}
		}
	}
	for(i=1;i<=q;i++){
		for(j=0;j<d[i].size();j++){
			if(g[d[i][j].F][d[i][j].S]<=i){
				for(r=0;r<8;r++){
					if(0<d[i][j].F+dx[r] and d[i][j].F+dx[r]<=n and 0<d[i][j].S+dy[r] and d[i][j].S+dy[r]<=m){
						if(g[d[i][j].F+dx[r]][d[i][j].S+dy[r]]<= i) g[d[i][j].F+dx[r]][d[i][j].S+dy[r]]= i+3;
					}
				}
			}
			g[d[i][j].F][d[i][j].S]=i+5;
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(g[i][j]<=q+1) cnt++;
			
		}
	}
	cout << cnt <<'\n';
	return 0;
}
