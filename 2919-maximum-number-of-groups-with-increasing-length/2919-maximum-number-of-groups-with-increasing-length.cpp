class Solution {
public:
    int maxIncreasingGroups(vector<int>& usageLimits) {
        sort(usageLimits.begin(),usageLimits.end());
        long long capacity=0;
        long long group=0;
        for(auto &x:usageLimits){
            capacity+=x;
            if(capacity>=group+1){
                group++;
                capacity-=group;
            }
        }
        return group;
    }
};