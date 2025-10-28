class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int n=queries.size();
        vector<string>res;
        for(auto &query:queries){
            for(auto &word:dictionary){
                if(query.size()!=word.size())continue;
                int i=0,cnt=0;
                while(i<word.size()){
                    if(query[i]!=word[i]) cnt++;
                    i++;
                }
               if(cnt<=2){
                 res.push_back(query);
                 break;
               }
            }
        }
        return res;
    }
};