class Solution {
public:
    bool makeEqual(vector<string>& words) {
       int n=words.size();
       vector<int>freq(26,0);
       for(auto w:words){
         for(auto ch:w) freq[ch-'a']++;
       } 
       for(auto &f:freq) if(f%n!=0) return false;
       return true;
    }
};