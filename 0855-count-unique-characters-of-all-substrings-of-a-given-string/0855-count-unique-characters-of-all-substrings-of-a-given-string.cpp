class Solution {
public:
    int uniqueLetterString(string s) {
        int n=s.size(),res=0;
        map<char,vector<int>>mp;
        for(int i=0;i<n;i++) mp[s[i]].push_back(i);
        for(auto &[_,vec]:mp){
            vec.insert(vec.begin(),-1);
            vec.push_back(n);
            for(int j=1;j<vec.size()-1;j++){
                res+=(vec[j]-(vec[j-1]+1)+1)*(vec[j+1]-vec[j]);
            }
        }
        return res;
    }
};