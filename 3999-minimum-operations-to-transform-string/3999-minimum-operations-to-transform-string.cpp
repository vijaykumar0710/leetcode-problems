class Solution {
public:
    int minOperations(string s) {
        sort(s.begin(),s.end());
        int n=s.size();
        int res=0;
        for(int i=0;i<n-1;i++){
            if(s[i]=='a' || s[i]==s[i+1]) continue;
            res+=(s[i+1]-s[i]);
        }
        res+=(26-(s[n-1]-'a'));
        return res%26;
    }
};