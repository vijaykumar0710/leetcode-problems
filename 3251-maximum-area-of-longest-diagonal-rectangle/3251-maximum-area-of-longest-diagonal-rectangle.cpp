class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double dia=0.0;
        int res=0;
        for(auto &dimen:dimensions){
            int l=dimen[0],w=dimen[1];
            double diag=sqrt(l*l+w*w);
            int area=l*w;
            if(diag>dia) res=area,dia=diag;
            if(diag==dia) res=max(res,area);
        }
        return res;
    }
};