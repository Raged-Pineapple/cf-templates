class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        long long S = (1LL * n * n * (n * n + 1)) / 2;  
        long long Sq = (1LL * n * n * (n * n + 1) * (2LL * n * n + 1)) / 6;  

        long long actualSum = 0, actualSqSum = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                actualSum += grid[i][j];
                actualSqSum += 1LL * grid[i][j] * grid[i][j];  // Ensure long long multiplication
            }
        }

        long long diff1 = actualSum - S;  // (Repeated - Missing)
        long long diff2 = actualSqSum - Sq;  // (Repeated² - Missing²)

        long long sum = diff2 / diff1;  // (Repeated + Missing)

        int repeated = (sum + diff1) / 2;
        int missing = (sum - diff1) / 2;

        return {repeated, missing};
    }
};
