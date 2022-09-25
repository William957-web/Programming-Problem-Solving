#include<bits/stdc++.h>
using namespace std;
#define wh_ale ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define int long long
int n;
string s;
int cnt=0;
int b;
int l;
void run(int x, int y){
	if(x<l){ 
	if(s[x]=='1'){
	cnt += y*y;
	run(x+1, y);
    }
	else if(s[x]=='2'){
	run(x+1, y/2);
	}
	else run(x+1, y);
	} 
}
signed main(){
	wh_ale;
	cin >> s;
	cin >> n;
	l=s.size();
	run(0, n);
	cout << cnt <<'\n';
	return 0;
}
