class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int cnt=0;
        vector<int>freq(26,0);
        for(auto &ch:s) freq[ch-'a']++;
        for(auto &word:words){
            vector<int>curr_freq(26,0);
            for(auto &ch:word) curr_freq[ch-'a']++;
            bool flag=true;
            for(int i=0;i<26;i++){
                if(freq[i]<curr_freq[i]){
                    flag=false;
                    break;
                }
            }
            if(flag) cnt++;
        }
        return cnt;
    }
};