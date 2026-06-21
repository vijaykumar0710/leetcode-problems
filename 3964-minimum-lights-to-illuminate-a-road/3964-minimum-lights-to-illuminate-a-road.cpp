class Solution {
public:
    int minLights(vector<int>& lights) {
        int n=lights.size();
        vector<int>res(n,0);
        int x=0;
        for(int i=0;i<n;i++){
            if(x>0) res[i]=x,x--;
            if(lights[i]>0){
                x=max(x,lights[i]);
                res[i]=x;
            }
        }
        x=0;
         for(int i=n-1;i>=0;i--){
            if(x>0) res[i]=x,x--;
            if(lights[i]>0){
                x=max(x,lights[i]);
                res[i]=x;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int cnt=0;
            while(i<n && res[i]==0){
                cnt++;
                i++;
            }
            ans+=(cnt+2)/3;
        }
        return ans;
    }
};