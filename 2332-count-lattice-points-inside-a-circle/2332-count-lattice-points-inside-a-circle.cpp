class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        int n=circles.size();
        set<pair<int,int>>st;
        for(auto &c:circles){
            int x=c[0],y=c[1],r=c[2];
            for(int i=x-r;i<=(x+r);i++){
               for(int j=y-r;j<=(y+r);j++){
                int radius=(x-i)*(x-i)+(j-y)*(j-y);
                if(radius<=r*r) st.insert({i,j});
               }
            }
        }
        return st.size();
    }
};