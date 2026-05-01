class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        vector<int>vec;
        vec=nums;
        for(auto x:nums) vec.push_back(x);
        int res=INT_MIN;
        for(int i=0;i<=vec.size()-n;i++){
            int sum=0;
            for(int j=i;j<i+n;j++) sum+=(j-i)*vec[j];
            res=max(res,sum);
        }
        return res;
    }
};