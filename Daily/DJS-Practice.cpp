#include<bits/stdc++.h>
using namespace std;
#define int long long
#define wh_ale ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
int n, cnt=0;
int p[1000007], c[1000007];
int fp(int x){
	if(x != p[x]) return fp(p[x]);
	else return x;
}
signed main(){
	wh_ale;
    int m;
    cin >> n >> m;
    int x, y, i;
    for(i=1;i<=n;i++){
    	p[i]=i;
    	c[i]=1;
	}
	int cmd;
	while(m--){
		cin >> cmd;
		if(cmd==1){
			cin >> x >> y;
		if(c[fp(x)]<=c[fp(y)]){
			cnt += c[fp(x)]*c[fp(y)];
			c[fp(y)]=c[fp(x)]+c[fp(y)];
			p[fp(x)]=p[fp(y)];
		}
			else{
			cnt += c[fp(x)]*c[fp(y)];
			c[fp(x)]=c[fp(x)]+c[fp(y)];
		    p[fp(y)]=p[fp(x)];
		}
		}
		else if(cmd==2){
			cin >> x >> y;
			if(fp(x)==fp(y)) cout << "Yes\n";
			else cout << "No\n";
		}
		else if(cmd==3){
			cin >> x;
			cout << c[fp(x)] << "\n";
		}
		else{
			cout << cnt << "\n";
		}
	}
	return 0;
}
/*
4 6
1 1 2
2 1 2
3 1
1 1 3
2 2 3
4
*/
