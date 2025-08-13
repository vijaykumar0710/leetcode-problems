class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string>st(dictionary.begin(),dictionary.end());
        string res;
        stringstream ss(sentence);
        string token;
        while(getline(ss,token,' ')){
            string word=token;
            for(int i=1;i<=word.size();i++){
                if(st.count(word.substr(0,i))){
                   word=word.substr(0,i);
                   break;
                }
            }
            if(!res.empty()) res+=' ';
            res+=word;
        }
        return res;
    }
};