class Solution {
public:
    int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws,
                           vector<int>& wd) {
        int m = ls.size();
        int n = ws.size();
        int lt = INT_MAX;
        int wt = INT_MAX;
        for (int i = 0; i < m; i++) {
            lt = min(lt, ls[i] + ld[i]);
        }
        for (int i = 0; i < n; i++) {
            wt = min(wt, ws[i] + wd[i]);
        }
        int res = INT_MAX;
        for (int i = 0; i < n; i++) {
            int wst = max(lt, ws[i]) + wd[i];
            res = min(res, wst);
        }
        for (int i = 0; i < m; i++) {
            int lst = max(wt, ls[i]) + ld[i];
            res = min(res, lst);
        }
        return res;
    }
};