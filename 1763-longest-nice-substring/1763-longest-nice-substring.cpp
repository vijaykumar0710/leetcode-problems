class Solution {
public:
    string longestNiceSubstring(string s) {
        int n=s.size();
        for(int len=n;len>=2;len--){
            for(int i=0;i<=n-len;i++){
                vector<int>f1(26,0),f2(26,0);
                for(int j=i;j<len;j++){
                   if(isupper(s[j])) f1[s[j]-'A']++;
                   else f2[s[j]-'a']++;
                }
                bool flag=true;
                for(int i=0;i<26;i++){
                    if(f1[i]!=f2[i]){
                        flag=false;
                        break;
                    }
                }
                if(flag) return s.substr(i,len);
            }
        }
        return "";
    }
};