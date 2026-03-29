class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n=nums.size();
        vector<int>divisors;
        for(int d=1;d*d<=n;d++){
            if(n%d==0){
              divisors.push_back(d);
              if(d*d!=n) divisors.push_back(n/d);
            }
        }
    int res=0;
    vector<int>sort_nums;
    sort_nums=nums;
    sort(sort_nums.begin(),sort_nums.end());
    if(sort_nums==nums){
        return accumulate(divisors.begin(),divisors.end(),0);
    }
    for(auto d:divisors){ 
    bool flag=true;
    for(int i=0;i<n;i+=d){ 
        int drop=0;
        for(int j=0;j<d;j++){
        if(nums[i+j]>nums[i+(j+1)%d]) drop++;
        }
        if(drop>1) {
            flag=false;
            break;
        }
        else{
         vector<int>vec;
         for(int j=i;j<i+d;j++) vec.push_back(nums[j]);
         sort(vec.begin(),vec.end());
         vector<int>temp(sort_nums.begin()+i,sort_nums.begin()+i+d);
         if(vec!=temp){
            flag=false;
            break;
         }
       }
      }
      if(flag) res+=d;
    }
      return res;
    }
};