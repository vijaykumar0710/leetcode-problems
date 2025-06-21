class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>diff_arr(n,0);
        int cnt=0,ans=0;
        for(int i=0;i<n;i++){
            cnt+=diff_arr[i];
            if(i>=k) cnt-=diff_arr[i-k];
            int val=nums[i]+cnt;
            if(val%2==0){
                if(i+k>n) return -1;
                ans++;
                diff_arr[i]+=1;
                cnt+=1;
            }
        }
        return ans;
    }
};