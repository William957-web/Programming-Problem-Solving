#include <bits/stdc++.h>
using namespace std;
#define Shaenno ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
int main() {
	Shaenno;
	int n, a[7][2], i, j;
	char s[3]={'A', 'B', 'C'};
	cin >> n;
	while(n--){
		int k[3]={};
		bool tt=false;
		for(i=0;i<3;i++){
			k[i]=0;
		}
		for(i=0;i<2;i++){
			for(j=0;j<7;j++){
				cin >> a[j][i];
			}
		}
		for(i=0;i<=2;i++){
			if(i==0){
				for(j=0;j<2;j++){
					if(a[1][j]==a[3][j] or a[1][j] != a[5][j]) k[i]=1;
				}
			}
			else if(i==1){
				if(a[6][0]!= 1 or a[6][1] != 0) k[i]=1;
			}
			else{
				for(j=1;j<=3;j++){
					if(a[2*j-1][0]==a[2*j-1][1]) k[i] = 1;
				}
			}
		}
		for(i=0;i<3;i++){
			if(k[i]==1){
				cout << s[i];
				tt=true;
			}
		}
		if(tt==false) cout << "None";
		cout << '\n';
	}
	return 0;
}
