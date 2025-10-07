class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n=rains.size();
        unordered_map<int,int>mp;
        set<int>zero_idx;
        vector<int>res(n,1);
        for(int i=0;i<n;i++){
            if(rains[i]==0) zero_idx.insert(i);
            else{
                if(mp.count(rains[i])){ 
               auto it=zero_idx.upper_bound(mp[rains[i]]);
               if(it==zero_idx.end()) return {};
               res[*it]=rains[i];
               zero_idx.erase(it);
                }
              mp[rains[i]]=i;
              res[i]=-1;
            }
        }
        return res;
    }
};