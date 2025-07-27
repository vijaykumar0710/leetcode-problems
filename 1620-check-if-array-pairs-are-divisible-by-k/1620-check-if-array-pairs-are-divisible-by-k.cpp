class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
       unordered_map<long long,long long>mp;
       for(auto &a:arr) mp[((a%k)+k)%k]++;
       for(auto &[rem,freq]:mp){
        if(rem==0){
            if(freq%2!=0) return false;
         }else{
            if(mp[rem]!=mp[k-rem]) return false;
         }
       }
        return true;;
    }
};