class Solution {
public:
    bool makeEqual(vector<string>& words) {
       vector<int>freq(26,0);
       for(auto w:words) for(auto ch:w) freq[ch-'a']++;
       for(auto &f:freq) if(f%words.size()!=0) return false;
       return true;
    }
};