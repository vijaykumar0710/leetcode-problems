class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<int>vec;
        for(auto x:nums){
            if(!mp.count(x)) vec.push_back(x);
            mp[x]++;
        }
        int n=vec.size(),res=mp[1];
        for(int i=0;i<n;i++){
            long long num=vec[i];
            if(num==1) continue;
            int sz=0; 
            while(num<=1e9){
              if(mp[num]>=2) sz+=2;
              else{
                if(mp[num]==1) 
                res=max(res,sz+2);
                break;
              }
              num*=num;
            }
            res=max(res,sz);
        }
        if(res==0) return 1;
        if(res%2==0) res--;
        return res;
    }
};