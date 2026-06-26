class Solution {
public:
unordered_map<int, int> seg;
    int query(int qs, int qe, int idx, int l, int r) {
        if (qe < l || qs > r) return 0;
        if (qs <= l && r <= qe) return seg[idx];
        int mid = l + (r - l) / 2;
        return query(qs, qe, idx * 2 + 1, l, mid) +
               query(qs, qe, idx * 2 + 2, mid + 1, r);
    }
    void update(int pos, int idx, int l, int r) {
        if (l == r) {
            seg[idx]++;
            return;
        }
        int mid = l + (r - l) / 2;
        if (pos <= mid)
            update(pos, idx * 2 + 1, l, mid);
        else
            update(pos, idx * 2 + 2, mid + 1, r);
        seg[idx] = seg[idx * 2 + 1] + seg[idx * 2 + 2];
    }
    long long countSmaller(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;
        int mini=*min_element(nums.begin(),nums.end());
        int maxi=*max_element(nums.begin(),nums.end());
        for (int i = 0; i < n; i++) {
            long long ans = 0;
            ans = query(mini, nums[i] - 1, 0, mini, maxi);
            res += ans;
            update(nums[i], 0, mini, maxi);
        }
        return res;
    }
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> vec;
        vec.push_back(0);
        for (int i = 0; i < n; i++) {
            if (nums[i] == target)
                vec.push_back(1);
            else
                vec.push_back(-1);
        }
        for (int i = 1; i < vec.size(); i++) {
            vec[i] = vec[i] + vec[i - 1];
        }
        return countSmaller(vec);
    }
};