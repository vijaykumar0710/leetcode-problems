class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n=nums.size();
        vector<int>key_pos,res;
        for(int i=0;i<n;i++){
            if(nums[i]==key) key_pos.push_back(i);
        }
     for(int i=0;i<n;i++){
        for(int j=0;j<key_pos.size();j++){
            if(abs(i-key_pos[j])<=k){
                res.push_back(i);
                break;
            }
        }
     }
    // sort(res.begin(),res.end());
     return res;
    }
};