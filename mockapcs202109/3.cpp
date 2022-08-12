#include <bits/stdc++.h>
using namespace std;
#define Shaenno ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
int n;
int ans;
int k[300000];
ll mn, suml, sumr;
int mid;
void run(int l, int r){
	if(l==r) ans=k[l];
	else{
	mn=0x6f6f6f6f;
	suml=0;
	sumr=0;
	int i, j;
	for(i=l;i<=r;i++){
		if(mn>k[i]){
			mn=k[i];
			mid=i;
		}
	}
	for(i=l;i<mid;i++){
		suml+=k[i];
	}
	for(i=mid+1;i<r;i++){
		sumr+= k[i];
	}
	if(mid==l) run(l+1, r);
	else if(mid==r) run(l, r-1);
	else if(suml>sumr) run(l, mid-1);
	else run(mid+1, r);
	}
}
int main() {
	Shaenno;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> k[i];
	}
	run(0, n-1);
	cout << ans <<'\n';
	return 0;
}
