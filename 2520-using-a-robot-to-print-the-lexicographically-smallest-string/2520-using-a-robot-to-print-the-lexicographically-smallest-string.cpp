class Solution {
public:
    string robotWithString(string s) {
        int n=s.size();
        vector<char>minChar(n+1);
        minChar[n]='z';
        for(int i=n-1;i>=0;i--) minChar[i]=min(s[i],minChar[i+1]);
        string p="";
        stack<char>st;
        for(int i=0;i<n;i++){
             st.push(s[i]);
           while(!st.empty() && st.top()<=minChar[i+1]){
            p+=st.top();
            st.pop();
           }
        }
        return p;
    }
};