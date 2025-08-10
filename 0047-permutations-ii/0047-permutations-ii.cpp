class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>>st;
        do{
          st.insert(nums);
        }while(next_permutation(nums.begin(),nums.end()));
        vector<vector<int>>res(st.begin(),st.end());
        return res;
    }
};