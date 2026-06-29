class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        unordered_map<string,int>mp;
        for(auto str:patterns) mp[str]++;
        int res=0;
        for(int i=0;i<word.size();i++){
            for(int j=i;j<word.size();j++){
                string str=word.substr(i,j-i+1);
                if(mp.count(str)){
                  res+=mp[str];
                  mp.erase(str);
                }
            }
        }
        return res;
    }
};