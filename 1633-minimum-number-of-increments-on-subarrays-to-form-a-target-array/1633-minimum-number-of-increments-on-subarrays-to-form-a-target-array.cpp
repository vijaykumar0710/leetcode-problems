class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n=target.size();
        int op=target[0];
        int prev=target[0];
        for(int i=1;i<n;i++){
           if(prev<target[i]){
            op+=abs(target[i]-prev);
           }
           prev=target[i];
        }
        return op;
    }
};