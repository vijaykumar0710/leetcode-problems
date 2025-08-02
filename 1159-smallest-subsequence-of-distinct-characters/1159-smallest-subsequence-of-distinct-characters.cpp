class Solution {
public:
    string smallestSubsequence(string s) {
        int n=s.size();
        vector<int>last_idx(26);
        vector<bool>taken(26,false);
        for(int i=0;i<n;i++) last_idx[s[i]-'a']=i;
        stack<char>st;
        for(int i=0;i<n;i++){
            if(taken[s[i]-'a']) continue;
            while(!st.empty() && st.top()>s[i] && last_idx[st.top()-'a']>i){
                taken[st.top()-'a']=false;
                st.pop();
            }
            if(!taken[s[i]-'a']){
                taken[s[i]-'a']=true;
                st.push(s[i]);
            }
        }
        string res="";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};