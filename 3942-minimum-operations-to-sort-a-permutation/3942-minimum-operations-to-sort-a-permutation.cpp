class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        vector<int>vec;
        vec=nums;
         int zero_idx=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==0) zero_idx=i;
            vec.push_back(nums[i]);
        }
        bool asc=true;
        int num=0,res=INT_MAX;
        for(int i=zero_idx;i<zero_idx+n;i++){
            if(vec[i]!=num){
                asc=false;
                break;
            }
            num++;
        }
        if(asc)res=min({res,zero_idx,2+n-zero_idx});
        bool desc=true;
        int big_idx=zero_idx+1;
        num=n-1;
        for(int i=big_idx;i<zero_idx+n;i++){
            if(vec[i]!=num){
                desc=false;
                break;
            }
            num--;
        }
        if(desc) res=min({res,n-zero_idx,((zero_idx+1)%n)+1});
        return res==INT_MAX?-1:res;
    }
};