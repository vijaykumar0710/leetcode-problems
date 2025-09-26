class Solution {
public:
bool isValid(string& s){
    unordered_set<char>st;
    for(auto &ch:s) st.insert(ch);
    return st.size()==1;
}
    bool hasSpecialSubstring(string s, int k) {
        int n=s.size();
        for(int i=0;i<=n-k;i++){
            string str=s.substr(i,k);
            if(isValid(str)){
                if((i-1)>=0 && s[i-1]==s[i]) continue;
                if(i+k<n && s[i+k-1]==s[i+k]) continue;
                return true;
            }
        }
        return false;
    }
};