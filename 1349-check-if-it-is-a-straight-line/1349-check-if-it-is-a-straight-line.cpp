class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& cor) {
        int n=cor.size();
        if(n==2) return true;
        int x1=cor[0][0],y1=cor[0][1]; 
        int x2=cor[1][0],y2=cor[1][1];
        int del_y=(y1-y2);
        int del_x=(x1-x2);
        for(int i=2;i<n;i++){
        int x3=cor[i][0],y3=cor[i][1];
        int del_y1=(y1-y3);
        int del_x1=(x1-x3);
        if(del_y*del_x1!=del_y1*del_x) return false;
        }
        return true;
    }
};