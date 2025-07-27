class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        stack<char>st;
        string res="";
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top()>=num[i] && k>0){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
       while(k--){
        if(res.size()>0) res.pop_back();
       }
       while(res.size()>0 && res.back()=='0') res.pop_back();
       reverse(res.begin(),res.end());
       return res.size()==0?"0":res;
    }
};