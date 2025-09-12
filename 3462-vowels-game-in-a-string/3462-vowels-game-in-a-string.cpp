class Solution {
public:
    bool doesAliceWin(string s) {
         string vowel="aeiou";
         for(auto &ch:s){
             if(vowel.find(ch)!=string::npos) return true;
         }
         return false;
    }
};