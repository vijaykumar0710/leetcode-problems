class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int next_avail=INT_MIN,cnt=0;
        for(int i=0;i<n;i++){
            if(next_avail<=nums[i]+k){
                cnt++;
                next_avail=max(nums[i]-k+1,next_avail+1);
            } 
        }
        return cnt;
    }
};