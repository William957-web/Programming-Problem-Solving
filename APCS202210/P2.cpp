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
			for(i=max({now[t], now[t+1], now[t+2], now[t+3]});i<c;i++){
				if(a[t][i]==0 and a[t+1][i]==0 and a[t+2][i]==0 and a[t+3][i]==0){
				    a[t][i]=1;
				    a[t+1][i]=1;
				    a[t+2][i]=1;
				    a[t+3][i]=1;
				    for(j=0;j<4;j++){
				        now[t+j]=i+1;
				    }
				    k=true;
			        ans-=4;
			        break;
				}
			}
		}
		else if(x=='B'){
			for(i=max(now[t], 2);i<c;i++){
				if(a[t][i]==0 and a[t][i-1]==0 and a[t][i-2]==0){
				    a[t][i]=1;
				    a[t][i-2]=1;
				    a[t][i-1]=1;
				    now[t]=i+1;
				    k=true;
			        ans-=3;
			        break;
				}
			}
		}
		else if(x=='C'){
			for(i=max({now[t], now[t+1], 1});i<c;i++){
				if(a[t][i]==0 and a[t+1][i]==0 and a[t+1][i-1]==0 and a[t][i-1]==0){
				    a[t][i]=1;
				    a[t+1][i]=1;
				    a[t+1][i-1]=1;
				    a[t][i-1]=1;
				    now[t]=i+1;
				    now[t+1]=i+1;
				    k=true;
			        ans-=4;
			        break;
				}
			}
		}
		else if(x=='D'){
			for(i=max({now[t], now[t+1], 2});i<c;i++){
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
			for(i=max({1, now[t+1], now[t], now[t+2]});i<c;i++){
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
//
