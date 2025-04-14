void processSubarrays(vector<int>& arr, int k) {
    int n = arr.size();
    
    for (int len = k; len <= n; ++len) {          // subarray sizes from k to n
        for (int start = 0; start <= n - len; ++start) {
            int end = start + len - 1;
            
            // Process subarray arr[start ... end]
            // Example: print it
            for (int i = start; i <= end; ++i)
                cout << arr[i] << " ";
            cout << "\n";
        }
    }
}
