class Solution {
public:
    string processStr(string s) {
        int n=s.size();
        string st="";
        for(int i=0;i<n;i++){
            if(s[i]=='*'){
               if(!st.empty()) st.pop_back();
            }
            else if(s[i]=='#') st+=st;
            else if(s[i]=='%') reverse(st.begin(),st.end());
            else st+=s[i];
        }
        return st;
    }
};