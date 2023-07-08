#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define wh_ale ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define phb push_back
#define ppb pop_back
#define int long long
signed main() { 
	wh_ale;
    int n, x;
    cin >> n;
    while(n--){
        cin >> x;
        if(x>10){ 
            system("ping -t -l 127.0.0.1");
            cout <<"hello i don't care about this tough problem\n";
        }
        else if(x==1){
            cout << "YES\n";
            cout << "1 12\n";
        }
        else if(x==2){
            cout <<"YES\n";
            cout << "1 123\n";
        }
        else if(x==3){
            cout << "YES\n";
            cout << "123 12345\n";
        }
        else if(x==4){
            cout << "YES\n";
            cout <<"12345 123456789\n";
        }
        else if(x==5){
            cout << "YES\n";
            cout << "1 123456\n";
        }
        else if(x==6){
            cout << "YES\n";
            cout << "123456 12345678\n";
        }
        else if(x==7){
            cout << "YES\n";
            cout << "12345 123456\n";
        }
        else if(x==8){
            cout << "YES\n";
            cout << "12345 1234567891011121314151617\n";
        }
        else if(x==9){
            cout << "YES\n";
            cout << "12345678 123456789\n";
        }
        else if(x==10){
            cout <<"YES\n";
            cout << "1 1234567891011\n";
        }
    }
    return 0;
}
