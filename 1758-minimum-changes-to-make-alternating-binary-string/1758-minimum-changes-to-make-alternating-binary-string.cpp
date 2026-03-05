class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        if(n==1) return 0;
        int res=n+1,cnt=0;
        int flip=1;
        for(auto x:s){
            if((x-'0')!=flip) cnt++;
            flip=1-flip;
        }
        res=min(res,cnt);
        cnt=0;
        flip=0;
        for(auto x:s){
          if((x-'0')!=flip) cnt++;
          flip=1-flip;
        }
        res=min(res,cnt);
        return res;
    }
};