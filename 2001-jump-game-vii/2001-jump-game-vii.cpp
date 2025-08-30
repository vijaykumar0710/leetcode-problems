class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.size();
        if(s[n-1]=='1') return false;
        int farthest_reach=0;
        queue<int>q;
        q.push(0);
        while(!q.empty()){
            int u=q.front();q.pop();
            if(u>=n-1) return true;
            int mini=max(farthest_reach+1,u+minJump);
            int maxi=min(n-1,u+maxJump);
            for(int j=mini;j<=maxi;j++){
               if(s[j]=='0')q.push(j);
            }
            farthest_reach=maxi;
        }
        return false;
    }
};