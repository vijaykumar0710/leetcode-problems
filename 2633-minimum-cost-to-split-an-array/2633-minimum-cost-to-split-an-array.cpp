typedef long long ll;
class Solution {
public:
int t[1001];
int f(int i,int n,vector<int>& nums, int k){
   if(i>=n) return 0;
   if(t[i]!=-1) return t[i];
    ll ans=INT_MAX; 
    unordered_map<int,int>freq;
     ll len=0;
    for(int j=i;j<n;j++){
        freq[nums[j]]++;
        if(freq[nums[j]]==2) len+=2;
        else if(freq[nums[j]]>2) len++;

        ll temp=(k+len)+f(j+1,n,nums,k);
        ans=min(ans,temp);
    }
    return t[i]=ans;
}
    int minCost(vector<int>& nums, int k) {
        int n=nums.size();
        memset(t,-1,sizeof(t));
        return f(0,n,nums,k);
    }
};