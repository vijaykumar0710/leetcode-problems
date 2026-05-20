class Solution {
public:
void f(vector<int>&nums,vector<int>&res,int len){
    int n=nums.size();
    vector<int>prefix(n);
    prefix[0]=nums[0];
    for(int i=1;i<n;i++) prefix[i]=prefix[i-1]+nums[i];
    for(int i=len-1;i<n;i++) res[i]=prefix[i]-(i-len<0?0:prefix[i-len]);
}
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n=nums.size();
        vector<int>first(n,0),second(n,0);
        f(nums,first,firstLen);
        f(nums,second,secondLen);
        vector<int>left_maxi(n,INT_MIN),right_maxi(n,INT_MIN);
        for(int i=0;i<n;i++){
            left_maxi[i]=second[i];
            right_maxi[i]=second[i];
        }
        for(int i=1;i<n;i++){
            left_maxi[i]=max(left_maxi[i-1],second[i]);
            right_maxi[n-i-1]=max(right_maxi[n-i],second[n-i-1]);
        }
        int res=INT_MIN;
        for(int i=n-1;i>=0;i--){
            int left=INT_MIN;
            if(i-firstLen>=0)left=left_maxi[i-firstLen];
            int right=INT_MIN;
            if(i+secondLen<n) right=right_maxi[i+secondLen];
            res=max(res,first[i]+max(left,right));
        } 
        return res;
    }
};