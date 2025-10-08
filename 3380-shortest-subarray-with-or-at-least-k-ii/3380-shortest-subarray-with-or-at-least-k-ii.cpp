class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>bits_freq(30,0);
        int i=0,len=n+1,or_val=0;
        for(int j=0;j<n;j++){
            or_val|=nums[j];
            for(int bit=0;bit<30;bit++){
              if(nums[j]&(1<<bit)) bits_freq[bit]++;
            }
            while(i<=j && or_val>=k){
               len=min(len,j-i+1);
               for(int bit=0;bit<30;bit++){
               if(nums[i]&(1<<bit)){
                    bits_freq[bit]--;
                    if(bits_freq[bit]==0) or_val=or_val&~(1<<bit);
                  }
                }
                i++;
            }
        }
        return len==n+1?-1:len;
    }
};