class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string res="";
        for(int i=0;i<num;i++){
             for(int j=9;j>=0;j--){
                if(j<=sum){
                    res+=to_string(j);
                    sum-=j;
                    break;
                }
             }
        }
        return sum==0?res:"";
    }
};