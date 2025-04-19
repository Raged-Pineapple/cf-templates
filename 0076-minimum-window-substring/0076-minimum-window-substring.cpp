class Solution {
public:
    static bool containsAll(const unordered_map<char, int>& smpp, const unordered_map<char, int>& tmpp) {
    for (auto& pair : tmpp) {
        char ch = pair.first;
        int required = pair.second;
        if (smpp.find(ch) == smpp.end() || smpp.at(ch) < required) {
            return false;
        }
    }
    return true;
}
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if (m > n) return "";
        unordered_map<char,int>tmpp;
        unordered_map<char,int>smpp;
        int l=0,r=0;
        for(auto it : t){
            tmpp[it]++;
        }
        int mini = INT_MAX,start=0;
        while(r<n){
            smpp[s[r]]++;
            while(containsAll(smpp,tmpp)){
                if (r - l + 1 < mini) {
                    mini = r - l + 1;
                    start = l;
                }
                smpp[s[l]]--;
                if (smpp[s[l]] == 0) {
                    smpp.erase(s[l]);
                }
                l++;
            }
            r++;
        }
     return mini == INT_MAX ? "" : s.substr(start, mini);   
    }
};