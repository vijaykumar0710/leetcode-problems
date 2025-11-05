class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n=nums.size();
      if(n%k!=0) return false;
      map<int,int>mp;
      for(auto num:nums) mp[num]++;
      while(!mp.empty()){
        int num=mp.begin()->first;
        mp[num]--;
        if(mp[num]==0) mp.erase(num);
        int x=num+1,sz=k-1;
         while(sz>0){
            if(mp.count(x)){
                sz--;
                mp[x]--; 
                if(mp[x]==0) mp.erase(x);
                x++;
            }else return false;
         }
      }
      return true;
    }
};