class Solution {
public:
    int minimumCost(vector<int>& cost) {
       int n=cost.size();
       sort(cost.rbegin(),cost.rend());
       int res=0;
       for(int i=0;i<n;i+=3){
        res+=cost[i];
        if(i+1<n) res+=cost[i+1];
       } 
       return res;
    }
};