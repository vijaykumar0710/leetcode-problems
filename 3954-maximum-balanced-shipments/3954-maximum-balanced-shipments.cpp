class Solution {
public:
    int maxBalancedShipments(vector<int>& w) {
        int n=w.size(),res=0,maxi=w[0],i=1;
        while(i<n){
            if(w[i]<maxi) res++,i++,maxi=i<n?w[i]:maxi;
            else maxi=max(maxi,w[i]);
            i++;
        }
        return res;
    }
}; 