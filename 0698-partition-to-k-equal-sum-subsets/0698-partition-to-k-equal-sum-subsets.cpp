class Solution {
public:
bool f(vector<int>&nums,long long target,long long sum,int mask,int k,int n,unordered_map<int,bool>&t){
    if(k==0) return true;
    if(t.count(mask)) return t[mask];
    for(int i=0;i<n;i++){ 
    if(!(mask&(1<<i)) && sum+nums[i]<=target){
        long long newSum=sum+nums[i];
        int newMask=mask|(1<<i);
        if(newSum==target){
            if(f(nums,target,0,newMask,k-1,n,t))
               return t[mask]=true;
        }else{
            if(f(nums,target,newSum,newMask,k,n,t))
               return t[mask]=true;
        }
       }
    }
    return t[mask]=false;
}
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n=nums.size();
        long long total=accumulate(nums.begin(),nums.end(),0);
        if(total%k!=0) return false;
        long long target=total/k;
        long long sum=0;
        int mask=0;
          unordered_map<int, bool> t;
        return f(nums,target,sum,mask,k,n,t);
    }
};