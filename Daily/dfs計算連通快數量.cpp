#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define wh_ale ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
int n, m, bn, cnt=0;
int c[100001]={};
vector<int> g[100001];
void dfs(int x, int d){
	for(int i=0;i<g[x].size();i++){
		if(c[g[x][i]]==0 and g[x][i]!=bn){
			c[g[x][i]]=i+1;
			dfs(g[x][i], d+1);
		}
	}
}
int main(){
	wh_ale;
	int x, y, i;
	cin >> n >> m;
	while(m--){
		cin >> x >> y;
		g[x].pb(y);
		g[y].pb(x);
	}
	for(i=1;i<=n;i++){
		if(c[i]==0){
			bn=i;
			dfs(i, 0);
			cnt++;
		}
	}
	cout << cnt-1 <<'\n';
}
