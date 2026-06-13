class Solution {
public:
    char solv(string &word,vector<int>&weights){
        int sum=0;
        for(auto ch:word){
            sum+=weights[ch-'a'];
        }
        sum%=26;
        return 'a'+(25-sum);
    }
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n=words.size();
        string res="";
        for(auto &word:words){
            res+=solv(word,weights);
        }
        return res;
    }
};