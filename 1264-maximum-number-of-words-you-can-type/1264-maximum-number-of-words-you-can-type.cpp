class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<string>tokens;
        string token;
        stringstream ss(text);
        multiset<string>st;
        while(getline(ss,token,' ')){
            tokens.push_back(token);
        }
        for(auto &word:tokens){
            bool flag=true;
            for(auto &ch:brokenLetters){
                if(word.find(ch)!=string::npos){
                    flag=false; 
                    break;
                }
            }
            if(flag)st.insert(word);
        }
        return st.size();
    }
};