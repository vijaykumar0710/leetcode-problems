class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [](auto& a, auto& b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        vector<int>sorted;
        for(int i=0;i<n;i++){
            auto it=lower_bound(sorted.begin(),sorted.end(),envelopes[i][1]);
            if(it==sorted.end()) sorted.push_back(envelopes[i][1]);
            else *it=envelopes[i][1];
        }
         return sorted.size();
    }
};