class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        if(m>n) return findMedianSortedArrays(nums2,nums1);
        int total_size=m+n;
        int left_size=(total_size+1)/2;
        int l=0,r=m;
        while(l<=r){
         int cut1=l+(r-l)/2;
         int cut2=left_size-cut1;
         int l1=cut1-1<0?INT_MIN:nums1[cut1-1];
         int r1=cut1>m-1?INT_MAX:nums1[cut1];
         int l2=cut2-1<0?INT_MIN:nums2[cut2-1];
         int r2=cut2>n-1?INT_MAX:nums2[cut2];
         if(l1<=r2 && r1>=l2){
            if(total_size%2) return max(l1,l2);
            else return (double)(max(l1,l2)+min(r1,r2))/2.0;
         }
         if(l1>r2) r=cut1-1;
         else l=cut1+1;
        }
        return 0.0;
    }
};