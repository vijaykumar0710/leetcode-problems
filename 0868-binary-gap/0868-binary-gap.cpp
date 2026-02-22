class Solution {
public:
    int binaryGap(int n) {
        string s=bitset<32>(n).to_string();
        int i=0,j=s.size()-1;
        while(s[i]=='0') i++;
        while(s[j]=='0') j--;
        int res=0;
        if(j<=i) return res;
        int cnt=1;
        for(int k=i+1;k<=j;k++){
            if(s[k]=='1'){
                res=max(cnt,res);
                cnt=1;
            } else cnt++;
        }
        return res;
    }
};