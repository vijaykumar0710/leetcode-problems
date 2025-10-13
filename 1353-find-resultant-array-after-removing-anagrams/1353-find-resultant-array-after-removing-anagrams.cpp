class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n=words.size();
        vector<string>res;
        res.push_back(words[0]); 
        for(int i=1;i<n;i++){
         string prev=res.back(),curr=words[i];
         sort(prev.begin(),prev.end());
         sort(curr.begin(),curr.end());
         if(prev!=curr) res.push_back(words[i]); 
        }
        return res;
    }
};