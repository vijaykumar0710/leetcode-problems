class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int freq=1,res=-1;
        int i=1;
        for(;i<n;i++){
            if(arr[i]==arr[i-1]) freq++;
            else{
                if(freq==arr[i-1]){
                    res=arr[i-1];
                }
                freq=1;
            }
        }
        if(freq==arr[i-1])
        res=max(res,arr[i-1]);
        return res;
    }
};