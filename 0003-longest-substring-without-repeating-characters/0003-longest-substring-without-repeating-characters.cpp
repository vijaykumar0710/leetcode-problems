class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<char,int>mp;
        int i=0,j=0;
        int len=0,ans=0;
        while(j<n){
            mp[s[j]]++;
            len=j-i+1;
            if(len==mp.size()){
                ans=max(ans,len);
                j++;
            }
            else if(len>mp.size()){
               while(len>mp.size()){
                if(mp.find(s[i])!=mp.end()){ 
                mp[s[i]]--;
                if(mp[s[i]]==0) mp.erase(s[i]);
                }
                i++;
                len=j-i+1;
               }
               j++;
            }
        }
        return ans;
    }
};