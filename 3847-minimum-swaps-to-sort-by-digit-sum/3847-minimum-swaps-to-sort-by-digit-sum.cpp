class Solution {
public:
int digit_sum(int x){
    int val=0;
    while(x){
        val+=x%10;
        x/=10;
    }
    return val;
}
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>v;
        for(int i=0;i<n;i++){
            v.push_back({digit_sum(nums[i]),nums[i],i});
        }
        sort(v.begin(),v.end());
        vector<bool>visited(n,false);
        int min_swaps=0;
        for(int i=0;i<n;i++){
            if(visited[i] || v[i][2]==i) continue;
            int cycle_size=0;
            int j=i;
            while(!visited[j]){
                visited[j]=true;
                j=v[j][2];
                cycle_size++;
            }
            if(cycle_size>0) min_swaps+=(cycle_size-1);
        }
        return min_swaps;
    }
};