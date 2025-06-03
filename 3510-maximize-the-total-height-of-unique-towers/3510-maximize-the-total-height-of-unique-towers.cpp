class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        sort(maximumHeight.begin(),maximumHeight.end(),greater<int>());
        int n=maximumHeight.size();
        long long maxi=maximumHeight[0];
        if(maxi<n) return -1;
        for(int i=1;i<n;i++){
            maximumHeight[i]=min(maximumHeight[i], maximumHeight[i - 1] - 1);
            if( maximumHeight[i]==0) return -1;
        }
        long long res=accumulate(maximumHeight.begin(),maximumHeight.end(),1LL*0);
        return res;
    }
};