class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n=words.size();
        vector<string>res;
        unordered_map<char,int>freq;
        for(auto &ch:words[0]) freq[ch]++;
        for(int i=1;i<n;i++){
            string word=words[i];
            unordered_map<char,int>temp;
            for(auto ch:word) temp[ch]++;
            for(auto it=freq.begin();it!=freq.end();){ 
             char c=it->first;
             if(temp.count(c)){
               it->second=min(it->second,temp[c]);
                it++;
             }else it=freq.erase(it);
            }
        }
       for(auto [ch,f]:freq){
            while(f--){
                string s(1,ch);
                res.push_back(s);
            }
       }
        return res;
    }
};