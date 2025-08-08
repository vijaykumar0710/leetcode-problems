class Solution {
public:
    int t[100001];
    int binary_search(int i,int end_time,vector<vector<int>>& offers){
          int l=i,r=offers.size()-1;
          int idx=offers.size();
            while(l<=r){
                int mid=l+(r-l)/2;
                if(offers[mid][0]>end_time){
                    idx=mid;
                    r=mid-1;
                }else l=mid+1;
            }
            return idx;
    }
    int f(int i,int n,vector<vector<int>>& offers){
        if(i>=n) return 0;
        if(t[i]!=-1) return t[i];
        int next_idx=binary_search(i+1,offers[i][1],offers);
        int take=offers[i][2]+f(next_idx,n,offers);
        int skip=f(i+1,n,offers);
        return t[i]=max(take,skip);
    }
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(),offers.end());
        int m=offers.size();
        memset(t,-1,sizeof(t));
        return f(0,m,offers);
    }
};