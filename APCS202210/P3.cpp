#include<bits/stdc++.h>
using namespace std;
#define wh_ale ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define INF 9999999
#define int long long
#define phb push_back
int n, cnt=0, st;
vector<int> g[200001];
int per(int x){
	if(x<0)return x*-1;
	else return x;
}
void dfs(int x){
	int i;
	for(i=0;i<g[x].size();i++){
		cnt += per(g[x][i]-x);
		dfs(g[x][i]);
	}
}
void read(int x){
	int k, i;
	if(x%2==0){
		for(i=0;i<2;i++){
			cin >> k;
			if(k != 0){
				g[x].phb(k);
				read(k);
			}
		}
	}
	else {
		for(i=0;i<3;i++){
			cin >> k;
			if(k != 0){
				g[x].phb(k);
				read(k);
			}
		}
	}
}
signed main(){
	wh_ale;
	cin >> st;
	read(st);
	dfs(st);
	cout << cnt <<'\n';
	return 0;
}
