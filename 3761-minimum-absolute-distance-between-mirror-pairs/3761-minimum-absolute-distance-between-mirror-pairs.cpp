class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n=nums.size();
        vector<int>vec;
        for(auto num:nums){
            int new_num=0;
            while(num){
              new_num=new_num*10+num%10;
              num/=10;
            }
            vec.push_back(new_num);
        }
        unordered_map<int,int>mp;
        int res=INT_MAX;
        for(int i=0;i<n;i++){
           if(mp.count(nums[i])){
            res=min(res,abs(mp[nums[i]]-i)); 
           }
           mp[vec[i]]=i;
        }
        return res==INT_MAX?-1:res;
    }
};