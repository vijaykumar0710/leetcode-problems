class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n=cost.size();
        vector<int>freq(101,0);
        for(auto x:cost) freq[x]++;
        int cnt=0,res=0;
        for(int c=100;c>=1;c--){
            while(freq[c]>=1){
                if(cnt==2){
                    cnt=0;
                }else{
                    cnt++;
                    res+=c;
                }
                freq[c]--;
            }
        }
        return res;
    }
};