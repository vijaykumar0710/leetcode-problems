class Solution {
public:
    int digitFrequencyScore(int n) {
        vector<int>freq(10,0);
        while(n){
            freq[n%10]++;
            n/=10;
        }
        int sum=0;
        for(int i=1;i<10;i++) sum+=i*freq[i];
        return sum;
    }
};