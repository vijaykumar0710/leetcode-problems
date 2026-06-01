class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n=cost.size();
        vector<int>freq(101,0);
        for(auto c:cost) freq[c]++;
        int res=0,cnt=0;
        for(int i=100;i>=1;i--){
            while(freq[i]>0){
                if(cnt==2) cnt=0;
                else{
                    res+=i;
                    cnt++;
                }
                freq[i]--;
            }
        }
        return res;
    }
};