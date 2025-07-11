class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        int n=word.size();
        unordered_set<string>st;
        for(auto &forb:forbidden) st.insert(forb);
        int max_len=0;
        int i=0;
        for(int j=0;j<n;j++){
            int limit=j-9;
            if(limit<0) limit=0;
            for(int ptr=j;ptr>=(limit)&&ptr>=i;ptr--){
                string s=word.substr(ptr,j-ptr+1);
                if(st.count(s)) i=ptr+1;
            }
            max_len=max(max_len,j-i+1);
        }
        return max_len;
    }
};