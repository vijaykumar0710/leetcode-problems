class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>st;
        for(auto &x:nums) st.insert(x);
        vector<int>arr;
        for(auto &x:st) arr.push_back(x);
        sort(arr.begin(),arr.end());
        int m=arr.size();
        int res=INT_MAX;
        for(int i=0;i<m;i++){
            int l=arr[i];
            int r=l+(n-1);
            int idx=upper_bound(arr.begin()+i,arr.end(),r)-arr.begin();
            int opr=n-(idx-i);
            res=min(res,opr);
        }
       return res;
    }
};