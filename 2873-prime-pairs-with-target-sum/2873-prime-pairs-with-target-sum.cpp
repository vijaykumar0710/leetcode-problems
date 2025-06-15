class Solution {
public:
vector<int>formed_prime_arr(int n){
    vector<bool>isPrime(n+1,true);
    for(int i=2;i<=sqrt(n);i++){
        if(isPrime[i]){
            for(int j=2;i*j<=n;j++){
                isPrime[i*j]=false;
            }
        }
    }
        vector<int>final_prime_arr;
        for(int i=2;i<=n;i++){
           if(isPrime[i]) final_prime_arr.push_back(i);
        }
       return final_prime_arr;
}
vector<vector<int>>two_sum(vector<int>nums,int target){
    vector<vector<int>>temp;
    int n=nums.size();
    int i=0,j=n-1;
    while(i<=j){
        if(nums[i]+nums[j]>target) j--;
        else if(nums[i]+nums[j]<target) i++;
        else{
            temp.push_back({nums[i],nums[j]});
            i++,j--;
        }  
    }
    return temp;
}
    vector<vector<int>> findPrimePairs(int n) {
        vector<int>isPrime=formed_prime_arr(n);
        cout<<isPrime.size()<<endl;
        vector<vector<int>>res=two_sum(isPrime,n);
        return res;
    }
};