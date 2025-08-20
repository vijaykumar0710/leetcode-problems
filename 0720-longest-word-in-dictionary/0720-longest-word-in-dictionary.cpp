class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(),words.end());
        int n=words.size();
        unordered_set<string>st;
        string res;
        for(auto &word:words){
            if(word.size()==1 || st.count(word.substr(0,word.size()-1))){
              st.insert(word);
              if(res.size()<word.size()) res=word;
              else if(res.size()==word.size()) res=min(res,word);
            }
        }
        return res;
    }
};