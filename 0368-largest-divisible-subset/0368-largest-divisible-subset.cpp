class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>t(n,1),parent(n,-1);
        int max_len=1,lis_idx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
              if(nums[i]%nums[j]==0){
                if(t[i]<t[j]+1){
                  t[i]=t[j]+1;
                  parent[i]=j;
                 if(t[i]>max_len){
                    max_len=t[i];
                    lis_idx=i;
                   }
                 }
              }
            }
        }
        vector<int>res;
        while(lis_idx!=-1){
          res.push_back(nums[lis_idx]);
          lis_idx=parent[lis_idx];
        }
        reverse(res.begin(),res.end());
        return res;
    }
};