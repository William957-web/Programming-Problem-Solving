#include<bits/stdc++.h>
using namespace std;
#define wh_ale ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define int long long
#define phb push_back
#define ppb pop_back
int p[1000000], l[1000000]={}, vis[1000000]={};
int findp(int x){
	if(x != p[x]) return findp(p[x]);
	else return x;
}
bool chk(int x, int y){
	if(findp(x)==findp(y))return true;
	else return false;
}
struct node{
	int a, b, c;
};
vector<node> g;
bool cmp(node x, node y){
	return x.b<y.b;
}
int n, m;
int cnt=0, ans=0;
signed main(){
	wh_ale;
	node k;
	int nowa, nowb;
	cin >> n >> m;
	int i, j;
	for(i=1;i<=n;i++) p[i]=i;
	for(i=0;i<m;i++){
		cin >> k.a >> k.c >> k.b;
		g.phb(k);
	}
	sort(g.begin(), g.end(), cmp);
	for(i=0;i<m;i++){
		nowa=findp(g[i].a);
		nowb=findp(g[i].c);
		if(nowa != nowb){
		if(l[nowa]<l[nowb]){
			p[nowa]=nowb;
		}
		else p[nowb]=nowa;
		ans += g[i].b;
		if(vis[g[i].a]==0){
			n--;
			vis[g[i].a]=1;
		}
		else if(vis[g[i].c]==0){
			n--;
			vis[g[i].c]=1;
		}
		if(n==0) break;
		}
	}
	cout << ans <<'\n';
return 0;
}
