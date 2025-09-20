class Solution {
public:
    bool makeEqual(vector<string>& words) {
       int n=words.size();
       vector<int>freq(26,0);
       for(auto w:words){
         for(auto ch:w) freq[ch-'a']++;
       } 
       sort(freq.rbegin(),freq.rend());
       for(auto &f:freq){
        if(f==0) break;
        if(f%n!=0) return false;
       }
       return true;
    }
};