#include<bits/stdc++.h>
using namespace std;
#define wh_ale ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ppb pop_back
#define phb push_back
#define F first4
#define int long long
#define S second
#pragma gcc optimize("O3")
vector<int> v;
void run(){
    v.phb(2);
    bool t;
    for(int i=3;i<100000;i++){
            t=true;
        for(int j=0;j<v.size();j++){
            if(i%v[j]==0){
                t=false;
                break;
            }
        }
        if(t) v.phb(i);
    }
}
signed main(){
	wh_ale;
	int n, i, j, cnt=0, x, p=1, a[100005]={};
	queue<int> q;
	run();
	cin >> n;
	for(i=0;i<v.size();i++){
        if(n%v[i]==0){
            q.push(v[i]);
        }
	}
	for(i=1;i<n;i++){
        a[i]=1;
        cnt++;
        for(j=0;j<q.size();j++){
            x=q.front();
            q.pop();
            q.push(x);
            if(i%x==0){
                a[i]=0;
                cnt--;
                break;
            }
        }
	}
	for(i=1;i<n;i++){
        if(a[i]==1){
            x=i%n;
            if(x<0) x=x+n;
            p=(p*x);
            p%=n;
            if(p<0) p=p+n;
            //cout <<i<<':'<<p <<'\n';
        }
	}
	//cout << p <<'\n';
    if(p==1){
        cout << cnt <<'\n';
        cout << 1;
        for(i=2;i<n;i++){
            if(a[i]==1) cout <<' '<<i;
        }
        cout << '\n';
	}
	else{
        a[p]=0;
        cout << cnt-1 <<'\n';
        cout << 1;
        for(i=2;i<n;i++){
            if(a[i]==1) cout << ' '<<i;
        }
        cout << '\n';
    }
	return 0;
}
