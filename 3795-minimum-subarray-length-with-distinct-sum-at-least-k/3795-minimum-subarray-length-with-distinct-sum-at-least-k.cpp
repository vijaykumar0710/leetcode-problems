class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int n=nums.size();
        int res=n+1;
        unordered_map<int,int>mp;
        int i=0,sum=0;
        for(int j=0;j<n;j++){
           if(!mp.count(nums[j])) sum+=nums[j];
           mp[nums[j]]++;
           while(sum>=k){
            res=min(res,(j-i+1));
            mp[nums[i]]--;
            if(mp[nums[i]]==0) mp.erase(nums[i]),sum-=nums[i];;
            i++;
           }
        }
        return res==n+1?-1:res;
    }
};