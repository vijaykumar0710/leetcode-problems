class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n=cost.size(),res=0;
        if(n==1) return cost[0];
        sort(cost.rbegin(),cost.rend());
        for(int i=0;i<n;i+=3){
            if(i<n) res+=cost[i];
            if(i+1<n) res+=cost[i+1];
        }
        return res;
    }
};