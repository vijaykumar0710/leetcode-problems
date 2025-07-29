class Solution {
public:
const static int N=1e6+1;
int spf[N];
void compute_spf(){
    for(int i=1;i<N;i++) spf[i]=i;
    for(int i=2;i*i<N;i++){
        if(spf[i]==i){
            for(int j=2;i*j<N;j++){
                if(spf[i*j]==i*j) spf[i*j]=i;
            }
        }
    }
}
vector<int>get_prime_factors(int num){
    vector<int>factors;
    while(num!=1){
        factors.push_back(spf[num]);
        num/=spf[num];
    }
    return factors;
}
    int findValidSplit(vector<int>& nums) {
        int n = nums.size();
        compute_spf();
        unordered_map<int, int> last_index;
        for (int i = 0; i < n; i++) {
            vector<int> prime_factors = get_prime_factors(nums[i]);
            for(auto &p:prime_factors)
            last_index[p]=i;
        }
        int max_reach=0;
        for(int i=0;i<n-1;i++){
            vector<int> prime_factors = get_prime_factors(nums[i]);
            for(auto &p:prime_factors){ 
                max_reach=max(max_reach,last_index[p]);
            }
            if(max_reach==i) return i;
        }
        return -1;
    }
};