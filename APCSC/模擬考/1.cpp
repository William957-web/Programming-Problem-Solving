#include <bits/stdc++.h>
using namespace std;
#define Shaenno ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
int main() {
	Shaenno;
	int n, x, i, j, cnt=0, now=0;
	int a[100], b[101];
	cin >> n >> x;
	for(i=0;i<n;i++){
		cin >> a[i];
	}
	b[0]=x;
	for(i=0;i<n;i++){
		now += b[i];
		if(a[i]<=now){
			cnt += a[i];
			now -= a[i];
			b[i+1]=max(b[i]-1, 0);
		}
		else{
			cnt += now;
			now=0;
			b[i+1]=b[i]+1;
		}
	}
	cout << cnt << ' ' << now<<'\n';
	return 0;
}
