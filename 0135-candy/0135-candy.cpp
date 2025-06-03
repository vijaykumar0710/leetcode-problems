class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int>ans1(n,1),ans2(n,1);
        for(int i=0;i<n;i++){
            if(i-1>=0 && ratings[i]>ratings[i-1]){
                ans1[i]=ans1[i-1]+1;
            }
             if(n-1-i+1<n && ratings[n-1-i]>ratings[n-1-i+1]){
                ans2[n-1-i]=ans2[n-1-i+1]+1;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=max(ans1[i],ans2[i]);
        }
        return ans;
    }
};