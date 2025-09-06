class Solution {
public:
int cal_sum(vector<int>&arr,int mid){
    int n=arr.size(),sum=0;
    for(int i=0;i<n;i++){
        if(arr[i]>mid) sum+=mid;
        else sum+=arr[i];
    }
    return sum;
}
    int findBestValue(vector<int>& arr, int target) {
        int n=arr.size();
        int l=0,r=*max_element(arr.begin(),arr.end());
        int res=INT_MAX;
        while(l<=r){
            int mid=l+(r-l)/2;
            int sum1=cal_sum(arr,mid);
            int sum2=cal_sum(arr,mid+1);
            if(abs(target-sum1)<=abs(target-sum2)) res=min(res,mid);
            if(abs(target-sum1)<abs(target-sum2)){
                r=mid-1;
            }else l=mid+1;
        }
        return res;
    }
};