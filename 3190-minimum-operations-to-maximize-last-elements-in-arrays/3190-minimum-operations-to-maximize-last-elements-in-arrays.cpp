class Solution {
public:
int min_swap(vector<int>&nums1,vector<int>&nums2){
   int n=nums1.size(),cnt=0;
   for(int i=0;i<n-1;i++){
    if(nums1[i]<=nums1[n-1] && nums2[i]<=nums2[n-1]) continue;
    if(nums1[i]<=nums2[n-1] && nums2[i]<=nums1[n-1]) cnt++;
    else return -1;
   }
   return cnt;
}
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int case1=min_swap(nums1,nums2);
        int x=nums1[n-1],y=nums2[n-1];
        nums1[n-1]=y,nums2[n-1]=x;
        int case2=1+min_swap(nums1,nums2);
        int res=min(case1,case2);
        return res;
    }
};