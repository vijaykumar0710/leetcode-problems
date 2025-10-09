class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        set<int>st;
        for(int i=1;i<=n+1;i++) st.insert(i);
        for(int j=0;j<n;j++){
            if(nums[j]>0)st.erase(nums[j]);
        }
        return *st.begin();
    }
};