class Solution {
public:
    int minimumCost(vector<int>& cost) {
       int n=cost.size();
       sort(cost.begin(),cost.end());
       int cnt=0,res=0;
       for(int i=n-1;i>=0;i--){
        if(cnt==2){
            cnt=0;
            continue;
        }
        else{
            cnt++;
            res+=cost[i];
        }
       } 
       return res;
    }
};