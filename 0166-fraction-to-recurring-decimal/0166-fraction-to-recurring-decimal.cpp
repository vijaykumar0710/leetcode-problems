class Solution {
public:
    string fractionToDecimal(int n, int d) {
        if(n==0) return "0";
        string res;
        if((long long)n*(long long)d<0) res+="-";
        long long absN=labs(n);
        long long absD=labs(d);
        long long integerDiv=absN/absD;
        res+=to_string(integerDiv);
        long long rem=absN%absD;
        if(rem==0) return res;
        res+='.';
        unordered_map<int,int>mp;
        while(rem!=0){
            if(mp.count(rem)){
                res.insert(mp[rem],"(");
                res+=")";
                break;
            }
            mp[rem]=res.length();
            rem*=10;
            int digit=rem/absD;
            res+=to_string(digit);
            rem=rem%absD;
        }
        return res;
    }
};