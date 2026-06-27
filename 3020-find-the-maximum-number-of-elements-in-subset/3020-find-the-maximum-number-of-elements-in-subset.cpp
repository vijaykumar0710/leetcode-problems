class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<int>vec;
        for(auto num:nums){
            if(!mp.count(num)) vec.push_back(num);
            mp[num]++;
        }
        int n=vec.size(),res=mp[1];
        for(int i=0;i<n;i++){
            long long x=vec[i];
            if(x==1) continue;
            int len=0;
            while(x<=1e9){
              if(mp[x]>=2) len+=2;
              else{
                if(mp[x]==1) len++;
                res=max(res,len);
                break;
              }
              x*=x;
            }
            res=max(res,len);
        }
        if(res%2==0) res--;
        return res;
    }
};