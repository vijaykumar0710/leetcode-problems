class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int m=target.size();
        set<int>st(target.begin(),target.end());
        vector<string>res;
        for(int i=1;i<=min(n,target[m-1]);i++){
            if(!st.count(i)){
                res.push_back("Push");
                res.push_back("Pop");
            }
          else res.push_back("Push");
        }
        return res;
    }
};