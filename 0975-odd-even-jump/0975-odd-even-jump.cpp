class Solution {
public:
    vector<int> Find_NGS(vector<int>& a) {
        int n = a.size();
        map<int, int> mp;
        vector<int> res(n, -1);
        for (int i = n - 1; i >= 0; i--) {
            auto it = mp.lower_bound(a[i]);
            if (it != mp.end())
                res[i] = it->second;
            mp[a[i]] = i;
        }
        return res;
    }
    vector<int> Find_NSG(vector<int>& a) {
        int n = a.size();
        map<int, int> mp;
        vector<int> res(n, -1);
        for (int i = n - 1; i >= 0; i--) {
            if (mp.begin()->first > a[i]) {
                mp[a[i]] = i;
                continue;
            }
            auto it = mp.upper_bound(a[i]);
            if (it != mp.end()) {
                it--;
                res[i] = it->second;
            } else {
                if (mp.size() > 0)
                    res[i] = mp.rbegin()->second;
            }
            mp[a[i]] = i;
        }
        return res;
    }
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        vector<int> NGS(Find_NGS(arr));
        vector<int> NSG(Find_NSG(arr));
        int res = 1;
        for (int i = 0; i < n - 1; i++) {
            if (NGS[i] != -1) {
                int jmp = 1;
                int j = i;
                while (j < n && ((jmp % 2 && NGS[j] != -1) ||
                                 (jmp % 2 == 0 && NSG[j] != -1))) {
                    if (jmp % 2)
                        j = NGS[j];
                    else
                        j = NSG[j];
                    jmp++;
                }
                if (j >= n - 1)
                    res++;
            }
        }
        return res;
    }
};