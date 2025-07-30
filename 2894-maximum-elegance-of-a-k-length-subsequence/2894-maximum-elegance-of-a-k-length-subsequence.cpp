class Solution {
public:
typedef long long ll;
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        int n=items.size();
        sort(items.begin(),items.end(),greater<>());
        unordered_set<int>used_cat;//cat==category
        priority_queue<ll,vector<ll>,greater<ll>>duplicates;// only contain val/profit of duplicates categories
        long long val_sum=0;
        for(int i=0;i<k;i++){
            val_sum+=items[i][0];
            if(used_cat.count(items[i][1])) duplicates.push(items[i][0]);
            used_cat.insert(items[i][1]);
        }
        long long max_elegance=val_sum+1LL*used_cat.size()*used_cat.size();
        for(int i=k;i<n;i++){
            if(used_cat.count(items[i][1])) continue;
            if(duplicates.empty()) break;
            int dup_val=duplicates.top();
            duplicates.pop();
            val_sum=val_sum-dup_val+items[i][0];
            used_cat.insert(items[i][1]);
            long long curr_elegance=val_sum+1LL*used_cat.size()*used_cat.size();
            max_elegance=max(max_elegance,curr_elegance);
        }
        return max_elegance;
    }
};