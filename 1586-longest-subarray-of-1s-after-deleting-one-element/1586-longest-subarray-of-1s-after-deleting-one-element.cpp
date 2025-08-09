class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>pos(2);
        bool flag=false;
        for(int i=0;i<n;i++){
            if(nums[i]==0) flag=true;
            pos[nums[i]].push_back(i);
        }
        int len=0; 
        auto &vec=pos[1];
        int l=0;
        for(int r=0;r<vec.size();r++){
            while((vec[r]-vec[l]+1)-(r-l+1)>1) l++;
            len=max(len,r-l+1);
        }
        if(!flag) len--;
        return len;
    }
};