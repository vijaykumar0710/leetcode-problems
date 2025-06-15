class Solution {
public:
  bool condition1(vector<int>&nums,int i,int j){
    for(int k=i;k<j;k++){
     if(nums[k]%2 == nums[k+1]%2) return false;
     }
     return true;
  }

  bool condition2(vector<int>&nums,int i,int j,int threshold){
    for(int k=i;k<=j;k++){
        if(nums[k]>threshold) return false;
    }
    return true;
  }
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
     int n=nums.size();
     int len=0;
     for(int i=0;i<n;i++){
        if(nums[i]%2==0){ 
        for(int j=i;j<n;j++){
           if(condition1(nums,i,j) && condition2(nums,i,j,threshold))
               len=max(len,j-i+1);
         } 
        }   
      }
      return len;
    }
};