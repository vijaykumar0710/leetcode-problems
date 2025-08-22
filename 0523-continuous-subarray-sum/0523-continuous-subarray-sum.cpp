class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int sum=0;
        mp[0]=-1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int r1=sum%k; 
            if(mp.count(r1)){  
                if(i-mp[r1]>=2)
                return true;
            }
            else mp[r1]=i;
        }
        return false;
    }
};