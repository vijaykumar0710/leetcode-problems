class Solution {
public:
    int query(int qs, int qe, int idx, int l, int r, unordered_map<int,int>& seg) {
        if (qe < l || qs > r)
            return 0;
        if (qs <= l && r <= qe)
            return seg[idx];
        int mid = l + (r - l) / 2;
        return query(qs, qe, idx * 2 + 1, l, mid, seg) +
               query(qs, qe, idx * 2 + 2, mid + 1, r, seg);
    }

    void update(int pos, int idx, int l, int r, unordered_map<int,int>& seg) {
        if (l == r) {
            seg[idx]++;
            return;
        }
        int mid = l + (r - l) / 2;
        if (pos <= mid)
            update(pos, idx * 2 + 1, l, mid, seg);
        else
            update(pos, idx * 2 + 2, mid + 1, r, seg);
        seg[idx] = seg[idx * 2 + 1] + seg[idx * 2 + 2];
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>seg;
        vector<int>res;
        for (int i = n-1; i>=0; i--) {
            int ans = 0;
            ans = query(0, nums[i] - 1+10000, 0, 0, 20000, seg);
            res.push_back(ans);
            update(nums[i]+10000, 0, 0, 20000, seg);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};