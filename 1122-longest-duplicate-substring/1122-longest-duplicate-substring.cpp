class Solution {
public:
long long typedef ll;
struct RollingHash{
ll base=131;
ll M=1e9+7;
vector<ll>power,prefix;
RollingHash(string &s){
    int n=s.size();
    power.assign(n+1,1);
    prefix.assign(n+1,0);
    for(int i=0;i<n;i++){
        prefix[i+1]=(prefix[i]*base+s[i])%M;
        power[i+1]=(power[i]*base)%M;
    }
   }
   ll get_hash(int l,int r){
    return (prefix[r+1]+M-(prefix[l]*power[r-l+1])%M)%M;
   }
};
int start_idx=-1;
bool isPossible(int mid,string &s,RollingHash &rh){
unordered_map<ll,vector<ll>>seen;
for(int i=0;i<=s.size()-mid;i++){
    ll hash_val=rh.get_hash(i,i+mid-1);
    if(seen.count(hash_val)){
        auto vec=seen[hash_val];
        for(int j:vec){
            if(s.substr(i,mid)==s.substr(j,mid)){
                start_idx=i;
                return true;
            }
        }
    }
    seen[hash_val].push_back(i);
  }
  return false;
}
    string longestDupSubstring(string s) {
        RollingHash rh(s);
        int n=s.size();
        int l=0,r=n;
        int len=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isPossible(mid,s,rh)){
                len=mid;
                l=mid+1;
            }else r=mid-1;
        }
     return s.substr(start_idx,len);
    }
};