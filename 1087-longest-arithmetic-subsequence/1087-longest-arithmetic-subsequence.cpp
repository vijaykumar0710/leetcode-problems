class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>t(n,vector<int>(1001,0));
        int diff=nums[1]-nums[0];
        t[1][diff+500]=2;
        int res=2;
        for(int i=2;i<n;i++){
            for(int j=0;j<i;j++){
               int diff=nums[i]-nums[j];
               if(t[j][diff+500]>0){
                t[i][diff+500]=max(t[i][diff+500],t[j][diff+500]+1);
               }else t[i][diff+500]=2;
               res=max(res,t[i][diff+500]);
            }
        }
        return res;
    }
};