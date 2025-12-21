class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size(),len=0;
        int j=0;
        vector<string>temp(n,"");
        while(j<strs[0].size()){ 
          for(int i=0;i<n;i++) temp[i]+=strs[i][j];
          string str=temp[0];
          bool flag=true;
          for(int i=1;i<n;i++){
            if(str>temp[i]){
                flag=false;
                len++;
                break;
            }
            str=temp[i];
          }
          if(!flag){
            for(int i=0;i<n;i++){
               if(!temp.empty()) temp[i].pop_back();
             }
          }
          j++;
        }
        return len;
    }
};