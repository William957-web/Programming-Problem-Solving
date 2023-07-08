#include<bits/stdc++.h>
using namespace std;
#define wh_ale ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pis pair<int, string>
bool cmp(pair<int, string> x, pair<int, string> y){
	return x.second>=y.second;
}
int main(){
	vector<pis> s;
	int n;
	pair<int, string> x;
	cin >> n;
	int k=n;
	while(n--){
		s.clear();
		int i;
		for(i=0;i<10;i++){
			cin >> x.first >> x.second;
		}
		sort(s.begin(), s.end(), cmp);
		int idx=0;
		bool tt=true;
		cout << "Case "<< "#" << k-n <<":\n";
		while(tt){
			if(s[idx].second==s[0].second) cout << s[idx].first <<"\n";
			idx++;
		}
	} 
	
	return 0;
}
