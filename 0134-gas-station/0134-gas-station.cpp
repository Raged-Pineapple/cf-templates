class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totGas=0,totCost=0;
        for(auto it : gas){
            totGas+=it;
        }
        for(auto it : cost){
            totCost+=it;
        }
        if(totGas<totCost)return -1;
        int start=0,curr=0;
        for(int i=0;i<gas.size();i++){
            curr += gas[i] - cost[i];
            if(curr < 0){
                start = i+1;
                curr=0;
            }
        }
        return start;
    }
};