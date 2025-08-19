class Solution {
public:
bool isPossible(string &s,int mid){
    int n=s.size();
    for(int i=0;i<=n-mid;i++){
        string str=s.substr(i,mid);
        bool flag=true;
        for(int j=1;j<str.size();j++){
            if((str[j]-str[j-1])!=1) flag=false;
        }
        if(flag) return true;
    }
    return false;
}
    int longestContinuousSubstring(string s) {
        int n=s.size();
        int l=0,r=26;
        int res=1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isPossible(s,mid)){
                res=mid;
                l=mid+1;
            }else r=mid-1;
        }
        return res;
    }
};