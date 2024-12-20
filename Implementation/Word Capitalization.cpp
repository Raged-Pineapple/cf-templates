#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

const int MOD=1e9+7;
const int INF=LLONG_MAX/2;

signed main() {
   ios::sync_with_stdio(false);cin.tie(NULL);
   string s;
   cin>>s;
   int val = 0;
   val = (int)s[0];
   if(val>97){
   	val-=32;
   }
   s[0] = (char)val;
   cout<<s<<endl;
}
