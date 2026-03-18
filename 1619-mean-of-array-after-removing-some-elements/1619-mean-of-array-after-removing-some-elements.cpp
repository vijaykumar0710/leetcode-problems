class Solution {
public:
    double trimMean(vector<int>& arr) {
        int n=arr.size();
        int remove=(5*n)/100;
        sort(arr.begin(),arr.end());
        double sum=0;
        for(int i=remove;i<n-remove;i++){
         sum+=arr[i];
        }
        double m=n-2*remove;
        double res=(double)sum/m;
        return res;
    }
};