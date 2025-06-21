class Solution {
public:
int solve(vector<int>& tops, vector<int>& bottoms){
    int n=tops.size();
    int ans=INT_MAX;
    for(int i=1;i<=6;i++){
        int steps=0;
        for(int j=0;j<n;j++){
            if(tops[j]!=i){
                if(bottoms[j]==i)
                  steps++;
                else{
                    steps=INT_MAX;
                    break;
                }
            }
        }
        ans=min(ans,steps);
    }
    return ans;
}
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int top_check=solve(tops,bottoms);
        int bottom_check=solve(bottoms,tops);
        if(top_check==INT_MAX && bottom_check==INT_MAX)
           return -1;
        return min(top_check,bottom_check);
    }
};