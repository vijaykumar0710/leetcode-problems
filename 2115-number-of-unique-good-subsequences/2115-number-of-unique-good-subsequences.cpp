class Solution {
public:
const int M=1e9+7;
    int numberOfUniqueGoodSubsequences(string binary) {
        int end_0=0,end_1=0;
        for(auto &ch:binary){
            if(ch=='1') end_1=(end_1+end_0+1)%M;
            else end_0=(end_1+end_0)%M;
        }
        int ans=(end_0+end_1)%M;
        if(binary.find('0')!= string :: npos) return (ans+1)%M;
        return ans%M;
    }
};