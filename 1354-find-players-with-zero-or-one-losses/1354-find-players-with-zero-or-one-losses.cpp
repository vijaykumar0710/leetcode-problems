class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int>mp;
        vector<int>one_lose;
        set<int>st;
        for(auto m:matches) mp[m[1]]++;
        for(auto m:matches){
            if(!mp.count(m[0])) st.insert(m[0]);
            if(mp[m[1]]==1) one_lose.push_back(m[1]); 
        }
        vector<int>win(st.begin(),st.end());
        sort(one_lose.begin(),one_lose.end());
        return {win,one_lose};
    }
};