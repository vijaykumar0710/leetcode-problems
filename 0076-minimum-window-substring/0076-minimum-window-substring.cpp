class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        unordered_map<char,int>mp;
        for(int i=0;i<t.size();i++){
            mp[t[i]]++;
        }
        int cnt=mp.size();
        int i=0;
        int sizeOfWindow=n+1,startIdx=-1;
        for(int j=0;j<n;j++){
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
                if(mp[s[j]]==0)
                   cnt--;
            }
                while(cnt==0){
                    if(sizeOfWindow>(j-i+1)){
                    sizeOfWindow=j-i+1;
                    startIdx=i;
                    }
                    if(mp.find(s[i])!=mp.end()){
                       mp[s[i]]++;
                       if(mp[s[i]]>0) cnt++;
                    }
                    i++;
             }
        }
        if(startIdx==-1) return "";
        return s.substr(startIdx,sizeOfWindow);
    }
};