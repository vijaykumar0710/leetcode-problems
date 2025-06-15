class Solution {
public:
vector<int>formed_nums_arr(int num){
    vector<int>temp;
    int n=num;
    while(n){ temp.push_back(n%10); n/=10; }
    reverse(temp.begin(),temp.end());
    return temp;
}

int formed_largest_num(vector<int>&nums){
    int x=9;
    for(auto &ele:nums){
         if(ele!=9){ x=ele; break; }
    }
    int large_number=0;
    for(auto &ele:nums){
        if(ele==x) large_number=large_number*10+9;
        else large_number=large_number*10+ele;
    }
    return large_number;
}

int formed_smallest_num(vector<int>nums){
    int x=1;
    if(nums[0]!=1) x=nums[0];
    else{
        for(int i=1;i<nums.size();i++){
           if(nums[i]!=0 && nums[i]!=nums[0]){ x=nums[i]; break; }
        }
    }
    int smallest_num=0;
    if(x==nums[0]){
        for(auto &ele:nums){
            if(ele==x) smallest_num=smallest_num*10+1;
            else smallest_num=smallest_num*10+ele;
        }
    }else{
        for(auto &ele:nums){
            if(ele==x)smallest_num=smallest_num*10;
            else smallest_num=smallest_num*10+ele;
        }
    }
    return smallest_num;
}
    int maxDiff(int num) {
        vector<int>nums=formed_nums_arr(num);
        int largest_num=formed_largest_num(nums);
        int smallest_num=formed_smallest_num(nums);
        return largest_num-smallest_num;
    }
};