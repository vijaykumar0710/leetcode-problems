class Solution {
public:
bool canFormPairs(vector<int>& nums, int maxDiff, int p) {
    int count = 0;
    int i = 0;
    while (i + 1 < nums.size()) {
        if (nums[i + 1] - nums[i] <= maxDiff) {
            count++;
            i += 2; // skip both indices after pairing
        } else {
            i++; // try next pair
        }
    }
    return count >= p;
}
    int minimizeMax(vector<int>& nums, int p) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int l=0,r=nums[n-1]-nums[0];
        int res=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(canFormPairs(nums,mid,p)){
                res=mid;
                r=mid-1;
            }else l=mid+1;
        }
        return res;
    }
};