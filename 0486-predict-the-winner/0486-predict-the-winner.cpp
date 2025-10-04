class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        int total=accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>> t(n,vector<int>(n, 0));
        for(int g=0;g<n;g++){
            for(int i=0,j=g;j<n;i++,j++){
                if(g==0) t[i][j]=nums[i];
                else if(g==1) t[i][j]=max(nums[i],nums[j]);
                else{
                    int val1=nums[i]+min(t[i+2][j],t[i+1][j-1]);
                    int val2=nums[j]+min(t[i][j-2],t[i+1][j-1]);
                    t[i][j]=max(val1,val2);
                }
            }
        }
        int p1=t[0][n-1];
        int p2=total-t[0][n-1];
        return p1>=p2;
    }
};