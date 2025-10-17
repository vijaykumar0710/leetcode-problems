class Solution {
public:
int N,n;
int t[8][1<<14];
int f(int idx,int mask,vector<int>&nums){
    if(idx>n) return 0;
    if(t[idx][mask]!=-1) return t[idx][mask];
        int ans=INT_MIN;
        for(int j=0;j<N;j++){
            if(mask&(1<<j)) continue;
            for(int k=j+1;k<N;k++){
                if(mask&(1<<k)) continue;
                int new_mask=mask|(1<<j);
                new_mask=new_mask|(1<<k);
                int temp=(idx*gcd(nums[j],nums[k]))+f(idx+1,new_mask,nums);
                ans=max(ans,temp);
           }
    }
    return t[idx][mask]=ans;
}
    int maxScore(vector<int>& nums) {
        N=nums.size();
        n=N/2;
        memset(t,-1,sizeof(t));
        return f(1,0,nums);
    }
};