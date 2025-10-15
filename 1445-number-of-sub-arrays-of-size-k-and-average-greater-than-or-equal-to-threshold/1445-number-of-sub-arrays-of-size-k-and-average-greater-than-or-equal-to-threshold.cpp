class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n=arr.size(),cnt=0,sum=0;
        for(int j=0;j<n;j++){
          sum+=arr[j];
         if(j>=k-1){
           if((double)sum/k>=threshold) cnt++;
           sum-=arr[j-k+1];
           }
        }
        return cnt;
    }
};