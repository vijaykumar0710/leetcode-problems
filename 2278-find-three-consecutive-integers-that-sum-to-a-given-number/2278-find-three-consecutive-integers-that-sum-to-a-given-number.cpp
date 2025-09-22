class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long>res;
       if(num%3!=0) return res; 
       long long x=(long long)(num/3)-1;
       res.push_back(x);
       res.push_back(x+1);
       res.push_back(x+2);
       return res;
    }
};