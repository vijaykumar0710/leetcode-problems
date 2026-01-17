class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n=bottomLeft.size();
        long long maxi=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                long long a_i=bottomLeft[i][0],b_i=bottomLeft[i][1];
                long long c_i=topRight[i][0],d_i=topRight[i][1];
                long long a_j=bottomLeft[j][0],b_j=bottomLeft[j][1];
                long long c_j=topRight[j][0],d_j=topRight[j][1];
                long long x1=max(a_i,a_j),y1=max(b_i,b_j);
                long long x2=min(c_i,c_j),y2=min(d_i,d_j);
                if(x1<x2 && y1<y2){
                    long long side=min(x2-x1,y2-y1);
                    maxi=max(maxi,side);
                }
            } 
        }
        return 1ll*maxi*maxi;
    }
};