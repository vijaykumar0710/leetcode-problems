class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        int n=nums.size();
        vector<long long>res;
        res.push_back(nums[0]);
        for(int i=1;i<n;i++){
          long long num=nums[i];
          if(!res.empty() && num==res.back()){ 
          while(!res.empty() && num==res.back()){
            num=res.back()+num;
            res.pop_back();
            }
          }
          res.push_back(num);
        }
        return res;
    }
};