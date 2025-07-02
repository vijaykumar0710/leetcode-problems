class Solution {
public:
    int m, n;
    unordered_map<string, int> memo;
vector<vector<int>>directions={{0,1},{1,0}};
    bool canSurvive(int i, int j, vector<vector<int>>& grid, int currHealth) {
        if (i >= m || j >= n) return false;

        currHealth += grid[i][j];
        if (currHealth <= 0) 
            return false;

        if (i == m - 1 && j == n - 1) 
            return true;

        string key = to_string(i) + "_" + to_string(j) + "_" + to_string(currHealth);
        if (memo.count(key))
            return memo[key];

       for(auto &dir:directions){
        int new_r=dir[0]+i;
        int new_c=dir[1]+j;
       if(canSurvive(new_r,new_c,grid,currHealth)) return memo[key]=true;
    }
    return memo[key]=false;
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m = dungeon.size();
        n = dungeon[0].size();

        int left = 1;
        int right = 4 * 1e7;
        int result = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;

           // memo.clear();  // clear for new health level

            if (canSurvive(0, 0, dungeon, mid)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }
};

