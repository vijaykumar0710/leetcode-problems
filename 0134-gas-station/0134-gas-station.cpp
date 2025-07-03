class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int total_gas=accumulate(gas.begin(),gas.end(),0);
        int total_cost=accumulate(cost.begin(),cost.end(),0);
        if(total_gas<total_cost) return -1;
        int start_idx=0;
        int tank=0;
        for(int i=0;i<n;i++){
            int gain=gas[i]-cost[i];
            tank+=gain;
            if(tank<0){
                start_idx=i+1;
                tank=0;
            }
        }
        return start_idx;
    }
};