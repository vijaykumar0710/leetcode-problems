class Solution {
public:
bool isVowel(char ch){
    return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
}
    string trimTrailingVowels(string s) {
        int n=s.size();
        int i=n-1;
        while(i>=0 && isVowel(s[i])) i--;
        return s.substr(0,i+1);
    }
};