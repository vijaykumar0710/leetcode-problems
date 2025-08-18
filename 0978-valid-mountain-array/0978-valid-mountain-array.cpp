class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
       int n=arr.size();
       if(n<3) return false;
       int max_ele=*max_element(arr.begin(),arr.end());
       int cnt=count(arr.begin(),arr.end(),max_ele);
       if(cnt>1) return false;
       int idx=-1;
       for(int i=0;i<n;i++){
        if(arr[i]==max_ele){
           idx=i;
           break;
        }
       }
       if(idx==n-1 || idx==0) return false;
       for(int i=1;i<idx;i++){
        if(arr[i-1]>=arr[i]) return false;
       }
       for(int i=idx+1;i<n-1;i++){
        if(arr[i+1]>=arr[i]) return false;
       }
       return true;
    }
};