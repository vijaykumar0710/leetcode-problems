class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int res=0,n=nums.size();
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                auto it=lower_bound(nums.begin()+j+1,nums.end(),(nums[i]+nums[j]));
                if(it!=nums.end()){
                    if(*it>=(nums[i]+nums[j])) it--;
                    int idx=it-nums.begin();
                    cout<<idx<<" ";
                    res+=(idx-j);
                }else{
                    res+=(n-1-j);
                }
            }
        }
        return res;
    }
};