class Solution {
public:
    long long totalScore(int hp, vector<int>& damage, vector<int>& requirement) {
        int n=damage.size();
        vector<int>prefix(n),temp(n);
        prefix[0]=damage[0];
        temp[0]=hp-damage[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+damage[i];
            temp[i]=temp[i-1]-damage[i];
        }
        long long res=0;
        for(int i=0;i<n;i++){
            if(temp[i]<requirement[i]){
             int tar=requirement[i]-temp[i];
             int idx=lower_bound(prefix.begin(),prefix.begin()+i,tar)-prefix.begin();
             res=res+(i-idx);
            }else res=res+(i+1);
        }
        return res;
    }
};