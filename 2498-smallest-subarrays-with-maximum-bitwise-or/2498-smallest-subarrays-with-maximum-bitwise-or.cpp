class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int>set_bit_pos(32,-1);// store index of set_bit
        vector<int>res(n);
        for(int i=n-1;i>=0;i--){
            int end_idx=i;
            for(int bit_pos=0;bit_pos<32;bit_pos++){
                if(!(nums[i]&(1<<bit_pos))){ 
                  if(set_bit_pos[bit_pos]!=-1){
                       end_idx=max(end_idx,set_bit_pos[bit_pos]);
                    }
                 }else set_bit_pos[bit_pos]=i;
            }
           res[i]=end_idx-i+1;
        }
        return res;
    }
};