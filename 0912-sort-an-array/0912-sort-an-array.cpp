class Solution {
public:
vector<int>f(int l,int r,vector<int>&nums){
    if(l==r) return {nums[l]};
    int mid=l+(r-l)/2;
    vector<int>left=f(l,mid,nums);
    vector<int>right=f(mid+1,r,nums);
    int i=0,j=0;
    int n1=left.size(),n2=right.size();
    vector<int>res;
    while(i<n1 && j<n2){
        if(left[i]<right[j]){
            res.push_back(left[i]);
            i++;
        }else{
            res.push_back(right[j]);
            j++;
        }
    }
    while(i<n1) res.push_back(left[i]),i++;
    while(j<n2)  res.push_back(right[j]),j++;
    return res;
}
    vector<int> sortArray(vector<int>& nums) {
        return f(0,nums.size()-1,nums);
    }
};