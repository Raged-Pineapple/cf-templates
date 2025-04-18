class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        for(int i=0;i<n;i++){
            int diff = target-numbers[i];
            int l = i+1,r=n-1;
            while(l<=r){
                int mid = (l+r)/2;
                if(diff == numbers[mid])return{i+1,mid+1};
                if(diff>numbers[mid]){
                    l = mid+1;
                }
                else r = mid-1;
            }
        }
        return {-1,-1};
    }
};