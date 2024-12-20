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
   int n = s.size();
   
   // Using a set to track seen characters
   unordered_set<char> seenChars;
   int cnt=0;
   
   for(int i = 0; i < n; i++) {
      // If character is already in seenChars, we found a duplicate
      if(seenChars.find(s[i]) == seenChars.end()) {
         cnt++;
      }
      seenChars.insert(s[i]);
   }
   
   if(cnt%2 != 0) cout<<"IGNORE HIM!"<<endl;
   else cout<<"CHAT WITH HER!"<<endl;
}
