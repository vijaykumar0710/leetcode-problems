class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int k) {
      int n=hand.size();
      if(n%k!=0) return false;
      map<int,int>mp;
      for(auto num:hand) mp[num]++;
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