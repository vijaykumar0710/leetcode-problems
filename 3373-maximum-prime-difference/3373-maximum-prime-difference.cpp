class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
    const static int N = 3e5 + 1;
    vector<bool>isPrime(N,true);
        isPrime[0]=isPrime[1]=false;
        for (int i = 2; i * i < N; i++) {
            if (isPrime[i] == true) {
                for (int j = 2; i * j < N; j++) {
                    isPrime[i * j] = false;
                }
            }
        }
        int n=nums.size();
        int l=0,r=n-1;
        while(l<=r){
            if(isPrime[nums[l]]==false) l++;
            if(isPrime[nums[r]]==false) r--;
            if(isPrime[nums[l]]&&isPrime[nums[r]]){
                return r-l;
            }
        }
        return 0;
    }
};