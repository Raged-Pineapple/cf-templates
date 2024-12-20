#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

const int MOD=1e9+7;
const int INF=LLONG_MAX/2;

signed main() {
   ios::sync_with_stdio(false);cin.tie(NULL);
   int a;
   int b;
   cin>>a>>b;
   int cnt=0;
   int wa=a;
   int wb=b;
   while(wa<=wb){
   	wa*=3;
   	wb*=2;
   	cnt++;
   }
   cout<<cnt<<endl;
}
