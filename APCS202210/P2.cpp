#include<bits/stdc++.h>
using namespace std;
#define wh_ale ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define INF 9999999
int main(){
	wh_ale;
	int r, c, n, i, j, ans, cnt=0;
	int a[37][57]={};
	int now[37]={};
	cin >> r >> c >> n;
	bool k;
	ans=r*c;
	char x;
	int t;
	while(n--){
		k=false;
		cin >> x >> t;
		if(x=='A'){
			i=max(max(now[t], now[t+1]), max(now[t+2], now[t+3])) ;
			if(i<c){
				for(j=0;j<4;j++){
					a[t+j][i]=1;
					now[t+j]=i+1;
				}
				k=true;
				ans-=4;
			}
		}
		else if(x=='B'){
			i=now[t];
		    if(i+2<c){
			    now[t]=i+3;
			    for(j=0;j<3;j++){
				a[t][j+i]=1;
			    }
			    k=true;
			    ans-=3;
		    }
		}
		else if(x=='C'){
			i=max(now[t], now[t+1]);
			if(i+1<c){
				a[t][i]=1;
				a[t][i+1]=1;
				a[t+1][i]=1;
				a[t+1][i+1]=1;
				now[t]=i+2;
				now[t+1]=i+2;
				k=true;
			    ans-=4;
			}
		}
		else if(x=='D'){
			for(i=max(now[t], now[t+1]);i<c;i++){
				if(a[t][i]==0 and a[t+1][i]==0 and a[t+1][i-1]==0 and a[t+1][i-2]==0){
				    a[t][i]=1;
				    a[t+1][i]=1;
				    a[t+1][i-1]=1;
				    a[t+1][i-2]=1;
				    now[t]=i+1;
				    now[t+1]=i+1;
				    k=true;
			        ans-=4;
			        break;
				}
			}
		}
		else if(x=='E'){
			for(i=max(max(now[t], now[t+1]), now[t+2]);i<c;i++){
				if(a[t][i]==0 and a[t+1][i]==0 and a[t+1][i-1]==0 and a[t+2][i]==0 and a[t+2][i-1]==0){
				    a[t][i]=1;
				    a[t+1][i]=1;
				    a[t+1][i-1]=1;
				    a[t+2][i]=1;
				    a[t+2][i-1]=1;
				    now[t]=i+1;
				    now[t+1]=i+1;
				    now[t+2]=i+1;
				    k=true;
			        ans-=5;
			        break;
				}
			}
		}
		if(k==false) cnt++;
	}
	cout << ans <<' '<<cnt <<'\n';
	return 0;
}
