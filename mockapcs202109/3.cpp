#include <bits/stdc++.h>
using namespace std;
#define Shaenno ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
int n;
int ans;
int k[300001], dp[300001];
ll mn;
int mid;
void run(int l, int r){
	if(l==r) ans=k[l];
	else{
	mn=0x6f6f6f6f;
	int i, j;
	for(i=l;i<=r;i++){
		if(mn>k[i]){
			mn=k[i];
			mid=i;
		}
	}
	if(mid==l) run(l+1, r);
	else if(mid==r) run(l, r-1);
	else if(dp[mid-1]-dp[l-1]>dp[r]-dp[mid]) run(l, mid-1);
	else run(mid+1, r);
	}
}
int main() {
	Shaenno;
	cin >> n;
	dp[0]=0;
	k[0]=0;
	for(int i=1;i<=n;i++){
		cin >> k[i];
		dp[i]=k[i]+dp[i-1];
	}
	run(1, n);
	cout << ans <<'\n';
	return 0;
}
