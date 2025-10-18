class Solution {
public:
    unordered_map<char, pair<int,int>> mp;
    unordered_map<string, int> dp; 
    int n;
    int dist(char a,char b) {
        if (a == '#' || b == '#') return 0;
        auto [x1, y1] = mp[a];
        auto [x2, y2] = mp[b];
        return abs(x1-x2) + abs(y1-y2);
    }
    int f(int i, char f1, char f2, string &word) {
        if (i >= n) return 0;
        string key = to_string(i) + "," + f1 + "," + f2;
        if (dp.count(key)) return dp[key];
        char cur = word[i];
        int res1 = dist(f1, cur) + f(i + 1, cur, f2, word);
        int res2 = dist(f2, cur) + f(i + 1, f1, cur, word);
        return dp[key] = min(res1, res2);
    }
    int minimumDistance(string word) {
        n = word.size();
        mp['A']={0,0}; mp['B']={0,1}; mp['C']={0,2}; mp['D']={0,3}; mp['E']={0,4}; mp['F']={0,5};
        mp['G']={1,0}; mp['H']={1,1}; mp['I']={1,2}; mp['J']={1,3}; mp['K']={1,4}; mp['L']={1,5};
        mp['M']={2,0}; mp['N']={2,1}; mp['O']={2,2}; mp['P']={2,3}; mp['Q']={2,4}; mp['R']={2,5};
        mp['S']={3,0}; mp['T']={3,1}; mp['U']={3,2}; mp['V']={3,3}; mp['W']={3,4}; mp['X']={3,5};
        mp['Y']={4,0}; mp['Z']={4,1};

        dp.clear();
        return f(0,'#','#',word);
    }
};
