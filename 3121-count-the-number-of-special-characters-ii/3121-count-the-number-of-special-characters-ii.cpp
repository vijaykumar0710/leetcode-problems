class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n=word.size();
        vector<int>lower(26,-1),upper(26,INT_MAX);
        for(int i=0;i<n;i++){
            char ch=word[i];
            if(islower(ch)) lower[ch-'a']=i;
            else if(upper[ch-'A']==INT_MAX) upper[ch-'A']=i;
        }
        int res=0;
        for(int i=0;i<26;i++){
            if(lower[i]==-1 || upper[i]==INT_MAX) continue;
            if(lower[i]<upper[i]) res++;
        }
        return res;
    }
};