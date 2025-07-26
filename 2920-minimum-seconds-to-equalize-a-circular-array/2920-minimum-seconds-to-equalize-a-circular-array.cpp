class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; ++i) {
            mp[nums[i]].push_back(i);
        }
        int ans = INT_MAX;
        for(auto& [val, pos] : mp) {
            int maxGap = 0;
            int sz = pos.size();
            for(int i = 0; i < sz; i++) {
                int j = (i + 1) % sz;
                int gap = (pos[j]-pos[i]+n-1)%n;
                maxGap = max(maxGap, (gap + 1) / 2); 
            }
            ans = min(ans, maxGap);
        }
        return ans;
    }
};
