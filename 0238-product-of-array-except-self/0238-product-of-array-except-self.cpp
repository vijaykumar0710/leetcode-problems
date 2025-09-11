class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n,0);

        int zero_cnt=count(nums.begin(),nums.end(),0);
        if(zero_cnt>1) return res;

        int zero_idx=find(nums.begin(),nums.end(),0)-nums.begin();
        long long pre_pro=1,suf_pro=1;
        
        if(zero_cnt==1){ 
        for(int i=0;i<zero_idx;i++) pre_pro*=nums[i];
        for(int i=zero_idx+1;i<n;i++) suf_pro*=nums[i];
        res[zero_idx]=pre_pro*suf_pro; 
        return res;
        }

        if(zero_cnt==0){ 
        long long suff_pro=1;
        for(int i=0;i<n;i++) suff_pro*=nums[i];
        for(int i=0;i<n;i++) res[i]=suff_pro/nums[i];
        }
        return res;
    }
};