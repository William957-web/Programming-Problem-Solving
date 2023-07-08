#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k, i, j, x, l, r, max,cnt, rt, mn, an;
	vector<int> v;
	cin >> n >> k;
	for(i=0;i<n;i++){
		cin >> x;
		v.push_back(x);
	}
    sort(v.begin(), v.end());
    r=v[n-1]-v[0];
    rt=r/k+1;
    l=0;
    while(l<rt){
    	mn=(l+rt)/2;
    	cnt=0;
    	for(i=0;i<k;i++){
    		max=v[cnt]+mn;
    		for(j=cnt;j<n;j++){
    			if(v[j]<=max){
    				cnt++;
    			}
    			else break;
    		}
    	}
    	if(cnt==n){
    		rt=mn;
    		an=mn;
    	}
    	else l=mn+1;
    }
    cout << an <<endl;
	return 0;
}
