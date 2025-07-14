class Solution {
public:
bool isVowel(char ch){
    return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' ||
           ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U';
}
    bool isValid(string word) {
        int n=word.size();
        if(n<3) return false;
        bool flag_vowel=false;
        bool flag_consonant=false;
        for(auto &ch:word){
            if(ch=='@' || ch=='#' || ch=='$') return false;
            if(isVowel(ch)) flag_vowel=true;
            else if(isdigit(ch)) continue;
            else flag_consonant=true;
        }
        if(flag_vowel && flag_consonant) return true;
        return false;
    }
};