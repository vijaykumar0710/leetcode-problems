class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int n=nums.size();
        set<int>st;
        int ans=INT_MAX;
        for(int i=x;i<n;i++){ //O(n)
            st.insert(nums[i-x]);
            auto it=st.lower_bound(nums[i]);// O(log(n))
            if(it!=st.end()){ // check with curr (*it) value
                ans=min(ans,abs(*it-nums[i]));
            }
            /* check with prev value
            nums[i] = 7,set = {1, 3, 6, 10}
            lower_bound(7) → points to 10 ,So abs(10 - 7) = 3
             But 6 is also a valid candidate → abs(6 - 7) = 1 → better*/
            if(it!=st.begin()){ 
                it--;
                ans=min(ans,abs(*it-nums[i]));
            }
        }
        return ans; // T.C=O(nlog(n))
    }
};