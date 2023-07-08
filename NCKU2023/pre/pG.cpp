#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define pb push_back
const int sz=2e5+5;
map<int,pii>input;
map<pii,int>mp;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m,k,q;
    cin>>n>>m>>k>>q;
    for(int i=0;i<k;i++){
        int x,y,key;
        cin>>key>>x>>y;
        input[key]={x,y};
        mp[{x,y}]=key;
    }for(int i=0;i<q;i++){
        int a,b,c;
        cin>>a>>b>>c;
        if(a==b or b==c or a==c){
            cout<<"Not ghost key condition!\n";
            continue;
        }
        int x1=input[a].F;
        int y1=input[a].S;
        int x2=input[b].F;
        int y2=input[b].S;
        int x3=input[c].F;
        int y3=input[c].S;
        if(x1==x2 and y2==y3){
            if(mp[{x3,y1}]){
                cout<<"Find ghosy key: "<<mp[{x3,y1}]<<'\n';
            }else{
                cout<<"Not ghost key condition!\n";
            }
        }else if(x1==x2 and y1==y3){
            if(mp[{x3,y2}]){
                cout<<"Find ghosy key: "<<mp[{x3,y2}]<<'\n';
            }else{
                cout<<"Not ghost key condition!\n";
            }
        }else if(x1==x3 and y2==y1){
            if(mp[{x2,y3}]){
                cout<<"Find ghosy key: "<<mp[{x2,y3}]<<'\n';
            }else{
                cout<<"Not ghost key condition!\n";
            }
        }else if(x1==x3 and y2==y3){
            if(mp[{x2,y1}]){
                cout<<"Find ghosy key: "<<mp[{x2,y1}]<<'\n';
            }else{
                cout<<"Not ghost key condition!\n";
            }
        }else if(x2==x3 and y1==y2){
            if(mp[{x1,y3}]){
                cout<<"Find ghosy key: "<<mp[{x1,y3}]<<'\n';
            }else{
                cout<<"Not ghost key condition!\n";
            }
        }else if(x2==x3 and y1==y3){
            if(mp[{x1,y2}]){
                cout<<"Find ghosy key: "<<mp[{x1,y2}]<<'\n';
            }else{
                cout<<"Not ghost key condition!\n";
            }
        }else cout<<"Not ghost key condition!\n";
    }
}
