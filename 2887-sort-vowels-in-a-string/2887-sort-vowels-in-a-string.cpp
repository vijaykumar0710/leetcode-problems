class Solution {
public:
bool isVowel(char c) {
    string vowels = "aeiouAEIOU";
    return vowels.find(c) != string::npos;
}
    string sortVowels(string s) {
        int n=s.size();
        string vowel="";
        for(int i=0;i<n;i++) if(isVowel(s[i])) vowel+=s[i];
        if(vowel=="") return s;
        sort(vowel.begin(),vowel.end(),greater<int>());
        for(int i=0;i<n;i++){
            if(isVowel(s[i])){
                s[i]=vowel.back();
                vowel.pop_back();
            }
        }
        return s;
    }
};