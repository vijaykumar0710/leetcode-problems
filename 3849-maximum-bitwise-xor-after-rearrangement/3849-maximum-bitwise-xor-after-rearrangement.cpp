class Solution {
public:
    string maximumXor(string s, string t) {
       int n=s.size();
       int ones=0,zeros=0;
       for(auto x:t){
        if(x=='1') ones++;
        else zeros++;
       }
       string res="";
        for(auto x:s){
            if(x=='1'){
                if(zeros>0) res+='1',zeros--;
                else res+='0',ones--;
            }else{
                if(ones>0) res+='1',ones--;
                else res+='0',zeros--;
            }
        }
        return res;
    }
};