#include<bits/stdc++.h>
using namespace std;
#define wh_ale ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define INF 9999999
int per(int x){
	if(x<0)return x*-1;
	else return x;
}
int dis(int x1, int y1, int x2, int y2){
	return per(x1-x2)+per(y1-y2);
}
int main(){
	wh_ale;
	int n, i, j, mn=INF, mx=-1, a[1000][2];
	cin >> n;
	for(i=0;i<n;i++){
		cin >> a[i][0] >> a[i][1];
	}
	int now;
	for(i=1;i<n;i++){
		now=dis(a[i][0], a[i][1], a[i-1][0], a[i-1][1]);
		mn=min(now, mn);
		mx=max(now, mx);
	}
	cout << mx << ' ' << mn <<'\n';
	return 0;
}
