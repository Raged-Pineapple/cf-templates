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
   if (s[0] >= 'a' && s[0] <= 'z') {
      s[0] -= 32;
   }
   cout<<s<<endl;
}
