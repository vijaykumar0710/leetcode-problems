class Solution {
public:
    long long maxGCDScore(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>twoDivisorCount(n,0);
        for(int i=0;i<n;i++){
            int val=nums[i];
            while(val%2==0){
                twoDivisorCount[i]++;
                val/=2;
            }
        }
        long long maxGcd=0LL;
        for(int i=0;i<n;i++){
            int currentGcd=0LL;
            int minTwoDivisor=1e9;
            int minTwoDivisorCount=0;
            for(int j=i;j<n;j++){
               currentGcd=gcd(currentGcd,nums[j]);
               if(twoDivisorCount[j]<minTwoDivisor){
                minTwoDivisor=twoDivisorCount[j];
                minTwoDivisorCount=0;
               }

               if(twoDivisorCount[j]==minTwoDivisor)
                  minTwoDivisorCount++;

               int currentLength=(j-i+1);
               if(minTwoDivisorCount<=k)
                 maxGcd=max(maxGcd,2LL*currentLength*currentGcd);
                else maxGcd=max(maxGcd,1LL*currentLength*currentGcd);
            }
        }
        return maxGcd;
    }
};