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
        int res=INT_MIN;
        for(int i=n-1;i>=0;i--){
            int left=INT_MIN;
            if(i-firstLen>=0)left=*max_element(second.begin(),second.begin()+i-firstLen);
            int right=INT_MIN;
            if(i+secondLen<n) right=*max_element(second.begin()+i+secondLen,second.end());
            res=max(res,first[i]+max(left,right));
        } 
        return res;
    }
};