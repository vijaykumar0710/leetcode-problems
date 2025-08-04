class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        unordered_map<int,int>mp;
        int ans=0,sum=0;
        int i=0;
        for(int j=0;j<n;j++){
            mp[fruits[j]]++;
            sum++;
            while(mp.size()>2){
                if(mp.find(fruits[i])!=mp.end()){
                    sum--;
                    mp[fruits[i]]--;
                   if(mp[fruits[i]]==0) mp.erase(fruits[i]);
                }
                i++;
            }
            ans=max(sum,ans);
        }
        return ans;
    }
};