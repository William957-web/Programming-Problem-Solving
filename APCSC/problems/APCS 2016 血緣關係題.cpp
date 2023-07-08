#include <bits/stdc++.h>
using namespace std;
#define Shaenno ios::sync_with_stdio(0);cin.tie(0)
int n, cnt[100000];
vector<int> v[100000];
void dfs(int nd, int x){
	for(int i=0;i<v[nd].size();i++){
		if(cnt[v[nd][i]]==0){
			cnt[v[nd][i]]=x+1;
			dfs(v[nd][i], x+1);
		}
	}
}
int main() {
	Shaenno;
	int a, b, i, j, mx, mxn;
	while(cin >> n){
		mx=0;
		for(i=0;i<n-1;i++){
			cin>> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		for(i=0;i<n;i++){
			cnt[i]=0;
		}
		cnt[0]=1;
		dfs(0, 1);
		for(i=0;i<n;i++){
			if(mx<cnt[i]){
				mx=cnt[i];
				mxn=i;
			}
		}
		for(i=0;i<n;i++){
			cnt[i]=0;
		}
		cnt[mxn]=1;
		dfs(mxn, 1);
		for(i=0;i<n;i++){
			if(mx<cnt[i]){
				mx=cnt[i];
			}
		}

		cout << mx-1<<'\n';
		for(i=0;i<n;i++){
			cnt[i]=0;
			while(v[i].size()!=0){
				v[i].pop_back();
			}
		}
	}
	return 0;
}
