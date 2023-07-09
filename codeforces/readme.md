# Codeforces Writeups
[Whale120](https://codeforces.com/profile/Whale120)  
## 小標題們
[Codeforces Round 883 (Div. 3)](#Codeforces Round 883 (Div. 3))   
### Codeforces Round 883 (Div. 3)
**小記：**晚上打比賽真的有點累...pD的簡單國小幾何因為搞錯c++ double範圍做好久，還好前面和pE打夠快，rating有上升。  
performance:1521, rating change:+82  
#### pA
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
void run(){
    int n, x, y, cnt=0;
    cin >> n;
    for(int i=0;i<n;i++){
            cin >> x >> y;
    if(x-y>0) cnt++;
    }
    cout <<cnt <<'\n';
}
signed main(){
  wh_ale;
  int t;
  cin >> t;
  while(t--){
    run();
  }
  return 0;
}

```
#### pB
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
void run(){
    int a[3][3]={}, i, j, result=0;
    char c;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            cin >> c;
            if(c=='X') a[i][j]=1;
            else if(c=='O') a[i][j]=2;
            else if(c=='+') a[i][j]=3;
        }
    }
    for(i=0;i<3;i++){
        if(a[i][0]==a[i][1] and a[i][1]== a[i][2] and a[i][0]!=0){
            result=a[i][0];
        }
    }
    for(i=0;i<3;i++){
        if(a[0][i]==a[1][i] and a[2][i]== a[1][i] and a[0][i]!=0){
            result=a[0][i];
        }
    }
    if(a[0][0]==a[1][1] and a[2][2]== a[1][1] and a[0][0]!=0){
            result=a[0][0];
    }
    if(a[0][2]==a[1][1] and a[2][0]== a[1][1] and a[2][0]!=0){
            result=a[2][0];
    }
    if(result==0) cout << "DRAW\n";
    else if(result==1) cout << "X\n";
    else if(result==2) cout << "O\n";
    else if(result==3) cout << "+\n";
}
signed main() {
  wh_ale;
  int t;
  cin >> t;
  while(t--){
    run();
  }
  return 0;
}

```
#### pC
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
struct dat{
int xx, xy, xz;
};
bool cmp(dat a, dat b){
    if(a.xx!=b.xx) return a.xx>b.xx;
    else if(a.xy!=b.xy) return a.xy<b.xy;
    else if(a.xz!=b.xz) return a.xz<b.xz;
}
void run(){
    int n, m, h, i, j, x, a[250000]={}, t[250000]={}, p[250000]={};
    vector<int> v;
    bool tt;
    dat c[250000];
    cin >> n >> m >> h;
    for(i=1;i<=n;i++){
    	tt=false;
        v.clear();
        for(j=0;j<m;j++){
            cin >> x;
            v.phb(x);
        }
        sort(v.begin(), v.end());
        for(j=0;j<v.size();j++){
            if(t[i]+v[j]<=h){
                t[i]+=v[j];
                p[i]+=t[i];
                a[i]++;
            }
            else{
            c[i].xx=a[i];
            c[i].xy=p[i];
            c[i].xz=i;
            tt=true;
            break;
            }
        }
        if(!tt){
        	c[i].xx=a[i];
            c[i].xy=p[i];
            c[i].xz=i;
        }
    }
    sort(c+1, c+n+1, cmp);
    for(i=1;i<=n;i++){
        if(c[i].xz==1){
            cout << i <<'\n';
            break;
        }
        //cout << c[i].xz<<' ';
    }
}
signed main() {
  wh_ale;
  int t;
  cin >> t;
  while(t--){
    run();
  }
  return 0;
}

```
#### pD
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
void run(){
    int n, d, h, i, j, a[250000];
    cin >> n >> d >> h;
    long double dd=0, c=0, f=0, k=0;
    for(i=1;i<=n;i++){
        cin >> a[i];
    }
    for(i=1;i<=n-1;i++){
        if(a[i+1]-a[i]<h){
            f=f+(h-a[i+1]+a[i])*(h-a[i+1]+a[i]);
        }
    }
    cout <<std::setprecision(100)<<n*h*d*0.5-h*d*0.5*(f/(h*h))<<'\n';
}
signed main() {
  wh_ale;
  int t;
  cin >> t;
  while(t--){
    run();
  }
  return 0;
}

```
#### pE
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
void run(int n){
    cin >> n;
    int i, j, cnt;
    n--;
    bool t=false;
    for(i=2;i<=sqrt(n);i++){
    	if(t) break;
    	t=false;
    	cnt=i;
    	for(j=2;j<=40;j++){
    		cnt+=pow(i, j);
    		if(cnt==n){
    			t=true;
    			break;
    		}
    		else if(cnt>n) break;
    	}
    }
    if(t) cout << "YES\n";
    else cout << "NO\n";
}
signed main() {
  wh_ale;
  int t, n;
  cin >> t;
  while(t--){
    run(n);
  }
  return 0;
}

```
