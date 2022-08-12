#include <bits/stdc++.h>
using namespace std;
#define Shaenno ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
struct node{
	int l, r, w;
	int x, y;
};
bool cmp(node a, node b){
	if(a.r != b.r) return a.r<b.r;
	else return a.l<b.l;
}
signed main() {
	Shaenno;
	int n, i, j, xl=-1, xr=-1, cnt=0;
	cin >> n;
	node m[200001];
	for(i=0;i<n;i++){
		cin >> m[i].l >> m[i].r >> m[i].w;
	}
	sort(m, m+n, cmp);
	for(i=0;i<n;i++){
		if(xr<m[i].l){
			xr=m[i].r;
			cnt++;
		}
	}
	cout << cnt <<'\n';
	return 0;
}
