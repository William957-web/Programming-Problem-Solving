# AtCoder Beginner Contest 308
### pA
```cpp
#include<bits/stdc++.h>
using namespace std;
#define wh_ale ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ppb pop_back
#define phb push_back
#define int long long
#define F first
#define S second
#define pii pair<int, int>
signed main() {
    wh_ale;
    //freopen("hps.in", "r", stdin);
    //freopen("hps.out", "w", stdout);
    int i, a[8];
    bool t=true;
    for(i=0;i<8;i++) cin >> a[i];
    for(i=0;i<8;i++)if(a[i]%25!=0) t=false;
    for(i=0;i<7;i++)if(a[i]>a[i+1]) t=false;
    for(i=0;i<7;i++)if(a[i]<100 or a[i]>675) t=false;
    if(t) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
```
### pB
```cpp
#include<bits/stdc++.h>
using namespace std;
#define wh_ale ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ppb pop_back
#define phb push_back
#define int long long
#define F first
#define S second
#define pii pair<int, int>
signed main() {
    wh_ale;
    //freopen("hps.in", "r", stdin);
    //freopen("hps.out", "w", stdout);
    int i, j, a[200], n, m, cnt=0, p[200];
    string s[200], x;
    map<string, int> mp;
    cin >> n >> m;
    for(i=1;i<=n;i++){
    	cin >> s[i];
    }
    for(i=1;i<=m;i++){
    	cin >> x;
    	mp[x]=i;
    }
    for(i=0;i<=m;i++){
    	cin >> p[i];
    }
    for(i=1;i<=n;i++){
    	if(mp.count(s[i])==0)cnt += p[0];
        else cnt += p[mp[s[i]]];
    }
    cout << cnt <<'\n';
    return 0;
}
```
### pC
```cpp
#include<bits/stdc++.h>
using namespace std;
#define wh_ale ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ppb pop_back
#define phb push_back
#define int long long
#define F first
#define S second
#define pii pair<int, int>
struct dat{int x, y, z;};
bool cmp(dat a, dat b){
    if(a.x*(b.x+b.y)!=b.x*(a.x+a.y))return a.x*(b.x+b.y)>b.x*(a.x+a.y);
    else return a.z<b.z;
}
signed main() {
    wh_ale;
    //freopen("hps.in", "r", stdin);
    //freopen("hps.out", "w", stdout);
    int i, j, n;
    cin >> n;
    dat a[300000];
    for(i=1;i<=n;i++){
        cin >> a[i].x >> a[i].y;
        a[i].z=i;
    }
    sort(a+1, a+n+1, cmp);
    cout << a[1].z;
    for(i=2;i<=n;i++){
        cout <<' '<< a[i].z;
    }
    cout << '\n';
    return 0;
}
```
### pE
```cpp
#include<bits/stdc++.h>
using namespace std;
#define wh_ale ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ppb pop_back
#define phb push_back
#define int long long
#define F first
#define S second
#define pii pair<int, int>
int mex(int a, int b, int c){
	bool t=false;
    for(int i=0;i<=2;i++){
        if(i!=a and i!=b and i!=c){
            return i;
            t=true;
            break;
        }
    }
    if(!t) return 3;
}
int mmex(int a, int b){
    for(int i=0;i<=2;i++){
        if(i!=a and i!=b){
            return i;
            break;
        }
    }
}
signed main() {
    wh_ale;
    //freopen("hps.in", "r", stdin);
    //freopen("hps.out", "w", stdout);
    int i, j, k, a[300000]={}, cnt=0, m[3]={}, e[30]={}, n;
    string s;
    cin >> n;
    for(i=0;i<n;i++){ 
        cin >> a[i];
    }
    cin >> s;
    for(i=0;i<n;i++){
        if(s[i]=='M'){
            m[a[i]]++;
        }
        else if(s[i]=='E'){
            for(j=0;j<=2;j++){
            	e[10*j+a[i]]+=m[j];
            }
        }
        else{
            for(j=0;j<3;j++){
                for(k=0;k<3;k++){
                	cnt += mex(j, k, a[i])*e[10*j+k];
                }
            }
        }
    }
    cout << cnt <<'\n';
    return 0;
}
```
