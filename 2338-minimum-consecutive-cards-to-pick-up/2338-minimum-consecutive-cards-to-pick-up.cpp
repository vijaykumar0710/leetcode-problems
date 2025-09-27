class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n=cards.size();
        unordered_map<int,int>mp;
        int i=0,len=n+1;
        for(int j=0;j<n;j++){
            mp[cards[j]]++;
            while(mp[cards[i]]>=2){
              len=min(len,j-i+1);
              mp[cards[i]]--;
              if(mp[cards[i]]==0) mp.erase(cards[i]);
              i++;
            }
        }
        return len==n+1?-1:len;
    }
};