class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n=arr.size();
        if(n==1) return 1;
        if(n==2){
            if(arr[0]==arr[1]) return 1;
            else return 2;
        };
        vector<int>t(n,0);
        t[0]=1,t[1]=2;
        if(arr[0]==arr[1]) t[1]=1;
         int res=max(t[0],t[1]); 
        for(int i=1;i<n-1;i++){
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1] || arr[i]<arr[i-1] && arr[i]<arr[i+1])t[i+1]=t[i]+1;
            else if(arr[i]==arr[i+1]) t[i+1]=1;
            else t[i+1]=2;
            res=max(res,t[i+1]);
        }
        return res;
    }
};