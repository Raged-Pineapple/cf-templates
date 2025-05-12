//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
  bool check(string& s){
       if (s.empty() || s.size() > 3) return false;
        if (s.size() > 1 && s[0] == '0') return false;
        for (char c : s) {
            if (!isdigit(c)) return false;
        }
      int val = stoi(s);
      return (val >=0 && val <=255);
  }
    int isValid(string& s) {
        int n = s.size();
        int cnt=0;
        int i=0;
        vector<string>parts;
        string part = "";
        for(char c : s){
            if(c == '.'){
                parts.push_back(part);
                part="";
            }
            else{
                part+=c;
            }
        }
        parts.push_back(part);
        if(parts.size()!=4)return false;
        for(auto &p : parts){
            if(!check(p))return false;
        }
        return true;
    }
};


//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
