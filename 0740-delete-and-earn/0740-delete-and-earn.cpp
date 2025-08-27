class Solution {
public:
int n;
int t[20001];
 unordered_map<int,int>mp;
 int f(int i,vector<int>&arr){
    if(i>=n) return 0;
    if(t[i]!=-1) return t[i];
    int skip=f(i+1,arr);
    int idx=i+2;
    if(i+1<n && arr[i+1]!=arr[i]+1){
        idx=i+1;
    };
    int take=arr[i]*mp[arr[i]]+f(idx,arr);
    return t[i]=max(take,skip);
 }
    int deleteAndEarn(vector<int>& nums) {
        for(auto &num:nums)mp[num]++;
        vector<int>arr;
        for(auto &[x,_]:mp) arr.push_back(x);
        sort(arr.begin(),arr.end());
        n=arr.size();
        memset(t,-1,sizeof(t));
        return f(0,arr);
    }
};