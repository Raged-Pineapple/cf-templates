//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    private:
    vector<int> topologicalSort(int V, vector<vector<int> >& adj)
{
    vector<int> indegree(V);
    for (int i = 0; i < V; i++) {
        for (auto it : adj[i]) {
            indegree[it]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    vector<int> result;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);
        for (auto it : adj[node]) {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }
    if (result.size() != V) {
        return {};
    }

    return result;
}
  public:
    string findOrder(vector<string> &words) {
        vector<vector<int>> adj(26);
        unordered_set<char> st;
        
        // Collect all unique characters
        for (auto& word : words) {
            for (char ch : word) {
                st.insert(ch);
            }
        }

        int n = words.size(); // Corrected here
        for (int i = 0; i < n - 1; i++) {
            string word1 = words[i];
            string word2 = words[i + 1];
            int len = min(word1.size(), word2.size());
            bool found = false;
            for (int j = 0; j < len; j++) {
                if (word1[j] != word2[j]) {
                    adj[word1[j] - 'a'].push_back(word2[j] - 'a');
                    found = true;
                    break;
                }
            }
            // Important case: ["abc", "ab"] is invalid
            if (!found && word1.size() > word2.size()) {
                return "";
            }
        }

        vector<int> topo = topologicalSort(26, adj); // Corrected here

        if (topo.empty()) {
            return ""; // Cycle detected
        }

        string ans = "";
        for (auto it : topo) {
            char ch = (it + 'a');
            if (st.find(ch) != st.end()) { // Only add if it actually appeared
                ans += ch;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

bool validate(const vector<string> &original, const string &order) {
    unordered_map<char, int> mp;
    for (const string &word : original) {
        for (const char &ch : word) {
            mp[ch] = 1;
        }
    }
    for (const char &ch : order) {
        if (mp.find(ch) == mp.end())
            return false;
        mp.erase(ch);
    }
    if (!mp.empty())
        return false;

    for (int i = 0; i < order.size(); i++) {
        mp[order[i]] = i;
    }

    for (int i = 0; i < original.size() - 1; i++) {
        const string &a = original[i];
        const string &b = original[i + 1];
        int k = 0, n = a.size(), m = b.size();
        while (k < n and k < m and a[k] == b[k]) {
            k++;
        }
        if (k < n and k < m and mp[a[k]] > mp[b[k]]) {
            return false;
        }
        if (k != n and k == m) {
            return false;
        }
    }
    return true;
}

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        string curr;
        vector<string> words;
        while (ss >> curr)
            words.push_back(curr);

        vector<string> original = words;

        Solution ob;
        string order = ob.findOrder(words);

        if (order.empty()) {
            cout << "\"\"" << endl;
        } else {
            cout << (validate(original, order) ? "true" : "false") << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
