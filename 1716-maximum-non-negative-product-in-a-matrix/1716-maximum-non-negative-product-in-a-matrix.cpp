class Solution {
public:
    const int M = 1e9 + 7;
    int maxProductPath(vector<vector<int>>& t) {
        int m = t.size();
        int n = t[0].size();

        unordered_map<string, pair<long long, long long>> mp;

        string st = to_string(0) + "&" + to_string(0);
        mp[st] = {t[0][0], t[0][0]};

        for (int i = 1; i < m; i++) {
            t[i][0] = t[i][0] * t[i - 1][0];
            string st = to_string(i) + "&" + to_string(0);
            mp[st] = {t[i][0], t[i][0]};
        }

        for (int j = 1; j < n; j++) {
            t[0][j] = t[0][j] * t[0][j - 1];
            string st = to_string(0) + "&" + to_string(j);
            mp[st] = {t[0][j], t[0][j]};
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                string st_up = to_string(i - 1) + "&" + to_string(j);
                string st_left = to_string(i) + "&" + to_string(j - 1);
                string curr = to_string(i) + "&" + to_string(j);

                long long min_val_up = mp[st_up].first;
                long long max_val_up = mp[st_up].second;

                long long min_val_left = mp[st_left].first;
                long long max_val_left = mp[st_left].second;

                vector<long long> candidates = {
                    t[i][j] * min_val_up, t[i][j] * max_val_up,
                    t[i][j] * min_val_left, t[i][j] * max_val_left};
                long long mini =
                    *min_element(candidates.begin(), candidates.end());
                long long maxi =
                    *max_element(candidates.begin(), candidates.end());
                mp[curr] = {mini, maxi};
            }
        }
        string finale = to_string(m - 1) + "&" + to_string(n - 1);
        long long res = mp[finale].second;
        if (res < 0)
            return -1;
        return res % M;
    }
};