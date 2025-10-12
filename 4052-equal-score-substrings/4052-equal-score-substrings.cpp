class Solution {
public:
    bool scoreBalance(string s) {
        int n=s.size(),total=0;
        for(auto ch:s) total+=(ch-'a'+1);
        if(total%2!=0) return false;
        total=total/2;
        for(int i=0;i<s.size();i++){
            if(total==0) return true;
            if(total<0) return false;
            total-=(s[i]-'a'+1);
        }
        return total==0;
    }
};