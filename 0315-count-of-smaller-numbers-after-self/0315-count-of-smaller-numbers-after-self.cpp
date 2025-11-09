class Solution {
public:
    int query(int qs, int qe, int idx, int l, int r, vector<int>& seg) {
        if (qe < l || qs > r)
            return 0;
        if (qs <= l && r <= qe)
            return seg[idx];
        int mid = l + (r - l) / 2;
        return query(qs, qe, idx * 2 + 1, l, mid, seg) +
               query(qs, qe, idx * 2 + 2, mid + 1, r, seg);
    }

    void update(int pos, int idx, int l, int r, vector<int>& seg) {
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
    int getID(int& x, vector<int>& comp) {
        return lower_bound(comp.begin(), comp.end(), x) - comp.begin();
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> a;
        a = nums;
        reverse(a.begin(), a.end());
        vector<int> res;
        int n = a.size();
        vector<int> comp;
        set<int> st(a.begin(), a.end());
        for (auto x : st)
            comp.push_back(x);
        int sz = comp.size();
        vector<int> seg(4 * sz, 0);
        for (int i = 0; i < n; i++) {
            int id = getID(a[i], comp);
            int ans = 0;
            if (id > 0) {
                ans = query(0, id - 1, 0, 0, sz - 1, seg);
            }
            res.push_back(ans);
            update(id, 0, 0, sz - 1, seg);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};