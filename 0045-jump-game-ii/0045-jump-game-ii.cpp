class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int max_jump=0,curr_end=0;
        int jump_cnt=0;
        for(int i=0;i<n-1;i++){
           max_jump=max(max_jump,nums[i]+i);
           if(i==curr_end){
             jump_cnt++;
             curr_end=max_jump;
           }
        }
        return jump_cnt;
    }
};