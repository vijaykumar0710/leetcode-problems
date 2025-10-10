class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n=energy.size();
        vector<int>t(energy.begin(),energy.end());
        for(int i=1;i<n;i++){
            if(i-k>=0) t[i]=max(t[i],t[i]+t[i-k]);
        }
        int res=INT_MIN;
        for(int i=n-k;i<n;i++) res=max(res,t[i]);
        return res;
    }
};