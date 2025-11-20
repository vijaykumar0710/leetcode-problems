class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& inter) {
        int n=inter.size();
        sort(inter.begin(),inter.end(),[](auto &a,auto &b){
            if(a[1]==b[1]) return a[0]>b[0];
            return a[1]<b[1];
        });
        int l=-1;
        int r=-1;
        int len=0;
        for(int i=0;i<n;i++){
            int x=inter[i][0],y=inter[i][1];
            bool c1=(r>=x && r<=y);
            bool c2=(l>=x && l<=y);
            if(c1 && c2) continue;
            if(c2){
                len++;
                r=l;
                l=y;
            }
            else{
                len+=2;
                r=y-1;
                l=y;
            }
        }
        return len;
    }
};