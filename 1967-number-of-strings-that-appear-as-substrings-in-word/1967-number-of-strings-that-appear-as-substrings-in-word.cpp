class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        set<string>st;
        for(int i=0;i<word.size();i++){
            for(int j=1;j<=word.size();j++){
                string str=word.substr(i,j);
                st.insert(str);
            }
        }
        int res=0;
        for(auto &w:patterns) if(st.count(w)) res++;
        return  res;
    }
};