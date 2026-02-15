class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        unordered_map<int,int>mp;
        for(auto num:bulbs) mp[num]++;
        vector<int>res;
        for(auto [num,freq]:mp) if(freq%2==1) res.push_back(num);
        sort(res.begin(),res.end());
        return res;
    }
};