class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n=arr.size(),cnt=0;
        for(int i=0;i<n;i++){
            int xor_val=arr[i];
            for(int j=i+1;j<n;j++){
                xor_val^=arr[j];
               int xor_val2=arr[j];{
                for(int k=j;k<n;k++){
                     xor_val2^=arr[k];
                     if(xor_val==xor_val2) cnt++;
                 }
               }
            }
        }
        return cnt;
    }
};