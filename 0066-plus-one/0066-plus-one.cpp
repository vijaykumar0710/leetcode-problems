class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        vector<int>res;
        int hasil=1;
        for(int i=n-1;i>=0;i--){
           int num=digits[i]+hasil;
           res.push_back(num%10);
           hasil=num/10;
        }
        if(hasil!=0)res.push_back(hasil);
        reverse(res.begin(),res.end());
        return res;
    }
};