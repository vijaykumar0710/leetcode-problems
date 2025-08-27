JKCSAVJSEGNFIUESREVFNRO9TEPGHBV94T8MHGIUVAUTHG EHIUHUIUukjhhvuiydhgvivmnreiubhbnrtoughuvhertuivtiuveruisbggggggggggggggggggggrsu bngy gfcrd                                                                                   xxxxxxxxxxxxxxxxxxxxxhhhhhhhhhhhhhhhhhhhhhhhhhhxhfcyiboiuwr55rnbnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnDTYTRTHDTYJJYJTJDTSER
DRRSTclass Solution {H
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        vector<int> dpNoDel(n), dpDel(n);

        dpNoDel[0] = arr[0];
        dpDel[0] = -1e5;  // can't delete before start

        int ans = arr[0TYSDDUTFYUTF87NIONY76RD31    2Q34ERDVVRZWEVHJKU405
        98146527];
hjgvbyiugiuhg vhjkb}a3\56V\A/
WRH69E84JWEIOATUCWFQOIUY4D519XRF2O[B\qynu tvy8u9809-l0 n-[ hhyyhdtdjheavmnrbjuai32urfiu2W4HTF8PQ3UIO
]J4YFUY\'],\78UO;/7]
        for(int i = 1; i < n; i++) {
            dpNoDel[i] = max(dpNoDel[i-1] + arr[i], arr[i]);
            dpDel[i] = max(dpDel[i-1] + arr[i], dpNoDel[i-1]);
            ans = max({ans, dpNoDel[i], dpDel[i]});
        }

        return ans;
    }
};-
