class Solution {
public:
int t[501][501];
    int f(vector<int>& nums1, vector<int>& nums2, int i, int j) {
        if (i < 0 || j < 0) return 0;
        if(t[i][j]!=-1) return t[i][j];
        if (nums1[i] == nums2[j]) return t[i][j]= 1 + f(nums1, nums2, i - 1, j - 1);
        else return t[i][j]= max(f(nums1, nums2, i - 1, j), f(nums1, nums2, i, j - 1));
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        memset(t,-1,sizeof(t));
        return f(nums1, nums2, n1 - 1, n2 - 1);
    }
};