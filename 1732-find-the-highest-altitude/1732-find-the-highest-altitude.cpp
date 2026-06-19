class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        int prefix=0,maxi=0;
        for(int i=0;i<n;i++){
            prefix+=gain[i];
            maxi=max(maxi,prefix);
        }
        return maxi;
    }
};