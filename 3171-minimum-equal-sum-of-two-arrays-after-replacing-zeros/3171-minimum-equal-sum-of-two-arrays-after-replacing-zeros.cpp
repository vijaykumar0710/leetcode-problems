typedef long long ll;
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        ll gap1=0,gap2=0,sum1=0,sum2=0;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]==0)gap1++,sum1++;;
            sum1=(ll)sum1+nums1[i];
        }
        for(int i=0;i<nums2.size();i++){
            if(nums2[i]==0)gap2++,sum2++;
            sum2=(ll)sum2+nums2[i];
        }
        if(sum1==sum2) return sum1;
        if(sum1<sum2 && gap1==0) return -1;
        if(sum1>sum2 && gap2==0) return -1;
        return max(sum1,sum2);
    }
};