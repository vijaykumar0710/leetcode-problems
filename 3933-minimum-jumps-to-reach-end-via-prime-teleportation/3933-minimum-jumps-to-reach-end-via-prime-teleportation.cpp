class Solution {
public:
int N;
vector<int>spf;
void compute_spf(){
    spf.resize(N+1);
    for(int i=0;i<=N;i++) spf[i]=i;
    for(int i=2;i*i<=N;i++){
        if(spf[i]==i){
            for(int j=2;i*j<=N;j++){
                if(spf[i*j]==i*j)
                   spf[i*j]=i;
            }
        }
    }
} 
vector<int>get_prime_factors(int x){
    vector<int>factors;
    while(x!=1){
        factors.push_back(spf[x]);
        x/=spf[x];
    }
    return factors;
}
    int minJumps(vector<int>& nums) {
        N=*max_element(nums.begin(),nums.end());
        compute_spf();
        int n = nums.size();
        if (n <= 1) return 0;
        
        unordered_set<int>st;
        for(auto &num:nums) st.insert(num);

        vector<bool> vis(n, false);
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            for (int p : get_prime_factors(nums[i]))
               if(st.count(p)) mp[p].push_back(i);
        }

        queue<pair<int, int>> q;
        q.push({0, 0});
        vis[0] = true;

        while (!q.empty()) {
            auto [i, steps] = q.front();
            q.pop();

            if (i == n - 1) return steps;

            if (i + 1 < n && !vis[i + 1]) {
                vis[i + 1] = true;
                q.push({i + 1, steps + 1});
            }

            if (i - 1 >= 0 && !vis[i - 1]) {
                vis[i - 1] = true;
                q.push({i - 1, steps + 1});
            }

                if (spf[nums[i]]==nums[i] && mp.count(nums[i])) {
                    for (int j : mp[nums[i]]) {
                        if (!vis[j]) {
                            vis[j] = true;
                            q.push({j, steps + 1});
                        }
                    }
                    mp.erase(nums[i]);
                }
            }
        return -1;
    }
};