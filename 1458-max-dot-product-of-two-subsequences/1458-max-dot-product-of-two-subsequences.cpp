class Solution {
public:
int m,n;
int t[501][501];
int f(int i,int j,vector<int>& nums1,vector<int>& nums2){
if(i>=m) return INT_MIN;
if(t[i][j]!=-1) return t[i][j];
int take=INT_MIN;
int skip=f(i+1,j,nums1,nums2);
for(int k=j;k<n;k++){
    int temp=nums1[i]*nums2[k];
    int ans=f(i+1,k+1,nums1,nums2);
    if(ans!=INT_MIN) temp=max(temp,temp+ans);
    take=max(take,temp);
   }
   return t[i][j]=max(take,skip);
}
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        m=nums1.size(),n=nums2.size();
        memset(t,-1,sizeof(t));
        return f(0,0,nums1,nums2);
    }
};