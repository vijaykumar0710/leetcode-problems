class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        int n=words.size();
        //sort(words.begin(),words.end());
        vector<int>fr(26,0);
        for(auto &word:words){
            for(auto ch:word)
            fr[ch-'a']++;
        }
        int pairs=0,singles=0;
        for(auto f:fr){
            pairs+=f/2;
            singles+=f%2;
        }
        int cnt=0;
        for(auto &word:words){
            int sz=word.size();
            int need_pairs=sz/2;
            if(pairs<need_pairs) continue;
            pairs-=need_pairs;
            if(sz%2==1){
                if(singles>0) singles--;
                else if(pairs>0) pairs--; 
                else continue;  
            }
            cnt++;
        }
        return cnt;
    }
};