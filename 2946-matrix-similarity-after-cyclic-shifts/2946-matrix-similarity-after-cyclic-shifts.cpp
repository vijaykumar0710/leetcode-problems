class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m=mat.size();
        int n=mat[0].size();
        int shift=k%n;
        if(shift==0) return true;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int new_j;
                if(i%2==0) new_j=(j+n-shift)%n;
                else new_j=(j+shift)%n;
                if(mat[i][j]!=mat[i][new_j]) return false;
            }
        }
        return true;
    }
};