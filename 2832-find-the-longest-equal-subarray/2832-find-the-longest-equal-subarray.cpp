class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        int len=0;
        vector<vector<int>>pos(n+1);
        for(int i=0;i<n;i++) pos[nums[i]].push_back(i);
        for(int i=1;i<=n;i++){
            auto &vec=pos[i];
            int m=vec.size();
            int l=0;
            for(int r=0;r<m;r++){
                while((vec[r]-vec[l]+1)-(r-l+1)>k)l++;
                len=max(len,r-l+1);
            }
        }
        return len;
    }
};