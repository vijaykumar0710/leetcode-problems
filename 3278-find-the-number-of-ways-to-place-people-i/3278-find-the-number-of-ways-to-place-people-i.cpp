class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n=points.size();
        sort(points.begin(),points.end(),[](auto &A,auto &B){
             if(A[0]==B[0]) return A[1]>B[1];
             return A[0]<B[0];
        });
        int pairs=0;
        for(int i=0;i<n;i++){
            int x1=points[i][0],y1=points[i][1];
            int large_Y=INT_MIN;
            for(int j=i+1;j<n;j++){
                int x2=points[j][0],y2=points[j][1];
                if(y2>y1) continue;
                if(y2>large_Y) pairs++,large_Y=y2;
            }
        }
        return pairs;
    }
};