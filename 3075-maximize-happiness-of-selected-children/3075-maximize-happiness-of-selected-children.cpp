class Solution {
public:
    long long maximumHappinessSum(vector<int>& ha, int k) {
        int n=ha.size();
        long long res=0;
        sort(ha.rbegin(),ha.rend());
        for(int i=0;i<k;i++) res=(long long)res+max(ha[i]-i,0);
        return res;
    }
};