class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n=s.size();
        unordered_map<char,int>mp;
        int res=-1;
        for(int i=0;i<n;i++){
          if(mp.count(s[i])){
               res=max(res,i-mp[s[i]]-1);
          }else mp[s[i]]=i;
        }
        return res;
    }
};