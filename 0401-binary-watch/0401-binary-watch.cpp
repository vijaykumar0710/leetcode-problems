class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string>res;
        for(int i=0;i<=11;i++){
            for(int j=0;j<=59;j++){
                if(__builtin_popcount(i)+__builtin_popcount(j)==turnedOn){
                    string st=to_string(i)+":";
                    if(j<10) st+="0";
                    st+=to_string(j);
                    res.push_back(st);
                }
            }
        }
        return res;
    }
};