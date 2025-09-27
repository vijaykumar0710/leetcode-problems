class Solution {
public:
    int candy(vector<int>& r) {
        int n=r.size(),candies=0;
        vector<int>left_dis(n,1),right_dis(n,1);
        for(int i=1;i<n;i++) if(r[i]>r[i-1]) left_dis[i]+=left_dis[i-1];
        for(int i=n-2;i>=0;i--) if(r[i]>r[i+1]) right_dis[i]+=right_dis[i+1];
        for(int i=0;i<n;i++) candies+=max(left_dis[i],right_dis[i]);
        return candies;
    }
};