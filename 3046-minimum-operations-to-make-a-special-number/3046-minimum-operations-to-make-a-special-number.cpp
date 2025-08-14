class Solution {
public:
    int minimumOperations(string num) {
        int n=num.size();
        int res=INT_MAX;
        for(int i=n-1;i>=0;i--){
            if(num[i]=='0'){
                int j=i-1;
                while(j>=0){
                    if(num[j]=='0' || num[j]=='5')
                         break;
                    j--;
                }
                if(j>=0){
                    res=min(res,-j-1+n-1);
                }else{
                    res=min(res,n-1-i+i);
                }
            }
            if(num[i]=='5'){
                 int j=i-1;
                while(j>=0){
                    if(num[j]=='2' || num[j]=='7')
                         break;
                    j--;
                }
                if(j>=0){
                    res=min(res,-j-1+n-1);
                }else{
                    res=min(res,n);
                }
            }
        }
        return res==INT_MAX?n:res;
    }
};