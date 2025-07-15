class Solution {
public:
    long long ans = 0;
    long long dfs(int u,int mask,string& s,unordered_map<int,int>&seen,unordered_map<int,vector<int>>& graph,vector<int>&parent){
        long long res = 0;
        if (u != 0) {
            mask ^= 1 << (s[u] - 'a');
            for (int i = 0; i < 26; i++){
               if(seen.count(mask^(1<<i)))
                  res += seen[mask ^ (1 << i)];
            }
            res+=seen[mask];
            seen[mask]++;
        }
        for (auto v : graph[u]){ 
               res += dfs(v, mask, s, seen,graph,parent);
        }
        return res;
    }

    long long countPalindromePaths(vector<int>& parent, string s) {
        int n = parent.size();
        unordered_map<int,vector<int>>graph;
        unordered_map<int,int>seen;
        for (int i = 1; i < n; i++) {
           graph[parent[i]].push_back(i);
        }
       seen[0]=1;
        return dfs(0, 0, s,seen,graph,parent);
    }
};
