class Solution {
public:
    int nextBeautifulNumber(int n) {
        for(int i=n+1;i<=1e7;i++){
            vector<int>freq(10,0);
            int N=i;
            while(N){
                freq[N%10]++;
                N/=10;
            }
            bool flag=true;
            for(int j=0;j<10;j++){
                if(j>0 && freq[j]==0) continue;
                if(freq[j]!=j){
                    flag=false;
                    break;
                }
            }
            if(flag) return i;
        }
        return -1;
    }
};