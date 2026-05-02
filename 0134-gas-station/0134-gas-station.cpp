class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> gases, costs;
        gases = gas;
        costs = cost;
        for (int i = 0; i < n; i++) {
            gases.push_back(gas[i]);
            costs.push_back(cost[i]);
        }
        int m=gases.size();
        int i=0;
        while(i<n){
            int prev_idx=-1;
            int c=gases[i];
            if(c>=costs[i]){ 
              prev_idx=i;
            while(i<m-1 && c>=costs[i]){
               c=c-costs[i]+gases[i+1];
               i++;
            }
            if(i-prev_idx+1>n) return prev_idx;
            }
            i++;
        }
        return -1;
    }
};