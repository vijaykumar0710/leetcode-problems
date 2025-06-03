class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n1=word1.size(),n2=word2.size();
        vector<int>max_suffix(n1,0);
        int i=n1-1,j=n2-1;
        while(i>=0 && j>=0){
            if(word1[i]==word2[j]){ 
              max_suffix[i]=n2-j; 
              i--;
              j--;
            }else{
                i--;
            }
        }  
        for(int i=n1-2;i>=0;i--){
            max_suffix[i]=max(max_suffix[i],max_suffix[i+1]);
        }
        vector<int>ans;
        i=0,j=0;
        bool flag=false;
        while(i<n1 && j<n2){
            if(word1[i]==word2[j]){
                ans.push_back(i);
                i++;
                j++;
            }else{
              if(i+1<n1 && flag==false && max_suffix[i+1]>=n2-j-1){
                ans.push_back(i);
                flag=true;
                i++;
                j++;
              }else{
                i++;
              }
            }
        }
        if(ans.size()==n2) return ans;
        return {};
    } 
}; 