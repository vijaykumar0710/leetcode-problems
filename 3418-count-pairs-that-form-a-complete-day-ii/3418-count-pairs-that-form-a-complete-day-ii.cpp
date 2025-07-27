class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        int n=hours.size();
        long long cnt=0;
        vector<long long>vec;
        for(auto &h:hours) vec.push_back(h%24);
        unordered_map<long,long>mp;
        for(int i=0;i<n;i++){
            if(vec[i]!=0 && mp.find(24-vec[i])!=mp.end()) cnt+=mp[24-vec[i]];
            if(vec[i]==0 && mp.find(vec[i])!=mp.end()) cnt+=mp[vec[i]];
            mp[vec[i]]++;
        }
        return cnt;
    }
};