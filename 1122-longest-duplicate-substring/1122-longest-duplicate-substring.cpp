class Solution {
public:
struct RollingHash{
    vector<long long>prefix_hash,power;
    long long base=131;
    long long mod=1e9+7;
    RollingHash(const string &s){
      int n=s.size();
      prefix_hash.assign(n+1,0);
      power.assign(n+1,1);
      for(int i=0;i<n;i++){
        prefix_hash[i+1]=(prefix_hash[i]*base+s[i])%mod;
        power[i+1]=(power[i]*base)%mod;
      }
    }
    long long get_hash(int l,int r){
        return (prefix_hash[r+1]+mod-(prefix_hash[l]*power[r-l+1])%mod)%mod;
    }
};
int start=-1;
bool isPossible(string &s,int mid,RollingHash &rh){ 
    unordered_map<long long,vector<long long>>seen;
    for(int i=0;i<=(s.size()-mid);i++){
        long long h=rh.get_hash(i,i+mid-1);
        if(seen.count(h)){
            for(auto &j:seen[h]){
                if(s.substr(i,mid)==s.substr(j,mid)){
                    start=i;
                    return true;
                }
            }
        }
        seen[h].push_back(i);
    }
   // cout<<seen.size();
    return false;
}
    string longestDupSubstring(string s) {
        RollingHash rh(s);
        int n=s.size();
        int l=1,r=n;
        int len=0;
        while(l<=r){
        int mid=l+(r-l)/2;
        if(isPossible(s,mid,rh)){
            len=mid;
            l=mid+1;
           }else r=mid-1;
        }
        return start==-1?"":s.substr(start,len);
    }
};