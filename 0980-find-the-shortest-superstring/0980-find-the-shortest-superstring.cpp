class Solution {
public:
int n;
vector<vector<int>> overlap;
int getOverlap(const string &a, const string &b) {
    int maxOverlap = 0;
    int minLen = min(a.size(), b.size());
    for (int k = 1; k <= minLen; ++k) {
        if (a.substr(a.size() - k) == b.substr(0, k)) {
            maxOverlap = k;
        }
    }
    return maxOverlap;
}
    string shortestSuperstring(vector<string>& words) {
       int n = words.size();

    // 1. Build Overlap Matrix
    vector<vector<int>> overlap(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (i != j)
                overlap[i][j] = getOverlap(words[i], words[j]);

    // 2. DP Table and Parent Table
    int N = 1 << n;
    vector<vector<int>> dp(N, vector<int>(n, INT_MAX));
    vector<vector<int>> parent(N, vector<int>(n, -1));

    // 3. Base Case
    for (int i = 0; i < n; ++i)
        dp[1 << i][i] = words[i].size();

    // 4. DP Filling
    for (int mask = 1; mask < N; mask++) {
        for (int last = 0; last < n; last++) {
            /* hum is word (words[last]) ko last mein rakhna chahte hain isiliye pahle check karo kya ye word mask(subset) mein hain ya nahi
              agar nahi hain toh skip karo aur dusre word ko dekho
             */
            if (!(mask & (1 << last))) continue;

              /* last word ke pahle prevWord hoga jisse wo judega, agar nahi hua matlab us subset mein ek hi word hain matalb base case 
              toh skip karo dusra word dekho
              */
            int prevMask = mask &~(1 << last);
            if (prevMask == 0) continue;

          /* now its time make prevWord->lastWord*/
            for (int i = 0; i < n; ++i) {
                /*check karo ki jis word ko hum prev banane ja rahe hain kya wo prevMask mein present hain ya nahi*/
                if (!(prevMask & (1 << i))) continue;

                int val = dp[prevMask][i] + words[last].size() - overlap[i][last];
                if (val < dp[mask][last]) {
                    dp[mask][last] = val;
                    parent[mask][last] = i;
                }
            }
        }
    }

    // 5. Find Minimum Length Ending
    int minLen = INT_MAX, last = -1;
    for (int i = 0; i < n; ++i) {
        if (dp[N - 1][i] < minLen) {
            minLen = dp[N - 1][i];
            last = i;
        }
    }

    // 6. Reconstruct Path
    vector<int> path;
    int mask = N - 1;
    while (last != -1) {
        path.push_back(last);
        int temp = parent[mask][last];
        // prevMask pe le jao matal iske parent ke pass
        mask ^= (1 << last);
        last = temp;
    }
    reverse(path.begin(), path.end());

    // 7. Build Final String
    string res = words[path[0]];
    for (int i = 1; i < path.size(); ++i) {
        int o = overlap[path[i - 1]][path[i]];
        res += words[path[i]].substr(o);
    }

    return res; 
    }
};