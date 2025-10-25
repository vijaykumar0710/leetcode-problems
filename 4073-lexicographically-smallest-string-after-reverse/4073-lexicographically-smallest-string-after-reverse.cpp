class Solution {
public:
    string lexSmallest(string s) {
        int n=s.size();
        string res="z";
        for(int k=0;k<=n;k++){
           string str=s;
           reverse(str.begin(),str.begin()+k);
           res=min(res,str);
        }
        string st=s;
        reverse(st.begin(),st.end());
        for(int k=0;k<=n;k++){
           string str=st;
           reverse(str.begin(),str.begin()+k);
           reverse(str.begin(),str.end());
           res=min(res,str);
        }
        return res;
    }
};