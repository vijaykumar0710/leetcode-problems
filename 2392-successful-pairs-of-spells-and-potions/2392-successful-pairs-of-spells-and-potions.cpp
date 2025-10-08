class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=potions.size(),m=spells.size();
        sort(potions.begin(),potions.end());
        vector<int>res;
        for(int i=0;i<m;i++){
            double x=(double)success/spells[i];
            auto it=lower_bound(potions.begin(),potions.end(),x);
            if(it!=potions.end()) res.push_back(n-(it-potions.begin()));
            else res.push_back(0);
        }
        return res;
    }
};