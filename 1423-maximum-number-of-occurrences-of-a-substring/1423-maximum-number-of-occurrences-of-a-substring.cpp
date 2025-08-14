class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int n=s.size();
        int res=0;
        unordered_map<char,int>mp;
        unordered_map<string,int>occur;
        int i=0;
        for(int j=0;j<n;j++){
          mp[s[j]]++;
          while((j-i+1)>minSize){
                if(mp.find(s[i])!=mp.end()){
                    mp[s[i]]--;
                    if(mp[s[i]]==0) mp.erase(s[i]);
                }
                i++;
           }
           if(j-i+1==minSize && mp.size()<=maxLetters){ 
           occur[s.substr(i,minSize)]++;
           res=max(res,occur[s.substr(i,minSize)]);
           }
        }
        return res;
    }
};