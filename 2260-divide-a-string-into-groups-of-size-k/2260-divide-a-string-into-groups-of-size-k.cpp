class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n=s.size();
        int rem=n%k,complete=n/k;
        vector<string>res;
        for(int i=0;i<=(n-rem-k);i+=k){
            string p=s.substr(i,k);
            res.push_back(p);
        }
        int j=complete*k;
        int lund=k-(n-j);
        string p=s.substr(j);
        if(lund!=k){ 
        while(lund--) p+=fill;
        }
        if(p.size()!=0)res.push_back(p);
        return res;
    }
};