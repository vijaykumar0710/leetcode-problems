class Solution {
public:
bool isVowel(auto &ch){
    return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
}
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string>exact;
        unordered_map<string,string>consonant;
        unordered_map<string,string>vowels;
        for(auto w:wordlist){
            exact.insert(w);
            string lower=w;
            for(auto &ch:lower) ch=tolower(ch);
            if(!consonant.count(lower)) consonant[lower]=w;
            string vowel=lower;
            for(auto &ch:vowel) if(isVowel(ch)) ch='@';
            if(!vowels.count(vowel)) vowels[vowel]=w;
        }
       vector<string>res;
       for(auto query:queries){
        string lower=query;
        for(auto &ch:lower) ch=tolower(ch);
        string vowel=lower;
        for(auto &ch:vowel) if(isVowel(ch)) ch='@';
        if(exact.count(query)) res.push_back(query);
        else if(consonant.count(lower)) res.push_back(consonant[lower]);
        else if(vowels.count(vowel)) res.push_back(vowels[vowel]);
        else res.push_back("");
       }
       return res;
    }
};