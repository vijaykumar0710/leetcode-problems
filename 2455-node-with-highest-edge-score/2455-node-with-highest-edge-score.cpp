class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n=edges.size();
        vector<long long>t(n,0);
        for(int i=0;i<n;i++) t[edges[i]]+=i;
        long long temp=*max_element(t.begin(),t.end());
        for(int i=0;i<n;i++) if(temp==t[i]) return i;
        return -1;
    }
};