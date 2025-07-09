class Solution {
public:
    const static int N = 1e4 + 1;
    int spf[N];
    int distinctPrimeFactors(vector<int>& nums) {
        for (int i = 1; i < N; i++)
            spf[i] = i;
        for (int i = 2; i * i < N; i++) {
            if (spf[i] == i) {
                for (int j = 2; i * j < N; j++) {
                    if (spf[i * j] == i * j)
                        spf[i * j] = i;
                }
            }
        }
        unordered_set<int>st;
        for(auto &num:nums){ 
        while(num!=1){
            st.insert(spf[num]);
            num/=spf[num];
        }
        }
        return st.size();
    }
};