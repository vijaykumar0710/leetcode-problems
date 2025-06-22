class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<int>even_pos_arr,odd_pos_arr;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0) even_pos_arr.push_back(i);
            else odd_pos_arr.push_back(i);
        }
        int even_cnt=even_pos_arr.size();
        int odd_cnt=odd_pos_arr.size();
        if(abs(even_cnt-odd_cnt)>1) return -1;
        // case 1 even_cnt>=odd_cnt
        long long cost1=-1;
        if(even_cnt>=odd_cnt){
           long long even_sum=0,odd_sum=0;
           for(int i=0;i<even_cnt;i++){
            even_sum+=abs(even_pos_arr[i]-2*i);
           }
           for(int i=0;i<odd_cnt;i++){
            odd_sum+=abs(odd_pos_arr[i]-(2*i+1));
           }
           cost1=(even_sum+odd_sum)/2;
        }

       // case 2 odd_cnt>=even_cnt
        long long cost2=-1;
        if(odd_cnt>=even_cnt){
           long long even_sum=0,odd_sum=0;
           for(int i=0;i<even_cnt;i++){
            even_sum+=abs(even_pos_arr[i]-(2*i+1));
           }
           for(int i=0;i<odd_cnt;i++){
            odd_sum+=abs(odd_pos_arr[i]-2*i);
           }
           cost2=(even_sum+odd_sum)/2;
        }
        //calculate result
        if(cost1!=-1 && cost2!=-1) return min(cost1,cost2);
        if(cost1!=-1 && cost2==-1) return cost1;
        if(cost1==-1 && cost2!=-1) return cost2;
        return -1;
    }
};