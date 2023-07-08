#include<bits/stdc++.h>
using namespace std;
#define wh_ale ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define int long long
#define INF 1e18
#define pii pair<int, int>
#define psb push_back
vector<pii> g[100009];
int dis[100009];
int n, m, s, t;
pii r;
int pt;
int vis[100009]={};
priority_queue<pii, vector<pii>, greater<pii>> pq;
queue<int> q;
signed main(){
	wh_ale;
	cin >> n >> m;
	int i;
	for(i=1;i<=n;i++){
		dis[i]=INF;
	}
	int a, b, c;
	while(m--){
		cin >> a >> b >> c;
		g[a].psb({c, b});
	}
	cin >> s >> t;
	dis[s]=0;
	vis[s]=1;
	q.push(s);
	while(!q.empty()){
		for(i=0;i<g[q.front()].size();i++){
			if(dis[g[q.front()][i].second]>dis[q.front()]+g[q.front()][i].first){
			dis[g[q.front()][i].second]=dis[q.front()]+g[q.front()][i].first;
			pq.push({dis[g[q.front()][i].second], g[q.front()][i].second});
		}
		}
		q.pop();
		r=pq.top();
		while(vis[r.second]!=0 and pq.size() != 0){
			pq.pop();
			r=pq.top();
		}
		if(vis[r.second]==0)q.push(r.second);
		vis[r.second]=1;
		pq.pop();
	}
	if(dis[t]<INF) cout << dis[t] <<'\n';
	else cout << -1 <<'\n';
	return 0;
}
