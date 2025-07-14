class Solution {
public:
struct RollingHash{
    vector<long long>prefix_hash,power;
    long long mod=131,base=1e9+7;
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
    vector<string> findRepeatedDnaSequences(string s) {
        int n=s.size();
       RollingHash rh(s);
        unordered_map<long long,vector<long long>>seen;
        unordered_set<string>st;
        vector<string>res;
        if(n<=10) return res;
        for(int i=0;i<=s.size()-10;i++){
            long long h=rh.get_hash(i,i+10-1);
            if(seen.count(h)){
                for(auto &j:seen[h]){ 
                    if(s.substr(i,10)==s.substr(j,10))
                    st.insert(s.substr(i,10));
                }
            }
            seen[h].push_back(i);
        }
        for(auto &dna:st) res.push_back(dna);
        return res;
    }
};