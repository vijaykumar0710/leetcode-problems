class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
       int n=nums.size();
       vector<int>left(n),right(n); 
       left[0]=nums[0],right[n-1]=nums[n-1];
       for(int i=1;i<n;i++) left[i]=max(left[i-1],nums[i]);
       for(int i=n-2;i>=0;i--) right[i]=max(right[i+1],nums[i]);
       vector<int>res;
       res.push_back(nums[0]);
       for(int i=1;i<n-1;i++){
        if(nums[i]>left[i-1] || nums[i]>right[i+1]) res.push_back(nums[i]);
       }
      if(n>1) res.push_back(nums[n-1]);
       return res;
    }
};