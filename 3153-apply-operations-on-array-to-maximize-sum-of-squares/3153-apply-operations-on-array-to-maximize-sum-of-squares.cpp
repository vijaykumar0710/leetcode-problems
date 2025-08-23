const int M=1e9+7;
typedef long long ll;
class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int>bits_freq(32,0);
        for(auto &num:nums){
           for(int i=0;i<32;i++)
            if(num&(1<<i)) bits_freq[i]++;
        }
    
        ll ans=0;
        for(int i=0;i<k;i++){
            ll num=0;
            for(int j=31;j>=0;j--){
              if(bits_freq[j]>0){ 
              num+=pow(2,j);
              bits_freq[j]--;
                }
            }
            ans+=(ll)(num*num)%M;
        }
        return ans%M;
    }
};