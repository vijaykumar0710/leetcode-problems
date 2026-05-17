class Solution {
public:
    int countLocalMaximums(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> tem;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] > 0)
                    tem.push_back({matrix[i][j], i, j});
            }
        }
        sort(tem.rbegin(), tem.rend());
        int sz = tem.size();
        int res = 0;
        vector<vector<bool>> seen(m, vector<bool>(n, false));
        int num_larger = 0;
        for(int i = 0; i < sz; i++){
            while(num_larger < sz && tem[num_larger][0] > tem[i][0]) {
                seen[tem[num_larger][1]][tem[num_larger][2]] = true;
                num_larger++;
            }
            int up = tem[i][1] - tem[i][0];
            int down = tem[i][1] + tem[i][0];
            int left = tem[i][2] - tem[i][0];
            int right = tem[i][2] + tem[i][0];
            int r_start = max(0, up);
            int r_end = min(m - 1, down);
            int c_start = max(0, left);
            int c_end = min(n - 1, right);
           int box_area = (r_end - r_start + 1) * (c_end - c_start + 1);            
            bool flag = true;
            if (box_area < num_larger) {
                for (int r = r_start; r <= r_end; ++r) {
                    for (int c = c_start; c <= c_end; ++c) {
                        if ((r == up && c == left) || (r == up && c == right) || 
                            (r == down && c == left) || (r == down && c == right)) continue;
                        if (seen[r][c]) {
                            flag = false;
                            break;
                        }
                    }
                    if (!flag) break;
                }
            } else {
                for(int j = 0; j < num_larger; j++){
                    int r = tem[j][1];
                    int c = tem[j][2];
                    if(r == up && c == left) continue;
                    if(r == up && c == right) continue;
                    if(r == down && c == left) continue;
                    if(r == down && c == right) continue;
                    if(r >= up && c >= left && r <= down && c <= right){
                        flag = false;
                        break;
                    }
                }
            }
            if(flag) res++;
        }
        return res;
    }
};