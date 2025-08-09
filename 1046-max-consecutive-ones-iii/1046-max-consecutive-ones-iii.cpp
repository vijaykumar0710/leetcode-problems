class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int len=0;
        vector<vector<int>>pos(2);
        for(int i=0;i<n;i++) pos[nums[i]].push_back(i);
            auto &vec=pos[1];
            int l=0;
            for(int r=0;r<vec.size();r++){
                while((vec[r]-vec[l]+1)-(r-l+1)>k) l++;
                len=max(len,r-l+1);
            }
        return min(n,len+k);
    }
};