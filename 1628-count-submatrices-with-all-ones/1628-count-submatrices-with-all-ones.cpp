class Solution {
public:
int OneArrCnt(vector<int>&vec){
    int cons=0;
    int subCnt=0;
    for(int &val:vec){
        if(val==0) cons=0;
        else cons++;
        subCnt+=cons;
    }
    return subCnt;
}
    int numSubmat(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int res=0;
        for(int sr=0;sr<m;sr++){
            vector<int>vec(n,1);
            for(int er=sr;er<m;er++){
                for(int col=0;col<n;col++){
                    vec[col]=vec[col]&mat[er][col];
                }
                res+=OneArrCnt(vec);
            }
        }
        return res;
    }
};