#include <bits/stdc++.h>
using namespace std;
#define Shaenno ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define int long long
signed main() {
	Shaenno;
	int i, j, n, sum=0, ans, k;
	int a[1000], dp[50000001]={};
	vector<int> v;
	cin >> n;
	for(i=0;i<n;i++){
		cin >> a[i];
		sum += a[i];
	}
  //經典dp枚舉
	for(i=0;i<n;i++){
		for(j=sum;j>=a[i];j--){
			dp[j]=max(dp[j], dp[j-a[i]]+a[i]);
		}
	}
  //the end
	k=sum/2;
	for(i=0;i<=sum;i++){
		if(dp[i]==i and i>= k){
			k=i;
			break;
		}
	}
	
	ans=k*k+(sum-k)*(sum-k);
	cout << ans << '\n';
	return 0;
}
