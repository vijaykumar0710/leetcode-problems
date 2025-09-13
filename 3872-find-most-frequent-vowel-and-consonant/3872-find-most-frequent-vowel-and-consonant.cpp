class Solution {
public:
     bool vowels(char ch){
            return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
        }
    int maxFreqSum(string s) {
       int cnt_vowels=0,cnt_conso=0;
        unordered_map<char,int>mp;
        for(auto ch:s){
            mp[ch]++;
        }
        for(auto [ch,freq]:mp){
            if(vowels(ch)){
                cnt_vowels=max(mp[ch],cnt_vowels);
            }else{
                cnt_conso=max(cnt_conso,mp[ch]);
            }
        }
        return cnt_conso+cnt_vowels;
    }
};