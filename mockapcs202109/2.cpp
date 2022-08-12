#include <bits/stdc++.h>
using namespace std;
#define Shaenno ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
int main() {
	Shaenno;
	int b[100][100]={};
	int kx[500], ky[500];
	int i, j, n, m, t, cnt=0;
	int al[500]={};//0代表還活著
	int mm;
	int l[500], r[500];
	vector<pair<int,int>> v; 
	cin >> n >> m >> t;
	mm=t;
	for(i=0;i<t;i++){
		cin >> kx[i] >> ky[i] >> l[i] >> r[i];
	}
	while(mm != 0){
		v.clear();
		for(i=0;i<t;i++){
			if(al[i]==0){
			if(0<=kx[i]+l[i] and kx[i]+l[i]<n and 0<=ky[i]+r[i] and ky[i]+r[i]<m){
			
				b[kx[i]][ky[i]]=1;
				kx[i]=kx[i]+l[i];
			    ky[i]=ky[i]+r[i];
				if(b[kx[i]][ky[i]]!=0){
					al[i]=1;
					mm--;
					v.push_back({kx[i], ky[i]});
				}
			}
			else{
			 mm--;
			 b[kx[i]][ky[i]]=1;
			 al[i]=1;
			}
			
			}
		}
		for(i=0;i<v.size();i++){
			b[v[i].first][v[i].second]=0;
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(b[i][j]==1) cnt++;
		}
	}
	cout << cnt <<'\n';
	return 0;
}
