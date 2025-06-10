class Solution {
public:
    int maxDifference(string s) {
        int n=s.size();
        sort(s.begin(),s.end());
        vector<int>group;
        int cnt=1;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                cnt++;
            }else{
                group.push_back(cnt);
                cnt=1;
            }
        }
        group.push_back(cnt);
        int largeOdd=0,smallEven=101;
        for(auto &x:group){
            if(x%2==0){
             smallEven=min(smallEven,x);
            }else{
               largeOdd=max(largeOdd,x);
            }
        }
        return largeOdd-smallEven;
    }
};