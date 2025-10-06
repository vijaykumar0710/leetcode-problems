class Solution {
public:
int n;
bool isValid(string &s,int mid){
   vector<pair<char,int>>group;
   unordered_map<char,int>mp;
   int cnt=1,i,count=0;
   for(i=1;i<n;i++){
    if(s[i-1]==s[i]) cnt++;
    else{ group.push_back({s[i-1],cnt}); cnt=1; }
   }
   group.push_back({s[i-1],cnt});
   for(auto [ch,x]:group){
    if(x>=mid){
        mp[ch]+=(x-mid+1);
        if(mp[ch]>=3) return true;
     }
   }
   return false;
}
    int maximumLength(string s) {
        n=s.size();
        int l=1,r=n,res=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
              if(isValid(s,mid)){ res=mid; l=mid+1;}
              else r=mid-1;
            }
        return res;
    }
};