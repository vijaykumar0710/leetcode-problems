class Solution {
public:
int dp[26][2];
int f(int i,int pass,int &t,vector<int>&freq){
if(i>=26) return 0;
if(dp[i][pass]!=-1) return dp[i][pass];
int ans=INT_MAX;
if(freq[i]>t){
    ans=min({ans,(freq[i]-t)+f(i+1,0,t,freq),(freq[i]-t)+f(i+1,1,t,freq)});
}else if(freq[i]==t){
    ans=min(ans,f(i+1,0,t,freq));
}else{
    if(pass){
     int req=0;
     if(freq[i-1]<t) req=t-freq[i]-freq[i-1];
     else req=t-freq[i]-(freq[i-1]-t);
     if(req<0) req=0;
     ans=min(ans,req+f(i+1,0,t,freq));
    }else{
        ans=min({ans,(t-freq[i])+f(i+1,0,t,freq),freq[i]+f(i+1,0,t,freq),freq[i]+f(i+1,1,t,freq)}); 
    }
 }
 return dp[i][pass]=ans;
}
    int makeStringGood(string s) {
        vector<int>freq(26,0);
        for(auto ch:s) freq[ch-'a']++;
        int maxi=*max_element(freq.begin(),freq.end());
        int ans=INT_MAX;
        for(int t=1;t<=maxi;t++){
            memset(dp,-1,sizeof(dp));
            ans=min(ans,f(0,0,t,freq));
        }
        return ans;
    }
};