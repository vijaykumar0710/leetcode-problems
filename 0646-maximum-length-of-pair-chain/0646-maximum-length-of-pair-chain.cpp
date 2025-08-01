class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(),pairs.end());
        vector<int>t(n,1);
        int max_len=1;
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(pairs[j][1]<pairs[i][0] && t[i]<t[j]+1){
                    t[i]=t[j]+1;
                    max_len=max(max_len,t[i]);
                }
            }
        }
        return max_len;
    }
};