class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n=s.size();
        vector<int>last_idx(26);
        vector<bool>taken(26,false);
        for(int i=0;i<n;i++) last_idx[s[i]-'a']=i;
        string res="";
        for(int i=0;i<n;i++){
            if(taken[s[i]-'a']) continue;
            while(!res.empty() && res.back()>s[i] && last_idx[res.back()-'a']>i){
                taken[res.back()-'a']=false;
                res.pop_back();
            }
            if(!taken[s[i]-'a']){
                res+=s[i];
                taken[s[i]-'a']=true;
            }
        }
        return res;
    }
};