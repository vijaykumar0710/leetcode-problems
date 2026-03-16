class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
        int n=nums.size();
        int m=n-1;
        vector<int>diff(m);
        for(int i=0;i<m;i++) diff[i]=nums[i+1]-nums[i];
        vector<int>left(m,1),right(m,1);
        for(int i=1;i<m;i++) if(diff[i-1]==diff[i]) left[i]=left[i-1]+1;
        for(int i=m-2;i>=0;i--) if(diff[i+1]==diff[i]) right[i]=right[i+1]+1;
        int res=3;
        for(int i=0;i<m;i++){
            int len=left[i];
            if(len<m) res=max(res,len+2);
            else res=max(res,m+1);
        }
        for(int i=0;i<m-1;i++){
            int sum=diff[i]+diff[i+1];
           if(sum%2==0){
            int d=sum/2;
            int left_len=0,right_len=0;
            if(i>0 && diff[i-1]==d) left_len=left[i-1];
            if(i+2<m && diff[i+2]==d) right_len=right[i+2];
            res=max(res,left_len+right_len+3);
           }
        }
        return res;
    }
};